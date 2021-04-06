#include <stdio.h>
#include <vector>
#define maxn 100
using namespace std;
struct node{
	int data;
	vector<node> child;
}Node[maxn];
void preOrder(int root){
	printf("%d", Node[root].data);//访问当前节点 
	for(int i = 0; i < Node[root].child.size(); i++){
		//编译不通过，只提供思路 
		preOrder(Node[root].child[i]);//递归访问root的所有子结点 
	}
} 

int main(){
	return 0;
}
