//AVL树 
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;
struct node{
	int v, height;//v为权值，height为高度
	node *lchild, *rchild;
};

node* newNode(int v){
	node* Node = (node*)malloc(sizeof(node));
	Node->v = v;
	Node->height = 1;
	Node->lchild = Node->rchild = NULL;//初始状态没有左右孩子
	return Node; 
}

//获取以root为根节点的子树的当前height 
int getHeight(node* root){
	if(root == NULL){
		return 0;
	}
	return root->height;
}

//计算节点root的平衡因子
int getBalanceFactor(node* root){
	return getHeight(root->lchild) - getHeight(root->rchild);
} 

//更新root的height
void updateHeight(node* root){
	root->height = max(getHeight(root->lchild), getHeight(root->rchild)) + 1;
}
 
//左旋 
void L(node* &root){
	node* temp = root->rchild;
	root->rchild = temp->lchild;
	temp->lchild = root;
	updateHeight(root);
	updateHeight(temp);
	root = temp; 
} 

//右旋 
void R(node* &root){
	node* temp = root->lchild;
	root->lchild = temp->rchild;
	temp->rchild = root;
	updateHeight(root);
	updateHeight(temp);
	root = temp; 
} 

void insert(node* &root, int v){
	if(root == NULL){ //到达空节点 
		root = newNode(v);
		return;
	}
	if(v < root->v){ // v比根节点权值小
		insert(root->lchild, v); //往左子树插入
		updateHeight(root);
		if(getBalanceFactor(root) == 2 ){
			if(getBalanceFactor(root->lchild) == 1){ // LL型
				 R(root);
			}else if(getBalanceFactor(root->lchild) == -1){ //LR型 
				L(root->lchild);
				R(root);
			}
		} 
	}else{
		insert(root->rchild, v);
		updateHeight(root);
		if(getBalanceFactor(root) == -2 ){
			if(getBalanceFactor(root->rchild) == -1){ // RR型
				 L(root);
			}else if(getBalanceFactor(root->rchild) == 1){ //RL型 
				R(root->rchild);
				L(root);
			}
		} 
	} 
	 
}

//AVL树的建立 
node* creatAVLTree(int data[], int n){
	node* root = NULL; //新建控根节点
	for(int i = 0; i < n; i++){
		insert(root, data[i]);
	} 
	return root; //返回根节点 
	 
}
