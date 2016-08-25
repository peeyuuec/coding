#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
struct node{
	int frequency;
	char c;
	node* left;
	node* right;
};
class HuffmanTree{
	
	public:
		HuffmanTree(){
		}
		void* add(node* node1,node* node2){
			node* newnode=new node;
			newnode->frequency=node1->frequency+node2->frequency;
			newnode->left=node1;
			newnode->right=node2;
			newnode->c='$';
			return newnode;
		}
		
		void printTree(node *head){
			if(head==NULL)return;
			
		}
};
int priorityQueue(int *array,int n){
	
	
	for(int i=0;i<n;i++){
	array[i]=array[i]*-1;	
	}
	vector<int> v(array,array+n);
	make_heap(v.begin(),v.end());
	for(int i=0;i<n;i++){
		cout<<v[i];
	}
	
}
struct compare{
	bool operator()(node& node1,node& node2){
		return( node1.frequency>node2.frequency);
	}
};
int main(){
	int array[5]={3,2,5,1,8};
	int charArray[5]={'a','b','c','d','e'};
	int frequency[5]={8,4,7,3,5};
	int n=5;
	node* nodearray=(node*) malloc(n*sizeof(struct node));
	//priorityQueue(array,n);
	
		for(int i=0;i<n;i++){
	frequency[i]=frequency[i]*-1;	
	nodearray[i].c=charArray[i];
	nodearray[i].frequency=frequency[i];
	nodearray[i].left=NULL;
	nodearray[i].right=NULL;
	}
	vector<node> v(nodearray,nodearray+n);
	make_heap(v.begin(),v.end(),compare());
	for(int i=0;i<n;i++){
	
	}
	for(int i=0;i<n;i++){
		cout<<v[i].c;
	}
	while(v.size()!=1){
		node node1=v[0];
		pop_heap(v.begin(),v.end(),compare());
		v.pop_back();
		node node2=v[0];
		node* newnode=new node;
			v.front().frequency=node1.frequency+node2.frequency;
			v.front().left=&node1;
			v.front().right=&node2;
			v.front().c='$';
	make_heap(v.begin(),v.end(),compare());
	}
	cout<<endl;
		for(int i=0;i<n;i++){
		cout<<v[i].frequency;
	}
	
}
