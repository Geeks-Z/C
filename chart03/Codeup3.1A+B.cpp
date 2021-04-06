
/*
给定两个整数A和B，其表示形式是：从个位开始，每三位数用逗号","隔开。
现在请计算A+B的结果，并以正常形式输出。
输入包含多组数据数据，每组数据占一行，由两个整数A和B组成（-10^9 < A,B < 10^9）。
请计算A+B的结果，并以正常形式输出，每组数据占一行。
*/
#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
int main(){
	char a[15],b[15];
	
	while(scanf("%s %s",a,b)!=EOF)
	{
		int flaga=1,flagb=1;
		if(a[0]=='-')
			flaga=-1;
		if(b[0]=='-')
			flagb=-1;
		int suma=0,sumb=0;
		for(int i=0;i<strlen(a);i++)
		{
			if(a[i]>='0'&&a[i]<='9')
			{
				suma=suma*10+(a[i]-'0');
			}
		}
		suma = flaga*suma;
		
		for(int j=0;j<strlen(b);j++)
		{
			if(b[j]>='0'&&b[j]<='9')
			{
				sumb=sumb*10+(b[j]-'0');
			}
		}
		sumb = flagb*sumb;
		
		cout<<suma+sumb<<endl;
	}
	
	return 0;
}
