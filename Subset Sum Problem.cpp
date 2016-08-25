#include<iostream>
using namespace std;
int check(int *set,int *A,int sum,int n,int *ispossible){
	if(sum==0) return 1;
	if(sum<0) return 0;
	for(int i=0;i<n;i++){
		if(A[i]!=1){
			A[i]=1;
			if(check(set,A,sum-set[i],n,ispossible)==1){
				*ispossible=1;
				return 1;
			}
			A[i]=0;
		}
	}
	return 0;
}
int checkdynamic(int *set,int sum,int n){
	int A[sum+1][n+1];
	for(int i=0;i<=n;i++){
		A[0][i]=1;
	}
	for(int i=1;i<=sum;i++){
		A[i][0]=0;
	}
	for(int i=1;i<=sum;i++){
		for(int j=1;j<=n;j++){
				A[i][j]=A[i][j-1];
			if(i>=set[j-1]){
				if(A[i-set[j-1]][j-1]==1||A[i][j-1]==1){
				A[i][j]=1;	
				}
			
			}
		 
			
		}
		
	}
	cout<<A[sum][n];
	
}
int main(){
	int n=6;
	int set[]={0, 34, 1, 12, 5, 2};
	int A[6]={0,0,0,0,0,0};
	int sum=9;
	int ispossible=0;
	check(set,A,sum,n,&ispossible);
	cout<<ispossible<<endl;
	checkdynamic(set,sum,n);
}
