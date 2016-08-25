#include<iostream>
using namespace std;
int main(){
	int n=8;
	int arr[] = { 10, 22, 9, 33, 21, 50, 41, 60 };
	int A[n+1];
	for(int i=0;i<=n;i++)
	   A[i]=1;
	   A[0]=0;
	for(int i=1;i<=n;i++){
		for(int j=0;j<i;j++){
			if(A[i]<=A[j+1]&&arr[i-1]>arr[j]){
				A[i]=A[j+1]	+1;
			}
		
		}
	}
	int max=0;
	for(int i=0;i<=n;i++){
		if(max<A[i])
		max=A[i];
	}
	cout<<max;

}
