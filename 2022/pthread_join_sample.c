#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

int main()
{
	void *ret1, *ret2;
	pthread_t thread1, thread2;

	pthread_create(&thread1, NULL, func, (void*)"A");
	pthread_create(&thread2, NULL, func, (void*)"B");

	pthread_join(thread1, &ret1);
	pthread_join(thread2, &ret2);

	printf("thread1:%d\n", *(int*)ret1);
	printf("thread2:%d\n", *(int*)ret2);

	free(ret1);
	free(ret2);

	return 0;
}
