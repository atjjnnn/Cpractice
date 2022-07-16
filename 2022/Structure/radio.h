#include <stdint.h>
#include <stdbool.h>

typedef struct
{
	//関数ポインタの型
	//TxDone is pointer to function(void) returning nothing(void)
	void (*TxDone)(void);

	void (*TxTimeout)(void);

	void (*RxDone)(uint8_t *payload, uint16_t size, int16_t rssi, int8_t snr);

	void (*RxTimeout)(void);

	void (*RxError)(void);
}RadioEvents_t;
