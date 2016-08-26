#include<iostream>
using namespace std;
int main(){
		int arr[] = {23, 45, -34, 12, 0, 98, -99, 4, 189, -1, 4};
	int n=11;
	for(int i=0;i<n;i++){
		for(int j=0;j<n-1;j++){
			if(arr[j]>arr[j+1]){
				int temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
				
			}
		}
	}
	int sum=0;
	for(int i=1;i<=n;i++){
		
			sum+=arr[i-1];
		
	}
	int a[n+1][sum+1];
	cout<<sum;
	for(int i=0;i<=sum;i++){
		a[0][i]=0;
	}
	for(int i=0;i<=n;i++){
		a[i][0]=1;
	}
	for(int i=1;i<=n;i++){
		for(int s=1;s<=sum;s++){
			if(s>=arr[i-1]){
				if(a[i-1][s]==1||a[i-1][s-arr[i-1]]==1){
					a[i][s]=1;
				}else{
					a[i][s]=0;
				}
			}else{
				a[i][s]=a[i-1][s];
			}
			
		}
	}
	for(int i=0;i<=n;i++){
		for(int j=0;j<=sum;j++){
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<a[11][121]<<endl;
	sum=0;
		for(int i=0;i<=n;i++){
		sum+=arr[i];
	}
	if(sum%2==0)sum=sum/2;
	else{sum=(sum-1)/2;
	}
	cout<<sum<<endl;
	for(int diff=0;diff<=sum;diff++){
		if(a[n][sum-diff]==1||a[n][sum+diff]==1){
			cout<<diff;
			return 1;
		}
	}
	return 1;
}
