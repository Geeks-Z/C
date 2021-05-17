# 1.C基础

## 数据和C

### 1.整型

初始化

```c
int val1, val2, vals;
int val1 = 1, val2 = 2;
int val1, val2 = 1; //未初始化val1
```

进制

八进制：0     显示：%o

十六进制：0x 0X    显示 %x

### 2.浮点型

浮点数比较：C/C++完全相同才判定为true，为此引入极小数（10^-8）来修正误差

```c
const double eps = 1e-8;
#define Equ(a, b) ((fabs((a) - (b))) < (eps)); 
```

# 2.运算符、表达式、语句、函数

## 2.1运算符

## 2.2类型转化

## 2.3函数

### 1.格式

返回类型	函数名称（参数类型	参数）{

​		函数体

}

### 2.变量

全局变量：定义在所有函数之前；

局部变量：定义在方法内部；值传递（参数的副本）

### 3.数组作为函数参数

第一维不需要写长度，第二维需要写长度；

函数中对数组元素的修改等同于**对原数组元素的修改**；

数组不允许作为返回类型出现；

# 3.循环、分支、跳转

## 3.1选择

### 3.1.1 if -else 

- 如果if表达式的判断是!=0，则可以省略
- 如果if表达式的判断是==0，则表达式前边添加非运算符“!”

### 3.1.2 switch语句

```c
switch(表达式){
	case 常量表达式1：
        ...
        break;
    case 常量表达式2：
        ...
        break;
    case 常量表达式3：
        ...
        break;
    default:
        ...
}
```

没有break将从第一个匹配的case开始执行语句，直到下面的语句都执行完成才退出switch。

## 3.2 循环

```c
for(表达式A; 表达式B; 表达式C){
}
```

C语言中不允许在表达式A中定义变量，如 int i = 1;C++可以

# 4.字符输入/输出和输入验证

## 3种输入方式

while...EOF型

**题目没有给定输入的结束条件**

```c
while(scanf("%d", &n) != EOF){ //scanf读取失败时，返回-1(EOF)
    
}

//读入字符串
while(scanf("%s", str) != EOF){ //scanf读取失败时，返回-1(EOF)
    
}

while(gets(str) != EOF){ //scanf读取失败时，返回-1(EOF)
    
}
```

while...break型

**题目要求当输入数据满足某个条件时停止输入**

```c
//例 当读入两个值都为0时
while(scanf("%d%d", &a, &b) != EOF){
    if(a == 0 && b == 0) break;
}
//简写
while(scanf("%d%d", &a, &b)， a || b){ //a || b 是 a != 0 || b != 0 的简写
    
}
```

while型(T--)

**题目给出测试数据的组数，然后是相应的测试数据**

```c
int T, a, b;
scanf("%d", &T);
while(T--){
    
}
```

## 3种输出类型

**每组输出之后增加一个空行**

```c
while(scanf("%d%d", &a, &b)， a || b){ //a || b 是 a != 0 || b != 0 的简写
    printf("%d\n", a + b);
    printf("\n");
}
```

**两组输出数据之间有一个空行  最后一组数据后面没有空行**

```c
while(T--){
    ...
 	if(T > 0)
        printf("\n");
}
```



# 5. 函数

## 5.1函数基础

任何程序在使用函数之前都需要声明该函数的类型

```c
void starbar (void);   // 声明函数原型
int main (void){
    starbar();
}

```



# 6. 指针

## 6.1 指针简介

## 6.2指针变量

### 定义

```c
int* p;
double* p;
int* p1, p2; //p1是int* 类型， p2是int型
int *p1, *p2, *p3;
```



## 6.3 指针变量作为函数参数

把变量的地址传入函数，如果在函数中对这个地址中的元素进行了修改，原先的数据也会被更改。

```c
void change (int* num1, int* num2){
	int temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}

int main(){
	int a = 1, b = 2;
	int* p1 = &a;
	int* p2 = &b;
	change(p1, p2);
	printf("%d %d\n", a, b);
	
	return 0;	
}

//错误写法1
void change (int* num1, int* num2){
	int* temp; //temp没有初始化，存放的地址是随机的，如果该地址是系统工作空间，就会出错？
    //改正 int x;
    //int* temp = &x;
    *temp = *num1;
	*num1 = *num2;
	*num2 = *temp;
}

//错误写法2
void change (int* num1, int* num2){
    //直接交换地址 main函数传递给change函数的“地址”是值传递
	int* temp = num1;
	num1 = num2;
	num2 = temp;
}

//改正--使用了引用
void change (int* &num1, int* &num2){
	int* temp = num1;
	num1 = num2;
	num2 = temp;
}
```

## C++中的引用

- 替代指针，达到对传入参数的修改影响外部变量的目的；
- 常量不可使用引用
- 添加&（与取地址不同）

```c
#include <stdio.h>
void change(int &x){  //函数的参数类型后面加个&
    x = 1;
}

int main(){
    int x = 10;
    change(x);
    printf("%d", x); // 1
    return 0;
}
```





# 7.数组和指针

## 7.1 一维数组

### 1.定义

数据类型  数组名  [数组大小]； //数组大小必须是整数常量，不可以是变量

### 2.初始化

使用数组前必须先初始化。

推荐使用**#define size 100** 的方式，如果数组为只读，可使用**const int days[size]**

```c
int a[10] = {5, 3, 2, 6, 8, 4};
```

**注意**：如果数组较大（大于10^6）则需要将其定义在主函数外面，因为函数内部申请的局部变量来自系统栈，而函数外部申请的全局变量来自静态存储区。

## 7.2多维数组

```c
int a[5][6] = {{3, 1, 2}, {8, 4}, {}, {1,2,3,4,5}};//如果没有{}编译不通过
```

**给数组元素赋相同值**

### 1.memset （添加<string.h>）

```c
memset(数组名，值，sizeof（数组名));
```

**赋值0或者-1；**？？？

### 2.fill函数

赋值其他数值。

## 7.3指针和数组

## 7.4函数、数组和指针

## 7.5指针操作

## 7.6保护数组中的数据

## 7.7指针和多维数组



# 8.字符串和字符串函数

## 8.1字符数组/字符串定义

字符数组可通过直接赋值字符串来初始化（仅限于初始化，其它位置不可）

一维字符数组的末尾都有一个空字符**'\0'**

## 8.2字符串输入

### 1.scanf

%c格式能识别空格跟换行符并将其输入

%s通过空格或换行符来识别一个字符串的结束

详见脑图

2.getchar()

## 8.3字符串输出

## 8.4 字符串函数

### 1.sscanf()

```c
sscanf(str, "%d", &n);//把字符数组str中的内容以“%d”的格式写到n中(从左至右)
#include <stdio.h>
int main(){
    int n;
    char str [50] = "123";
    sscanf(str, "%d", &n);
    printf("%d", n); // 123
}

#include <stdio.h>

int main(){
	
	int n;
	double db;
	char str[100] = "2048:3.14,hello", str2[100];
	sscanf(str, "%d:%lf,%s", &n, &db, str2);
	printf("n = %d, db = %.2f, str = %s\n", n, db, str2);//n = 2048, db = 3.14, str = hello
	return 0;
}
```



### 2.ssprintf()

```c
sprintf(str, "%d", n);//把n以"%d"形式写到字符数组str中(从右至左)
#include <stdio.h>
int main(){
    int n = 233;
    char str [50] ;
    sprintf(str, "%d", n);
    printf("%s", str); // 233
}

#include <stdio.h>

int main(){
	int n = 12;
	double db = 3.1415;
	char str [100];
	char str2 [100] = "good";
	sprintf(str, "%d:%.2f,%s", n, db, str2);
	printf("str = %s\n", str); //str = 12:3.14,good
	return 0;
	
}
```



# 9. 存储类别、链接和内存管理

## 9.1 存储类别

## 9.2 随机数函数和静态变量

## 9.3 分配内存

### malloc 、free函数

```c
typename* p = (typename*)malloc(sizeof(typename));

free(p)
```

```c
#include <stdio.h>
#include <stdlib.h> // 为 malloc() 和 free()函数提供原型
int main(void)
{
  double *ptd;
  int max;
  int number;
  int i = 0;

  puts("What is the maximum number of type double entries?");
  scanf("%d", &max);
  ptd = (double *)malloc(max * sizeof(double));
  if (ptd == NULL)
  {
    puts("Memory allocation failed, Goodbye");
    exit(EXIT_FAILURE);
  }

  // ptd 现在指向有 max 个元素的数组
  puts("Enter the values (q to quit) :");
  while (i < max && scanf("%lf", &ptd[i]) == 1)
    ++i;
  printf("Here are your %d entries: \n", number = i);
  for (i = 0; i < number; i++)
  {
    printf("%7.2f", ptd[i]);
    if (i % 7 == 6)
      putchar('\n');
  }
  if (i % 7 != 0)
    putchar('\n');
  puts("Done");
  free(ptd);

  return 0;
}

```



# 10.文件输入输出

# 十一.结构和其他数据结构

## 11.1结构体定义

```c
struct book {       /* 结构模板: 标记为 book */
    char title[MAXTITL];
    char author[MAXAUTL];
    float value;
    };               /* 结构模板结束 */

//方式1
struct Name{
	//一些基本的数据结构或者自定义的数据类型
}
struct studentInfo{
    int id;
    char gender;
    char name[20];
    char major[20];
}Alice, Bob, stu[1000]; //stu为结构体数组

struct node{
    node;//错误  不能定义自身
    node* next; //可以定义node*指针变量
}

//声明
studentInfo Alice;
studentInfo str[1000];
/*可以把这个声明放在任何函数的外面, 也可以放在一个函数定义内部. 如果这个结构声明置于一个函数内部, 它的标记只能在该函数内部使用. 如果是外部声明, 它可以被在本文件中该声明之后的所有函数使用.*/

```

## 11.2 结构体初始化

构造函数

初始化结构体**c写法**

```c
struct studentInfo{
    int id;
    char gender;
    };
struct studentInfo stu = {1,lee};
```

内部包含默认的构造函数(不可见)**c++写法**

```c++
struct studentInfo{
    int id;
    char gender;
	studentInfo(int _id, char _gender){
        id = _id;
        gender = _gender;
    };
    //简写
    studentInfo(int _id, char _gender) : id(_id), gender(_gender){}
}Alice, Bob, stu[1000]; //stu为结构体数组
studentInfo stu = studentInfo(10086, 'M');
```

如果自己重新定义了构造函数，则不能不经过初始化就定义结构体变量(默认的构造函数studentInfo(){}被覆盖)

## 11.3结构体访问

```c
struct studentInfo{
	int id;
	char name[20];
	studentInfo* next;
}stu, *p;
//访问 .运算符
stu.id;
stu.name;
(*p).id;
// -> 运算符
p->id;
p->name;
```

## 11.4结构数组

# 12.位操作

# 13.C预处理器和C库

## 13.1 明示常量#define

```c
#define TWO 2 //预处理器   宏  替换体
```

预处理器不进行计算, 它只是按照指令进行文字替换操作.实际运算过程发生在编译阶段

在C中，非自动数组的大小应该是整型常量表达式，数组大小必须是整形常量的组合、枚举常量和sizeof表达式。**不包括const声明的值（C++可以）**

## 13.2 在#define中使用参数

在#define中使用参数可以创建外形和作用与函数类似的类函数宏

```c
#define MEAN(X,Y) (((X)+(Y))/2)  //宏(宏参数) 替换体
/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: Geeks_Z
 * @Date: 2021-03-11 11:07:38
 * @LastEditors: Geeks_Z
 * @LastEditTime: 2021-03-11 11:10:23
 */
#include <stdio.h>
#define SQUARE(X) X *X /* 类函数与类名之间不能用空格 */
#define PR(X) printf("The result is %d \n", X)
int main(void)
{
  int x = 4;
  int z;

  printf("X = %d \n", x);
  z = SQUARE(x);
  printf("Evaluating SQUARE(x) : ");
  PR(z);
  z = SQUARE(2);
  printf("Evaluating SQUARE (2): ");
  PR(z);
  printf("Evaluating SQUARE (x+2) : "); 
  //x * x  变成  x+2 * x+2
  PR(SQUARE(x + 2));//Evaluating SQUARE (x+2) : The result is 14 
  printf("Evaluating 100 / SQUARE(2) :");
  //100 / SQUARE(2)  它将变成: 100 / 2*2
  PR(100 / SQUARE(2)); //Evaluating 100 / SQUARE(2) :The result is 100
  //上述问题通过该修改  #define SQUARE (x) (x*x)可以实现正确功能
  printf("x is %d \n", x);  
  printf("Evaluating SQUARE (++x) :");
  //  ++x * ++x = 5 * 6 = 30  避免++x作为宏参数
  PR(SQUARE(++x));
  printf("After incrementing, x is %x \n", x);
  return 0;
}

```



# 14.C++库

## sort函数

sort(首元素地址，尾元素地址的下一个地址，比较函数（可选）)

```c
#include <algorithm>
using namespace std;

int main()
{
    int arr[6] = {1, 2, 3, 4, 5, 6};
    sort(arr, arr + 4); //对arr[0]~arr[3]排序
    return 0;
}
```

### cmp函数

#### 1 基本数据类型

```c
//降序的cmp函数
bool cmp(int a, int b){
    return a > b;
}
```

记忆：如果要把数据从小到大，就用“<";  从大到小，就用”>“

#### 2 结构体类型

```c
struct node {
    int x, y;
    char name[10];
}nodes[10];
bool cmp (node a, node b){
    //return a.x > b.x;
    return strcmp(a.name, b.name) < 0;//按姓名字典序从小到大
}
```

#### 3 STL容器

# 13.其他

## 1.cin与cout

说明：C++中的输入输出函数(添加#include <iostream> 和 using namespace std;)

- 输入cin

```c++
#include <iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    return 0;
}
cin >> n >> db >> c >> str;//读入多个
//读入1行
char str[100];
cin.getline(str, 100);
//str容器
string str;
getline(str, 100);
```

- 输出cout

```c++
cout << n << " " << db << " " << endl;//endl为换行，也可使用"\n"换行
```

## 2.位、字节、字

字：设计计算机时给定的自然存储单位。目前计算的的32、64位为一个字长、字长决定了CPU一次操作处理的实际位数。