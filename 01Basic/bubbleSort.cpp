/*
 * @Descripttion: 冒泡排序
 * @version: 1.0
 * @Author: Geeks_Z
 * @Date: 2021-04-02 23:09:55
 * @LastEditors: Geeks_Z
 * @LastEditTime: 2021-04-02 23:14:10
 */
#include <stdio.h>
int main()
{
  int arr[5] = {0, 2, 3, 4, 5};
  for (int i = 0; i < 5; i++)
  {
    for (int j = 0; j < 5 - i; j++)
    {
      if (arr[j] < arr[j + 1])
      {
        int temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }
  for (int i = 0; i < 5; i++)
  {
    printf("%d", arr[i]);
  }

  return 0;
}