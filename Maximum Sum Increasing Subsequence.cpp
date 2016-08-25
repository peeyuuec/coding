#include<iostream>
using namespace std;
int main(){
		int n=7;
	int arr[] = {1, 101, 2, 3, 100, 4, 5};
	int index[n];
	int A[n+1];
	for(int i=1;i<=n;i++){
		A[i]=arr[i-1];
		index[i-1]=-1;
	}
	for(int i=1;i<=n;i++){
		int max=0;
		int temp=-1;
		for(int j=1;j<i;j++){
			if(arr[i-1]>=arr[j-1]){
				if(max<A[j]){
					max=A[j];
					temp=j;
				}
			}
		}
		A[i]=max+arr[i-1];
		index[i-1]=temp-1;
	}
	int max=0,in;
		for(int i=1;i<=n;i++){
		cout<<A[i]<<" ";
		if(max<A[i]){
			max=A[i];
			in=i-1;
		}
		
	}
	cout<<endl;
		while(index[in]>=0){
		cout<<arr[in]<<" ";
		in=index[in];
	}cout<<arr[in];
	cout<<endl;
	cout<<"max:"<<max<<endl<<"index:"<<in<<endl;
			for(int i=0;i<n;i++){
		cout<<index[i]<<" ";
	}cout<<endl;

	
	
	
}
