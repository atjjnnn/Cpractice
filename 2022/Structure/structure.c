#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include "radio.h"

typedef enum
{
	LOWPOWER,
	RX,
	RX_TIMEOUT,
	RX_ERROR,
	TX,
	TX_TIMEOUT,
}States_t;

States_t State = LOWPOWER;

static RadioEvents_t RadioEvents;

void OnTxDone(void);

void OnRxDone(uint8_t *payload, uint16_t size, int16_t rssi, int8_t snr);

void OnTxTimeout(void);

void OnRxTimeout(void);

void *thread_task_1(RadioEvents_t *Events)
{
	sleep(1);
	Events->TxDone();
}

void *thread_task_2(RadioEvents_t *Events)
{
        sleep(10);
        Events->RxTimeout();
}

int main(void)
{
	pthread_t pid;	

	RadioEvents.TxDone = OnTxDone;
	RadioEvents.RxDone = OnRxDone;
	RadioEvents.TxTimeout = OnTxTimeout;
	RadioEvents.RxTimeout = OnRxTimeout;

	pthread_create(&pid, NULL, thread_task_1, &RadioEvents);
        pthread_create(&pid, NULL, thread_task_2, &RadioEvents);

	while(1)
	{

		switch(State)
		{
			case RX:
				printf("Case: RX:%d\n", RX);
				State =LOWPOWER;
				break;
			case TX:
				printf("Case: TX:%d\n", TX);
				State =LOWPOWER;
				break;
			case RX_TIMEOUT:
				printf("Case: RX_TIMEOUT:%d\n", RX_TIMEOUT);
				State =LOWPOWER;
				break;
			case TX_TIMEOUT:
				printf("Case: TX_TIMEOUT:%d\n", TX_TIMEOUT);
				State =LOWPOWER;
				break;
			default:
				break;
		}
	}

}

void OnTxDone(void)
{
	State = TX;
}

void OnTxTimeout(void)
{
	State = TX_TIMEOUT;
}

void OnRxDone(uint8_t *payload, uint16_t size, int16_t rssi, int8_t snr)
{
	State = RX;
}

void OnRxTimeout(void)
{
	State = RX_TIMEOUT;
}
