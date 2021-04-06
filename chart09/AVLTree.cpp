//AVL�� 
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;
struct node{
	int v, height;//vΪȨֵ��heightΪ�߶�
	node *lchild, *rchild;
};

node* newNode(int v){
	node* Node = (node*)malloc(sizeof(node));
	Node->v = v;
	Node->height = 1;
	Node->lchild = Node->rchild = NULL;//��ʼ״̬û�����Һ���
	return Node; 
}

//��ȡ��rootΪ���ڵ�������ĵ�ǰheight 
int getHeight(node* root){
	if(root == NULL){
		return 0;
	}
	return root->height;
}

//����ڵ�root��ƽ������
int getBalanceFactor(node* root){
	return getHeight(root->lchild) - getHeight(root->rchild);
} 

//����root��height
void updateHeight(node* root){
	root->height = max(getHeight(root->lchild), getHeight(root->rchild)) + 1;
}
 
//���� 
void L(node* &root){
	node* temp = root->rchild;
	root->rchild = temp->lchild;
	temp->lchild = root;
	updateHeight(root);
	updateHeight(temp);
	root = temp; 
} 

//���� 
void R(node* &root){
	node* temp = root->lchild;
	root->lchild = temp->rchild;
	temp->rchild = root;
	updateHeight(root);
	updateHeight(temp);
	root = temp; 
} 

void insert(node* &root, int v){
	if(root == NULL){ //����սڵ� 
		root = newNode(v);
		return;
	}
	if(v < root->v){ // v�ȸ��ڵ�ȨֵС
		insert(root->lchild, v); //������������
		updateHeight(root);
		if(getBalanceFactor(root) == 2 ){
			if(getBalanceFactor(root->lchild) == 1){ // LL��
				 R(root);
			}else if(getBalanceFactor(root->lchild) == -1){ //LR�� 
				L(root->lchild);
				R(root);
			}
		} 
	}else{
		insert(root->rchild, v);
		updateHeight(root);
		if(getBalanceFactor(root) == -2 ){
			if(getBalanceFactor(root->rchild) == -1){ // RR��
				 L(root);
			}else if(getBalanceFactor(root->rchild) == 1){ //RL�� 
				R(root->rchild);
				L(root);
			}
		} 
	} 
	 
}

//AVL���Ľ��� 
node* creatAVLTree(int data[], int n){
	node* root = NULL; //�½��ظ��ڵ�
	for(int i = 0; i < n; i++){
		insert(root, data[i]);
	} 
	return root; //���ظ��ڵ� 
	 
}
