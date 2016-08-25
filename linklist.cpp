#include<iostream>
using namespace std;
struct node{
	int data;
	node *next;
};
class linklist{
	node* head;

	public: 
	linklist(){
		head=NULL;
	}

	int size(){
		int s=0;
		node* temp=head;
		while(temp!=NULL){
			s++;
			temp=temp->next;
		}
		return s;
	}
	node* addfront(int data){
		node* temp=new node;
		temp->data=data;
		temp->next=head;
		head=temp;
		return head;
	}
	void removefront(){
		if(head==NULL) {
	cout<<"empty list"<<endl;
	return;
	}
		cout<<head->data<<endl;
		head=head->next;
		
		return ;
	}
	node* addlast(int data){
	    
	    node* newnode=new node;
	    newnode->data=data;
	    newnode->next=NULL;
		if(head==NULL){
			head=newnode;
			return head;
		}
		node* temp=head;
		while(temp->next!=NULL){
			temp=temp->next;
		}
		temp->next=newnode;
		return head;
	}
	void removelast(){
		if(head==NULL) {
		cout<<"Empty List"<<endl;
				}
		node* temp=head;
		node* temp2=head;
		temp=temp->next;
		while(temp->next!=NULL){
			temp=temp->next;
			temp2=temp2->next;
		}
		cout<<temp->data<<endl;
		temp2->next=NULL;
	}
	void addat(int data,int position){
		
		if(position==0){
			cout<<"position should be > 0";
			return;
		}
		if(position==1){
			addfront(data);
			return;
		}
		
		if(size()<position){
			cout<<"size is less than position, adding at last";
		    addlast(data);
			return;
		}
		node* newnode=new node;
		newnode->data=data;
		node *temp1=head,*temp2=head->next;
		for(int i=0;i<position-2;i++){
			temp2=temp2->next;
			temp1=temp1->next;
		}
		newnode->next=temp2;
		temp1->next=newnode;
		cout<<"added"<<endl;
		return;
		
	}
	void removeat(int position){
		if(size()<position){
			cout<<"size less than position"<<endl;
			return ;
		}
		if(size()==0){
			cout<<"empty list"<<endl;
			return;
		}
		if(position==1){
			removefront();
			return;
		}
		node* temp1=head;
		node* temp2=head->next;
		for(int i=0;i<position-2;i++){
			temp2=temp2->next;
			temp1=temp1->next;
		}
		temp1->next=temp2->next;
		return;
	}
	void print(){
		node* temp=head;
		while(temp!=NULL){
			cout<<temp->data<<" ";
			temp=temp->next;
		}
	}

void reverseinKblocks(int k){
	int s=size();
	if(k==0||k==1||s<k){
		return ;
	}
	int blocks=s/k;
	cout<<"blocks"<<blocks<<endl;
    node* temp=head;
    for(int p=0;p<k-1;p++){
    	temp=temp->next;
	}
	for(int i=0;i<blocks;i++){
		   node* kplus1=head;
		    for(int p=0;p<2*k-1&&kplus1!=NULL;p++){
        	cout<<"value"<<kplus1->data<<endl;
			kplus1=kplus1->next;
        	
	      }
	      //cout<<"kplus1"<<kplus1->data<<endl;
		node* temp1=head;
    	node* temp2=head->next;
    	node* t=head;
    	if(kplus1!=NULL){
		
		head->next=kplus1;}
	
    	for(int j=0;j<k-1;j++){
		
    	
    	head=temp2;
    	temp2=temp2->next;
    	head->next=temp1;
    	temp1=head;
    	//cout<<"head"<<head->data<<endl;
        }
       	if(kplus1==NULL){
			t->next=temp2;
		}
        head=temp2;
    	
	}
	head=temp;
}
node* gethead(){
	return head;
}
void splitintwo(node* h,node** a,node** b)
{
	*a=h;
	*b=h;
	node *a1,*b1;
	if(h==NULL||h->next==NULL){
		*a=h;
		*b=NULL;
			return;
	}
	a1=h;
	b1=h;
	int s=size();
	int mid=(s+size()%2)/2 ;
	node* temp=h;
	for(int i=0;i<mid;i++)
	   {
	   temp=b1;
	   b1=b1->next;}
	   temp->next=NULL;
	   *b=b1;
	   
}
node* merge(node* a,node* b){
	node* temp=a;
	while(a->next!=NULL)
	{cout<<"a";
	a=a->next;
	}
	//cout<<b->data;
	a->next=b;
	
	return temp;
}
node* LLmergesort(node* h){
	if(h==NULL||h->next==NULL) {
		//cout<<h->data;
	return h;}
	else{
		node *a,*b;
		splitintwo(h,&a,&b);
		node *t1,*t2;
		t1=a;
		t2=b;
	//	cout<<t2->next->data;
		t1=LLmergesort(t1);
		
		t2=LLmergesort(t2);
		node* newhead;
		newhead=merge(t1,t2);
		return newhead;
	}
}
void sethead(node* h){
	head=h;
}

node* quicksortpartition(node* left,node* right,node** beforepivot){

		if(left==right) return left;
	node* temp=left;
	node* pivot=right;
	while(temp->data>pivot->data){
		left=left->next;
		temp->next=right->next;
		right->next=temp;
		right=temp;
		temp=left;
	}
		
	node* temp2=left; 
	temp=left->next;
	while(temp!=pivot){
		
		if(temp->data>pivot->data){
			temp2->next=temp->next;
				temp->next=right->next;
			right->next=temp;
		
			right=temp;
			temp=temp2->next;
		}
		else{
			temp=temp->next;
			temp2=temp2->next;
		}
	}
	head=left;
	return pivot;
}
node* quicksortlinklist(node* left,node* right){

	if(left==NULL||left->next==NULL) return left;

//	node* pivot=quicksortpartition(left,);
	//quicksortlinklist()
}

node *insertionsortLL(){
   node* temp1=head;
   if(temp1==NULL||temp1->next==NULL) return temp1;
   int s=size();
   node* temp2=head;
   node* temp3=head;
   node* temp4=head;
   for(int i=1;i<s;i++){
   	
   	temp3=temp2;
   	temp4=temp2->next;
   	int data=temp4->data;
   	temp1=NULL;
   	temp2=head;
   	while(temp2->data<data){
   		temp1=temp2;
   		temp2=temp2->next;
	   }
	   if(temp2==temp4){
	   	
	   }
	   else{
	   
	   
	   if(temp1==NULL){

		   
	   	temp3->next=temp4->next;
	   	temp4->next=temp2;
	   	head=temp4;
	   
	   	
	   }
	   else{
	   
	   temp1->next=temp4;
	   temp3->next=temp4->next;
	   temp4->next=temp2;
	   
	   }
	   
	   
}
	   
   }	
}
};
int main(){
	node *a,*b;
	linklist ll;
ll.addfront(30);
ll.addfront(3);
//ll.removefront();
ll.addfront(4);
//ll.removelast();
ll.addfront(20);
ll.addfront(5);
//ll.removefront();
node* temp=ll.gethead();
while(temp->next!=NULL){
	temp=temp->next;
}
//ll.quicksortpartition(ll.gethead(),temp);
//ll.sethead(ll.LLmergesort(ll.gethead()));
//ll.splitintwo(ll.gethead(),&a,&b);
//ll.sethead(a);

ll.insertionsortLL();
cout<<endl;
//	cout<<ll.size();
	ll.print();
}
