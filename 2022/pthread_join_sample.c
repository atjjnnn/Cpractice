#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

void* func(void* ptr)
{
	int i = 0;
	char* str = (char*)ptr;
	void* ret;

	for (i=1; i<=5; i++) {
		printf("%s=%d\n", str, i);
	}

	//auto変数はアドレスが危険なため、mallocでメモリ割り当て
	ret = malloc(sizeof(int));
	if (0 == strcmp(str, "A")) {
		*(int*)ret = 0;
	} else {
		*(int*)ret = 999;
	}

	//スレッドで呼び出される関数の中でreturnすると、
	//その値がpthread_joinの第二引数に格納されて戻る
	return ret;
}

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

	//受け取った側はfreeする必要がある
	free(ret1);
	free(ret2);

	return 0;
}
