#include <stdio.h>
#include <pthread.h>

void * thread_task(void *data)
{
	int *pData = (int*)data;

	printf("thread data: %d\n", *pData);

	*pData = 200;
}

int main(void)
{
	int data = 100;

	pthread_t pid;
	pthread_create(&pid, NULL, thread_task, &data);
	pthread_join(pid, NULL);

	printf("data : %d\n", data);
	printf("main thread done\n");
}
