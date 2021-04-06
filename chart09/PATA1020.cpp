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
	if(postL > postR){//�������г���С�ڵ���0
		return NULL; 
	}
	
	node* root = (node*)malloc(sizeof(node));//�½�һ���ڵ㣬������ŵ�ǰ�������ĸ��ڵ� 
	root->data = post[postR];
	
	int k;
	for(k = inL; k < inR; k++){
		if(in[k] == post[postR])//�������������ҵ�in[k] == post[posR]�Ľڵ� 
			break;
	} 
	
	int numLeft = k - inL;//����������
	
	// ��������������Ϊ��perL+1,preL+numLeft-1�� ��������Ϊ��inL��k-1��
	//�����������ĸ��ڵ��ַ����ֵ��root����ָ�� 
	root->lchild = create(postL,postL + numLeft - 1,inL,k-1);
	
	//��������������Ϊ��postL+numLeft,postR-1������������Ϊ��k+1��inR��
	//�����������ĸ��ڵ��ַ����ֵ��root����ָ�� 
	root->rchild = create(postL + numLeft, postR - 1, k + 1, inR);
	
	return root; 
}

//������� 
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
			q.push(now->lchild); // �������ǿ�
			
		}  
		if(now->rchild != NULL){
			now->rchild->layer = now->layer + 1;
			q.push(now->rchild); // �������ǿ�
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


