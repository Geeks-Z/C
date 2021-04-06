/*
 * @Descripttion: 11种OJ练习
 * @version: 1.0
 * @Author: Geeks_Z
 * @Date: 2021-04-06 10:31:53
 * @LastEditors: Geeks_Z
 * @LastEditTime: 2021-04-06 13:09:09
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @Descripttion: 多个测试用例，每个测试用例一行。
 * 每行通过,隔开，有n个字符，n＜100
 * @param {*}
 * @return {*}
 */
void test10()
{
}

/**
 * @Descripttion: 多个测试用例，每个测试用例一行。每行通过空格隔开，有n个字符，n＜100;
 * 对于每组测试用例，输出一行排序过的字符串，每个字符串通过空格隔开
 * @param {*}
 * @return {*}
 */
void test09()
{
  char **s = (char **)malloc(sizeof(char *) * 100);
  int cnt = 0;
  int i = 0, j = 0;
  char *tmp;
  s[cnt] = (char *)malloc(sizeof(char) * 100);
  while (scanf("%s", s[cnt]) != EOF)
  {
    cnt++;
    if (getchar() == '\n')
    {
      for (i = 0; i < cnt; i++)
      {
        for (j = 0; j < cnt - 1 - i; j++)
        {
          if (strcmp(s[j], s[j + 1]) > 0)
          {
            tmp = s[j];
            s[j] = s[j + 1];
            s[j + 1] = tmp;
          }
        }
      }
      for (i = 0; i < cnt; i++)
      {
        printf("%s ", s[i]);
      }
      printf("\n");
      cnt = 0;
    }
    s[cnt] = (char *)malloc(sizeof(char) * 100);
  }
}

/**
 * @Descripttion: 输入有两行，第一行n 第二行是n个空格隔开的字符串
 * 输出一行排序后的字符串，空格隔开，无结尾空格
 * @param {*}
 * @return {*}
 */
void test08()
{
  char str[100][100];
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
  {
    scanf("%s", str[i]);
  }
  /**
   * base-- 指向要排序的数组的第一个元素的指针。
   * nitems-- 由 base 指向的数组中元素的个数。
   * size-- 数组中每个元素的大小，以字节为单位。
   * compar-- 用来比较两个元素的函数，即函数指针（回调函数）*/
  qsort(str, n, sizeof(str[0]), strcmp);
  for (int i = 0; i < n; i++)
  {
    printf("%s ", str[i]);
  }
}

/**
 * @Descripttion: 输入数据有多组, 每行表示一组输入数据。
 * 每行不定有n个整数，空格隔开。(1 <= n <= 100)。
 * @param {*}
 * @return {*}
 */
void test07()
{
  int ans, a;
  char c;
  while (scanf("%d", &ans) != EOF)
  {
    while (1)
    {
      c = getchar();
      if (c == ' ')
      {
        scanf("%d", &a);
        ans += a;
      }
      else if (c == '\n')
      {
        printf("%d\n", ans);
        break;
      }
    }
  }
}

/**
 * @Descripttion: 输入数据有多组, 每行表示一组输入数据。
 * 每行的第一个整数为整数的个数n(1 <= n <= 100)。
 * 接下来n个正整数, 即需要求和的每个正整数。
 * @param {*}
 * @return {*}
 */
void test06()
{
  int n, a;
  while (scanf("%d", &n) != EOF)
  {
    int ans = 0;
    while (n--)
    {
      scanf("%d", &a);
      ans += a;
    }
    printf("%d\n", ans);
  }
}

/**
 * @Descripttion: 输入的第一行包括一个正整数t(1 <= t <= 100), 表示数据组数。
 * 接下来t行, 每行一组数据。每行的第一个整数为整数的个数n(1 <= n <= 100)。
 * 接下来n个正整数, 即需要求和的每个正整数。
 * @param {*}
 * @return {*}
 */
void test05()
{
  int t, n, a;
  scanf("%d", &t);
  while (t--)
  {
    int ans = 0;
    scanf("%d", &n);
    while (n--)
    {
      scanf("%d", &a);
      ans += a;
    }
    printf("%d\n", ans);
  }
}

/**
 * @Descripttion: 输入数据包括多组。
 * 每组数据一行,每行的第一个整数为整数的个数n(1 <= n <= 100), n为0的时候结束输入。
 * 接下来n个正整数,即需要求和的每个正整数。
 * @param {*}
 * @return {*}
 */
void test04()
{
  int n, a, b;
  while (scanf("%d", &n) && n)
  {
    int ans = 0;
    while (n--)
    {
      scanf("%d", &a);
      ans += a;
    }
    printf("%d\n", ans);
  }
}

/**
 * @Descripttion: 输入包括两个正整数a,b(1 <= a, b <= 10^9),输入数据有多组, 如果输入为0 0则结束输入
 * @param {*}
 * @return {*}
 */
void test03()
{
  int a, b;
  while (scanf("%d%d", &a, &b) && (a || b))
  {
    printf("%d\n", a + b);
  }
}

/**
 * @Descripttion: 输入第一行包括一个数据组数t(1 <= t <= 100)
 * 接下来每行包括两个正整数a,b(1 <= a, b <= 10^9)
 * 输出a+b的结果
 * @param {*}
 * @return {*}
 */
void test02()
{
  int n, a, b;
  scanf("%d", &n);
  while (n--)
  {
    scanf("%d%d", &a, &b);
    printf("%d\n", a + b);
  }
}

/**
 * @Descripttion: 输入包括两个正整数a,b(1 <= a, b <= 10^9),输入数据包括多组。
 * 输出a+b的结果
 * @param {*}
 * @return {*}
 */
int test01()
{
  int a, b;
  while (scanf("%d%d", &a, &b) != EOF)
  {
    printf("%d\n", a + b);
  }
  return 0;
}

int main()
{
  return 0;
}
