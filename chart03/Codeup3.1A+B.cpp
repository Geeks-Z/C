
/*
������������A��B�����ʾ��ʽ�ǣ��Ӹ�λ��ʼ��ÿ��λ���ö���","������
���������A+B�Ľ��������������ʽ�����
������������������ݣ�ÿ������ռһ�У�����������A��B��ɣ�-10^9 < A,B < 10^9����
�����A+B�Ľ��������������ʽ�����ÿ������ռһ�С�
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
