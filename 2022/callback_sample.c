/* This program is reffered by the site below. */
/* https://qiita.com/developer-kikikaikai/items/7c423b17a0afe0ac1f09 */

#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

//要求APIの引数で渡す関数（コールバック）の型定義
typedef void (*notify_event_cb)(const char *result);

//要求用API。引数のeventが要求処理後に呼ばれる
static void request_action(notify_event_cb event);

/* 要求を受ける側の処理 */
//メイン処理
static void * actor_main(void * arg)
{
	notify_event_cb event = (notify_event_cb) arg;
	sleep(1);
	//処理が終わった想定。関数をコール
	event("Result OK!");
	
	return NULL;
}

static void request_action(notify_event_cb event)
{
	pthread_t pid;

	pthread_create(&pid, NULL, actor_main, event);
	pthread_detach(pid);
}

/* 応答で呼ばれるコールバックの中身 */
static void notify_event(const char *result)
{
	printf("Receive result![%s]\n", result);
}

int main()
{
	//request_actionはすぐ終了して後でnotify_eventが呼ばれる。
	request_action(notify_event);	
	printf("API request_action is called! Let's wait result!\n"9;

	//sleep中に要求を受ける側が処理を終えてコールバックを呼ぶ。
	sleep(3);
	printf("Exit!\n");

	return 0;
}
