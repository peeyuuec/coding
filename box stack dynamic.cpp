#include<iostream>
using namespace std;
int sortboxes(int a[][3],int n){
	for(int i=0;i<n;i++){
		for(int j=1;j<n;j++){
			if(a[j][0]>a[j-1][0]){
				int temp=a[j][0];
				a[j][0]=a[j-1][0];
				a[j-1][0]=temp;
				temp=a[j][1];
				a[j][1]=a[j-1][1];
				a[j-1][1]=temp;
				temp=a[j][2];
				a[j][2]=a[j-1][2];
				a[j-1][2]=temp;
			}
		}
	}
}
int main(){
	 int arr[4][3] = { {4, 6, 7}, {1, 2, 3}, {4, 5, 6}, {10, 12, 32} };
	 int n=4;
	 int allboxes[3*n][3];
	 for(int i=0;i<n;i++){
	 	allboxes[3*i][0]=arr[i][0];
	 	allboxes[3*i][1]=arr[i][1];
	 	allboxes[3*i][2]=arr[i][2];
	 	allboxes[3*i+1][0]=arr[i][1];
	 	allboxes[3*i+1][1]=arr[i][2];
	 	allboxes[3*i+1][2]=arr[i][0];
	 	allboxes[3*i+2][0]=arr[i][2];
	 	allboxes[3*i+2][1]=arr[i][0];
	 	allboxes[3*i+2][2]=arr[i][1];
	 }
	 
	
	 n=3*n;

	 for(int i=0;i<n;i++){
	 	if(allboxes[i][0]<allboxes[i][1]){
	 		int temp=allboxes[i][0];
	 		allboxes[i][0]=allboxes[i][1];
	 		allboxes[i][1]=temp;
		 }
	 } 

	 sortboxes(allboxes,n);
	  int A[n];
	  int parent[n];
	  for(int i=0;i<n;i++){
	  	A[i]=allboxes[i][2];
	  	parent[i]=-1;
	  }
	  for(int i=0;i<n;i++){
	  	int max=0;
	  	for(int j=0;j<i;j++){
	  		if(allboxes[j][1]>allboxes[i][1]&&allboxes[j][0]>allboxes[i][0]&&A[i]<A[j]+allboxes[i][2]){
	  			A[i]=A[j]+allboxes[i][2];
	  			parent[i]=j;
			  }
		  }
	  }
	  int index,max=0;;
	  for(int i=0;i<n;i++){
	  	if(max<A[i]){
	  		max=A[i];
	  		index=i;
		  }
	  }
	  do{
	  	cout<<allboxes[index][0]<<" "<<allboxes[index][1]<<" "<<allboxes[index][2]<<endl;
	  	index=parent[index];
	  }
	  while(index!=-1);
	  
	  
	 	 	 for(int i=0;i<n;i++)
	 cout<<A[i]<<" ";
	cout<<"a"<<endl;
}
