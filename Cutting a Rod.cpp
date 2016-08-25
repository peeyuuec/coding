#include<iostream>
using namespace std;
int max(int a,int b){
	return a>b?a:b;
}
int main(){
	int n=8;
	int arr[] = {1, 5, 8, 9, 10, 17, 17, 20};

	int A[n+1][n+1];
	for(int i=0;i<=n;i++)
	A[0][i]=0;
		for(int i=0;i<=n;i++)
	A[i][0]=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i>=j){
				A[i][j]=max(A[i-j][j]+arr[j-1],A[i][j-1]);
			}
			else{
				A[i][j]=A[i][j-1];
			}
		}
	}
	cout<<A[n][n];
}
