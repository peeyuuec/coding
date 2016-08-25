#include<iostream>
using namespace std;
int max(int a,int b){
	return a>b?a:b;
}
int main(){
	 int i, j;
	 int n=4;
	 int m=3;
    int arr[3] = {1, 2, 3};
    int A[n+1][m+1];
    for(int i=0;i<=n;i++)
    A[i][0]=0;
    for(int i=0;i<=m;i++)
    A[0][i]=1;
	for(int i=1;i<=n;i++){
	
      for(int j=1;j<=m;j++){
      	int x=0;
		  if(i>=arr[j-1]){
      	x=A[i-arr[j-1]][j];
		  }
		 
		  	A[i][j]=x+A[i][j-1];
		  
         
	  }}
	  	for(int i=0;i<=n;i++){
	
      for(int j=0;j<=m;j++){

cout<<A[i][j]<<" ";
         
	  }
	  cout<<endl;
	  }
	  cout<<A[n][m];

}
