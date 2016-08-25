#include<iostream>
using namespace std;
int max(int a,int b){
	return a>b?a:b;
}
int main(){
	int n=3,m=3;
	int w[n]={2,3,1};
	int v[n]={5,7,3};
	int W=4;
	int A[W+1][n+1];
	for(int i=0;i<=W;i++){
	A[i][0]=0;	
	}
		for(int i=0;i<=n;i++){
	A[0][i]=0;	
	}
	for(int i=1;i<=W;i++){
		for(int j=1;j<=n;j++){
			if(i>=w[j-1]){
				A[i][j]=max(A[i][j-1],A[i-w[j-1]][j-1]+v[j-1]);
			}
			else{
					A[i][j]=A[i][j-1];
			}
		}
	}
	cout<<A[W][n];
}
