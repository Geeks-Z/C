#include <string.h>
#include <stdio.h>

int main(){
	char str1[50], str2[50];
	gets(str1);
	gets(str2);
	strcpy(str1, str2);
	printf("%d", strlen(str1));
	printf("%s", str1);
	return 0;
}
