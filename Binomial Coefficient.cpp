#include<iostream>
using namespace std;
int binomiacoefficientefficiently(int n,int k){
	int A[k+1];
	A[0]=1;
	for(int i=1;i<=k;i++){
		A[i]=((n-i+1) *A[i-1])/i;
	}
	return A[k];
}
int main(){
	
	int n=7,k=2;
	int A[n+1][k+1];
			for(int i=1;i<=n;i++){
				for(int j=0;j<=k;j++)
		 A[i][j]=0;
	}
	for(int i=0;i<=n;i++){
		A[i][0]=1;
	}

	for(int i=1;i<=n;i++){
		for(int j=1;j<=k;j++){
			if(i>=j)
			A[i][j]=A[i-1][j-1]+A[i-1][j];
		}
	}
	cout<<A[n][k]<<endl;
	cout<< binomiacoefficientefficiently(n, k);
}
