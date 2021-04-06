/*
 * @Descripttion: 常见的输入输出
 * @version: 1.0
 * @Author: Geeks_Z
 * @Date: 2021-04-03 14:16:20
 * @LastEditors: Geeks_Z
 * @LastEditTime: 2021-04-03 14:45:41
 */
#include <stdio.h>

/**
 * @Descripttion: 没有结束条件的输入
 * @param {*}
 * @return {*}
 */
void noEndCase()
{
  int a, b;
  freopen("input.txt", "r", stdin);
  while ((scanf("%d %d", &a, &b) != EOF))
  {
    printf("%d\n", a + b);
  }
}

/**
 * @Descripttion: 有结束条件的输入
 * @param {*}
 * @return {*}
 */
void yesEndCase()
{
  int a, b;
  freopen("input.txt", "r", stdin);
  while (scanf("%d%d", &a, &b) && (a || b))
  {
    printf("%d\n", a + b);
  }
}

/**
 * @Descripttion: 有测试组数的输入
 * @param {*}
 * @return {*}
 */
void haveGroupNum()
{
  int n, a, b;
  scanf("%d", &n);
  while (n--)
  {
    scanf("%d%d", &a, &b);
    printf("%d\n", a + b);
  }
}

int main()
{
  yesEndCase();
  return 0;
}