#include<iostream>
using namespace std;
int main(){
	int input[]={1, 3, 5, 6, 5, 2, 3, 1, 0, 0, 9};
	int n=11;
	int A[n];
	int parent[n];
	for(int i=0;i<n;i++)
	{
		A[i]=1000;
		parent[i]=-2;
	}
	A[0]=0;
	parent[0]=-1;
	for(int i=0;i<n-1;i++){
		int index=i+input[i];
		if(index>=n){
			index=n-1;
		}
	for(int j=i+1;j<=index;j++){
		
 
	if(A[j]>A[i]+1){
		A[j]=A[i]+1;
		parent[j]=i;
	}		
	}
	}
	for(int i=0;i<n;i++)
		{
	cout<<A[i]<<" ";
	}
	cout<<endl;
	int index=n-1;
	if(parent[index]==-2) {
		cout<<"can not reach last element"<<endl;
		return 0;
	}
	do{
		cout<<index<<" ";
		index=parent[index];
	}
	while(index!=-1);
}
