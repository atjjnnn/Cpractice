#include <stdio.h>
#define DAYS 365

int calc_passed_days(age)
{
  int days =0;
  days = age * DAYS;
  return days;
}

void get_age()
{
  printf("あなたの年齢を入力してください。\n");
  int age;
  scanf("%d",&age);

  int day = calc_passed_days(age);
  printf("今日はあなたが生まれてから%d日目です。\n", day);
}

int main()
{
  get_age();

  return 0;
}
