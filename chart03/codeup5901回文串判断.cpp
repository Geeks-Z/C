//codeup5901���Ĵ��ж� 
#include <stdio.h>
#include <string.h>
#define maxn 256

bool judge(char str []){
	int len = strlen(str);
	for(int i = 0; i < (len / 2); i++){
		if(str[i] != str[len - 1 - i]) return false;
		return true;
	}
}
int main(){
	char str[maxn];
	while(gets(str)){
		bool flag = judge(str);
		printf("%d", flag);
	}
}

 
 
