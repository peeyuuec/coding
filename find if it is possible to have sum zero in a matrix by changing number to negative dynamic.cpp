#include<iostream>
using namespace std;
int main(){
	int data[4]={2,3,4,5};
	int n=4;
	int sum=0;
	for(int i=0;i<n;i++){
		sum+=data[i];
		
	}
	int a[sum+1][n+1];
	
	for(int i=0;i<=sum;i++){
		a[i][0]=0;
	}
	for(int i=0;i<=n;i++){
		a[0][i]=1;
	}
	for(int s=1;s<=sum;s++){
		for(int i=1;i<=n;i++){
			if(s>=2*data[i]){
				a[s][i]=a[s][i-1]||a[s-2*data[i]][i-1];
			}
			else{
				a[s][i]=a[s][i-1];
			}
		}
	}
	for(int i=0;i<=sum;i++){
		for(int j=0;j<=n;j++){
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<a[sum][n];
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
}
