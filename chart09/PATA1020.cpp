//PATA1020
#include <stdio.h>
#include <stdlib.h>
#include <queue>
#define  maxn 50
using namespace std;

struct node{
	node* lchild;
	node* rchild;
	int data;
	int layer;
	
};

int pre[maxn], in[maxn], post[maxn];

node* create( int postL, int postR, int inL, int inR){
	if(postL > postR){//后序序列长度小于等于0
		return NULL; 
	}
	
	node* root = (node*)malloc(sizeof(node));//新建一个节点，用来存放当前二叉树的根节点 
	root->data = post[postR];
	
	int k;
	for(k = inL; k < inR; k++){
		if(in[k] == post[postR])//在中序序列中找到in[k] == post[posR]的节点 
			break;
	} 
	
	int numLeft = k - inL;//左子树个数
	
	// 左子树后序序列为【perL+1,preL+numLeft-1】 中序序列为【inL，k-1】
	//返回左子树的根节点地址，赋值给root的左指针 
	root->lchild = create(postL,postL + numLeft - 1,inL,k-1);
	
	//右子树后序序列为【postL+numLeft,postR-1】，中序序列为【k+1，inR】
	//返回右子树的根节点地址，赋值给root的右指针 
	root->rchild = create(postL + numLeft, postR - 1, k + 1, inR);
	
	return root; 
}

//层序遍历 
void LayerOrder(node* root){
	queue<node*> q;
	root->layer = 1;
	q.push(root);
	while(!q.empty()){
		node* now = q.front();
		q.pop();
		printf("%d",now->data);
		if(now->lchild != NULL){
			now->lchild->layer = now->layer + 1;
			q.push(now->lchild); // 左子树非空
			
		}  
		if(now->rchild != NULL){
			now->rchild->layer = now->layer + 1;
			q.push(now->rchild); // 右子树非空
		} 
	} 
}

int main(){
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d", &post[i]);
	}
	
	for(int i = 0; i < n; i++){
		scanf("%d", &in[i]);
	}
	
	node* root = create(0, n-1, 0, n-1);
	
	LayerOrder(root);
	return 0;
	
}


