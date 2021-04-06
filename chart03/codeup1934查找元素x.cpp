#include<stdio.h>
const int maxn = 210;
int main(){
	int arr[maxn];
	int num, val;
	scanf("%d", &num);
	for(int i = 0; i < num; i++){
		scanf("%d", &arr[i]);
	}
	
	printf("%d", arr[0]);
	
	return 0;
}
