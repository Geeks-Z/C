#include <stdio.h>

const int maxn = 100010;
int school[maxn] = {0};
int main(){
	
	int Num, schoolId, score;
	scanf("%d", &Num);
	while(Num--){
		scanf("%d%d", &schoolId, &score);
		school[schoolId] += score;
	}
	
	int index = 1, max = -1;
	for(int i = 1; i <= Num; i++){
		printf("\n");
		if(school[i] > max){
			max = school[i];
			index = i;
		}
		
	}
	
	printf("%d %d\n", index, max);
	return 0;
	
}
