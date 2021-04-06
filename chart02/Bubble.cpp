#include <stdio.h>

int main(){
	int arr[10] = {3, 1, 4, 5, 2};
	for(int i = 1; i < 5; i++){
		for(int j = 0; j < 5 - i; j++){
			if(arr[j] > arr[j+1]){
				int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
	
	for(int index = 0; index < 5; index++){
		printf("%d", arr[index]);
	}
	
	return 0;
}
