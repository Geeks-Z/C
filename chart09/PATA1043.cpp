//PATA1043
#include <stdio.h>
#include <stdlib.h>
#include <vector>
using namespace std;

struct node{
	int data; //������ 
	node* left; // ָ���� 
	node* right;
};

//����ڵ� 
void insert(node* &root, int data){
	if(root == NULL){
		root = (node*)malloc(sizeof(node));
		root->data = data;
		root->left = root->right = NULL;
	}
	if(data < root->data) insert(root->left, data); // ���������� 
	else insert(root->right, data); // ���������� 
} 

//������� �������vi 
void preOrder(node* root, vector<int>&vi){
	if(root == NULL) return;
	vi.push_back(root->data);
	preOrder(root->left, vi);
	preOrder(root->right, vi);
} 

//������������� �������vi 
void preOrderMirror(node* root, vector<int>&vi){
	if(root == NULL) return;
	vi.push_back(root->data);
	preOrder(root->right, vi);
	preOrder(root->left, vi);
	
}

//������� �������vi 
void postOrder(node* root, vector<int>&vi){
	if(root == NULL) return;
	postOrder(root->left, vi);
	postOrder(root->right, vi);
	vi.push_back(root->data);
} 

//������������� �������vi 
void postOrderMirror(node* root, vector<int>&vi){
	if(root == NULL) return;
	postOrderMirror(root->right, vi);
	postOrderMirror(root->left, vi);
	vi.push_back(root->data);
}

//origin��ų�ʼ���� 
//pre postΪ���򡢺���preM postM Ϊ���������򡢺���
vector<int> orign,pre,preM,post,postM;
int main(){
	int n, data;
	node* root = NULL;//����ͷ�ڵ� 
	scanf("%d", &n);//����ڵ���� 
	for(int i = 0; i < n; i++){
		scanf("%d",&data);
		orign.push_back(data);//�����ݼ���orign 
		insert(root, data);//��data��������� 
	}
	
	preOrder(root, pre);
	preOrderMirror(root, preM);
	postOrder(root, post);
	postOrderMirror(root, postM);
	
	if(orign == pre){ //��ʼ���е�����������
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
 

