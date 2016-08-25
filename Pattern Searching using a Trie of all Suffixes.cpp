#include<iostream>
using namespace std;
struct trinode{
	int index[1000],size;
	trinode* next[256];
	int isleaf;
};
trinode* node(){
	trinode *newnode=new trinode();
	newnode->isleaf=0;
	newnode->size=0;
	for(int i=0;i<256;i++){
	   newnode->next[i]=NULL;
	}
	return newnode;
}
class tri{
	trinode* head;
	public:
	tri(){
		head=node();
	}
	void insert(char str[],int pos){
		int n=strlen(str);
		trinode* temp=head;
		for(int i=0;i<n;i++){
			if(temp->next[str[i]]!=NULL){
				temp=temp->next[str[i]];
			}
			else{
				trinode* t=node();
				temp->next[str[i]]=t;
				temp=t;
			}
		temp->index[temp->size]=pos;
		temp->size+=1;
		}
		temp->isleaf=1;
	}
	void searchtri(char pat[]){
		int i=0;
		trinode* temp=head;
		int n=strlen(pat);
		while(i<n&&temp->next[pat[i]]!=NULL){
			temp=temp->next[pat[i]];
			i++;
		}
		if(i==n){
			for(int i=0;i<temp->size;i++){
				cout<<temp->index[i]<<endl;
			}
		}
	}
};
int main(){
	char str[]="banana";
	tri t;
	int n=strlen(str);
	for(int i=0;i<n;i++){
		
		t.insert(str+i,i);
	}
	char pat[]="a";
	t.searchtri(pat);
}
