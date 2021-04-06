#include<stdio.h>
//#define pi 3.14
typedef struct node{
	int data;
	node* next;
}Node, *pNode;

int main(){
	const double pi = 3.14;
	Node node1;
	node1.data = 1;
	pNode pp = &node1;
//	int i = 1;
//	int* p = &i;
	printf("%d\n",node1.data);
	printf("%d\n",pp);
	printf("%d\n",-5 % (3));
	printf("%d\n", 2 << 2);
	printf("%f",pi * 2);
	return 0;
} 
