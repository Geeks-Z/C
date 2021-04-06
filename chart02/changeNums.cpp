#include <stdio.h>

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
