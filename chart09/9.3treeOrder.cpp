#include <stdio.h>
#include <vector>
#define maxn 100
using namespace std;
struct node{
	int data;
	vector<node> child;
}Node[maxn];
void preOrder(int root){
	printf("%d", Node[root].data);//���ʵ�ǰ�ڵ� 
	for(int i = 0; i < Node[root].child.size(); i++){
		//���벻ͨ����ֻ�ṩ˼· 
		preOrder(Node[root].child[i]);//�ݹ����root�������ӽ�� 
	}
} 

int main(){
	return 0;
}
