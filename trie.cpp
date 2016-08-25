#include<iostream>
using namespace std;
struct node{
	node* child[256];
	int isleaf;
};
node* newnodes(){
	node* newnode=new node();
	for(int i=0;i<256;i++){
		newnode->child[i]=NULL;
	}
	newnode->isleaf=0;
	return newnode;
}
class trie{
	node* head;
	public:
		trie(){
			head=newnodes();
		}
		void insert(char* str){
			node* temp=head;
			int n=strlen(str);
			for(int i=0;i<n;i++){
				
				if(temp->child[str[i]]!=NULL){
					
					temp=temp->child[str[i]];
				}
				else{
					
					node* newnode=newnodes();
					
					temp->child[str[i]]=newnode;
					temp=newnode;
				}
			}
			temp->isleaf=1;
		}
		int searchTRIE(char* str){
			int n=strlen(str);
			node* temp=head;
			int i=0;
			for( i=0;i<n;i++){
				if(temp->child[str[i]]==NULL)return 0;
				temp=temp->child[str[i]];
				
			}
			if(temp->isleaf==0) return 0;
			return 1;
		}
		void printtree(node* temp,char* output){
			if(temp->isleaf==1){
				if(strlen(output)>0){
					cout<<output<<endl;
				}	}
				int n=strlen(output);
				for(int i=0;i<256;i++){
					if(temp->child[i]!=NULL){
						output[n]=(char)i;
						output[n+1]='\0';
						printtree(temp->child[i],output);
					}
				}
		
			
		}
		void print(){
			node* temp=head;
			char output[100];
			printtree(temp,output);
		}
		
};
int main(){
	trie t;
	char keys[][8] = {"the", "a", "there", "answer", "any",
                     "by", "bye", "their"};
	for(int i=0;i<8;i++)
	t.insert(keys[i]);
	cout<<t.searchTRIE(keys[1]);
	t.print();
}
