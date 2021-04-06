#include <stdio.h>
int main(){
    int num, a;
    int res = 0;
    while(scanf("%d", &num) != EOF && num != 0){
    	while(num--){
	        scanf("%d", &a);
	        res += a;
    	}
    	printf("%d\n", res);
    	res = 0;
	}
	return 0;
    
}
