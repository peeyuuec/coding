#include<iostream>
using namespace std;
int main(){
	int n=7;
	 
		int arr[] = {6, 2, 5, 4, 5, 1, 6};
		int sum[n];
		int parent[n];
		for(int i=0;i<n;i++){
			sum[i]=arr[i];
			parent[i]=-1;
		}
		
		for(int i=0;i<n;i++){
			for(int j=0;j<i;j++){
				if(arr[i]>arr[j]&&sum[j]+arr[i]>sum[i]){
					sum[i]=sum[j]+arr[i];
					parent[i]=j;
				}
			}
		}
		 
		int maxx=0;
		int index;
				for(int i=0;i<n;i++){
				if(maxx<sum[i]){
					maxx=sum[i];
					index=i;
				}	
				cout<<parent[i]<<" ";
				}
				 cout<<maxx<<endl;
		
		do{
			cout<<index<<" ";
			index=parent[index];
		}
		while(index!=-1);

}
