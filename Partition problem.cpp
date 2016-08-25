#include<iostream>
using namespace std;
int min(int a,int b){
	return a<b?a:b;
}
int main()
{
	
	int arr[] = {3, 1, 5, 9, 14};
	int n=5;
	int sum=0;
	for(int i=0;i<n;i++)
	sum+=arr[i];
	if(sum%2!=0){
	cout<<"not possible"<<endl;
	return 0;}
	 sum=sum/2;
	int A[sum+1][n+1];
	for(int i=1;i<=sum;i++){
		A[i][0]=10000;
	}
		for(int i=1;i<=n;i++){
		A[0][i]=0;
	}
	for(int i=1;i<=sum;i++){
		for(int j=1;j<=n;j++){
			if(i>=arr[j-1]){
				A[i][j]=min(A[i-arr[j-1]][j-1],A[i][j-1]);
			}
			else{
				A[i][j]=A[i][j-1];
			}
		}
	}
	cout<<A[sum][n];
}
