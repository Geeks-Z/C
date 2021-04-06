//PATA1043
#include <stdio.h>
#include <stdlib.h>
#include <vector>
using namespace std;

struct node{
	int data; //数据域 
	node* left; // 指针域 
	node* right;
};

//插入节点 
void insert(node* &root, int data){
	if(root == NULL){
		root = (node*)malloc(sizeof(node));
		root->data = data;
		root->left = root->right = NULL;
	}
	if(data < root->data) insert(root->left, data); // 插在左子树 
	else insert(root->right, data); // 插在右子树 
} 

//先序遍历 结果存在vi 
void preOrder(node* root, vector<int>&vi){
	if(root == NULL) return;
	vi.push_back(root->data);
	preOrder(root->left, vi);
	preOrder(root->right, vi);
} 

//镜像树先序遍历 结果存在vi 
void preOrderMirror(node* root, vector<int>&vi){
	if(root == NULL) return;
	vi.push_back(root->data);
	preOrder(root->right, vi);
	preOrder(root->left, vi);
	
}

//后序遍历 结果存在vi 
void postOrder(node* root, vector<int>&vi){
	if(root == NULL) return;
	postOrder(root->left, vi);
	postOrder(root->right, vi);
	vi.push_back(root->data);
} 

//镜像树后序遍历 结果存在vi 
void postOrderMirror(node* root, vector<int>&vi){
	if(root == NULL) return;
	postOrderMirror(root->right, vi);
	postOrderMirror(root->left, vi);
	vi.push_back(root->data);
}

//origin存放初始序列 
//pre post为先序、后序，preM postM 为镜像树先序、后序
vector<int> orign,pre,preM,post,postM;
int main(){
	int n, data;
	node* root = NULL;//定义头节点 
	scanf("%d", &n);//输入节点个数 
	for(int i = 0; i < n; i++){
		scanf("%d",&data);
		orign.push_back(data);//将数据加入orign 
		insert(root, data);//将data插入二叉树 
	}
	
	preOrder(root, pre);
	preOrderMirror(root, preM);
	postOrder(root, post);
	postOrderMirror(root, postM);
	
	if(orign == pre){ //初始序列等于先序序列
		printf("YES\n");
		for(int i = 0; i < post.size(); i++){
			printf("%d", post[i]);
			if(i < post.size() - 1) printf(" ");
		} 
	}else if(orign == preM){
		printf("YES\n");
		for(int i = 0; i < postM.size(); i++){
			printf("%d", postM[i]);
			if(i < postM.size() - 1) printf(" ");
		} 
	} else{
		printf("NO\n");
	}
	
	return 0;
}
 

