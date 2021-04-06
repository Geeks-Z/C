/*
 * @Descripttion: 测试string.h文件
 * @version: 1.0
 * @Author: Geeks_Z
 * @Date: 2021-04-03 10:04:12
 * @LastEditors: Geeks_Z
 * @LastEditTime: 2021-04-03 12:20:00
 */

#include <stdio.h>
#include <string.h>
using namespace std;
struct node
{
  int data;
  int v;
};
int main()
{
  char str1[20] = "aaa";
  char str2[20] = "bbb";
  strcpy(str1, str2);
  printf("%s\n", str1);
  int n;
  double db;
  char str3[100];
  char str[100] = "2048:3.14,hello";
  sscanf(str, "%d:%lf,%s", &n, &db, str3);
  printf("n=%d, db = %.2f, str3 = %s\n", n, db, str3);
  node node1 = {1, 2};
  printf("%d", node1.data);
  return 0;
}