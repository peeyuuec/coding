#include<iostream>
using namespace std;
int main(){
	int n=3;
	 int arr[] = {10, 20, 30}   ;
	 int A[n][n];
	 for(int i=0;i<n;i++){
	 	A[i][i]=0;
	 }
	 for(int L=2;L<n;L++){
	 	int index1=n-L+1;
	 	for(int i=1;i<index1;i++){
	 		int index2=i+L-1;
	 		int min=100000;
	 		for(int k=i;k<index2;k++){
	 			int temp=A[i][k]+A[k+1][index2]+arr[i-1]*arr[k]*arr[index2];
	 			if(temp<min){
	 				min=temp;
				 }
	 			
			 }
			 A[i][index2]=min;
		 }
	 }
	 cout<<A[1][n-1];
}
