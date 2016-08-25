#include<iostream>
using namespace std;
int main(){
	int n=4;
	int arr[n][2] = { {5, 28}, {15, 25},
                          {27, 40}, {50, 60} };
    
    int A[n+1];
    int parent[n];
    for(int i=0;i<n;i++)
    parent[i]=-1;
    for(int i=0;i<=n;i++)
    A[i]=1;
    for(int i=1;i<n;i++){
    	for(int j=0;j<i;j++){
    		if(arr[i][0]>arr[j][1]&&A[j]>=A[i]){
    			A[i]=A[j]+1;
			   parent[i]=j;
			}
		}
	}
	int max=0;
	int index;
	for(int i=0;i<n;i++)
	{
	     if(max<A[i]){
	     	max=A[i];
	     	index=i;
		 }
}
	cout<<endl;
	
	do{
			cout<<index<<" ";
		index=parent[index];
	}
	while(index!=-1);
	

}
