#include <stdio.h>
#include <pthread.h>


int main(void)
{
	int data = 100;

	pthread_t pid;
	pthread_create(&pid, NULL, thread_task, &data);
	pthread_join(pid, NULL)

	printf("data : %d\n", data);
	printf("main thread done\n");
}
