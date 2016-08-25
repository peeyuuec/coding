#include<iostream>
using namespace std;
struct node{
	int id;
	node* left;
	node* right;
	int LIS;
};
node* newNode(int id){
	node* newnode=new node();
	newnode->left=NULL;
	newnode->right=NULL;
	newnode->id=id;
	newnode->LIS=0;
}
int max(int a,int b){
	return a>b?a:b;
}
int calculateLIS(node* head){
	if(head==NULL){
		return 0;
	}
	if(head->LIS>0) {return head->LIS;
	}
	if(head->left==NULL&&head->right==NULL)return (head->LIS=1);
	int lis_exclude=calculateLIS(head->left)+calculateLIS(head->right);
	int lis_include=1;
	if(head->left!=NULL){
		lis_include+=calculateLIS(head->left->left);
		lis_include+=calculateLIS(head->left->right);
	}
		if(head->right!=NULL){
		lis_include+=calculateLIS(head->right->left);
		lis_include+=calculateLIS(head->right->right);
	}
	return max(lis_exclude,lis_include);
}
int main(){
    node* root=newNode(20);
     root->left                = newNode(8);
    root->left->left          = newNode(4);
    root->left->right         = newNode(12);
    root->left->right->left   = newNode(10);
    root->left->right->right  = newNode(14);
    root->right               = newNode(22);
    root->right->right        = newNode(25);
    cout<<calculateLIS(root);
}
