#include<iostream>
using namespace std;
int main(){
	int n=4;
	int A[n+1];
	A[0]=1;
	A[1]=2;
	
	for(int i=2;i<=n;i++){
		A[i]=A[i-1]+A[i-2];
	}
	cout<<A[n];
}
