//PATB1022 D���Ƶ�A+B
//P����תΪʮ����
#include <stdio.h>

int P2Decimal(int val, int P){
	int res = 0;
	int base = 1;
	while(val != 0){
		res = res + (val % 10) * base;
		val = val / 10;
		base = base * P;
	}
	return res; 
} 


//ʮ����תΪP����
void decimal2P(int val, int P){
	int res = 0;
	do{
		res = val % P;
		queue.push(res);
		res = res / P;	
	}while(val != 0);
	
	
} 

int main(){
	int res =  0;
//	res = P2Decimal(2153, 8);
	res = decimal2P(1131, 8);
	printf("%d", res);
	return 0;
	
}
