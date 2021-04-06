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
