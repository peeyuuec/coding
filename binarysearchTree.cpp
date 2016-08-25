#include<iostream>
using namespace std;
struct node{
	int data;
	node* left;
	node* right;
};
class binaryTree{
	node* head;
	public:
		binaryTree(){
			head=NULL;
		}
		void add(int data){
			node *newnode=new node;
			newnode->data=data;
			newnode->left=NULL;
			newnode->right=NULL;
			if(head==NULL){
				head=newnode;
				return;
			}
			else{
				node* temp=head;
				node* temp2=head;
				while(temp!=NULL){
					if(data<=temp->data){
						temp2=temp;
						temp=temp->left;
					}
					else{
						temp2=temp;
						temp=temp->right;
					}
				}
				if(data<=temp2->data){
						temp2->left=newnode;
					}
					else{
						temp2->right=newnode;
					}
			}
		}
		void inorderTraversal(node* h){
			if(h==NULL) return;
			inorderTraversal(h->left);
			cout<<h->data;
			inorderTraversal(h->right);
		}
		void printBST(){
			node* temp=head;
			inorderTraversal(temp);
		}
		
		void createBST(int *array, int n ){
	for(int i=0;i<n;i++){
		add(array[i]);
	}
}
int getmax(){
	node* temp=head;
	while(temp->right!=NULL){
		temp=temp->right;
	}
	return temp->data;
}
void removemax(){
	node* temp=head;
	node* temp2=head;
	if(temp==NULL){
		cout<<"Empty tree"<<endl;
		return;
	}
	while(temp->right!=NULL){
		temp2=temp;
		temp=temp->right;
	}
	if(temp==head){
		head=head->left;
	}
	else{
		temp2->right=temp->left;
	}
	
}
void printKsmallest(int *array,int n,int k){
	for(int i=k;i<n;i++){
		int max=getmax();
		if(array[i]<max){
			removemax();
			add(array[i]);
		}
	}
	printBST();
}
void printpreorder(node *temp){
	if(temp==NULL) return;
	
	cout<<temp->data<<" ";
	printpreorder(temp->left);
	printpreorder(temp->right);
	
	return;
}
void preorder(){
	node* temp=head;
	printpreorder(temp);
}
void preorderiterative(){
	node* temp=head;
	node* arr[100];
	int top=-1;
	while(1){
		while(temp!=NULL){
			cout<<temp->data<<" ";
			arr[++top]=temp;
			temp=temp->left;
		}
		temp=arr[top--];
		if(temp->right!=NULL){
			temp=temp->right;
		}else{
			temp=NULL;
		}
		if(top==-1)break;
	}
	return ;
}
void inorderiterative(){
	node* temp=head;
	node* stack[1000];
	int top=-1;
	while(1){
		while(temp!=NULL){
			stack[++top]=temp;
			temp=temp->left;
		}
		if(top==-1){
			break;
		}
		temp=stack[top--];
		cout<<temp->data<<" ";
		temp=temp->right;
		
	}
	return;
}
void postorderiterative(){
	node* temp=head;
	node* stack[1000];
	int top=-1;
	do{
		while(temp!=NULL){
			if(temp->right!=NULL){
				stack[++top]=temp->right;
			}
			stack[++top]=temp;
			temp=temp->left;
		}
		temp=stack[top--];
		if(temp->right!=NULL&&temp->right==stack[top]){
			top--;
			stack[++top]=temp;
			temp=temp->right;
		}
		else{
			cout<<temp->data<<" ";
			temp=NULL;
		}

		
	}
	while(top!=-1);
}
int depth(node* temp){
	if(temp==NULL)return 0;
	int left=depth(temp->left);
	int right=depth(temp->right);
	if(left>right){
		return (1+left);
	}
	else{
		return (1+right);
	}
}
int depthOfBinaryTree(){
	node* temp=head;
	return depth( temp);
}

};

int main(){
		int array[6]={10, 7, 8, 9, 1, 5};  
 int n=6;
 int k=2;
 binaryTree bt;
 bt.createBST(array,n);
bt.preorder();
cout<<endl;
bt.preorderiterative();
cout<<endl;
bt.inorderiterative();
cout<<endl<<"a";
bt.postorderiterative();
//bt.printKsmallest(array,n,k);
 cout<<endl<<bt.depthOfBinaryTree();
}
