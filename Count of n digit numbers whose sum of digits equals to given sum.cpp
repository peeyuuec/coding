#include<iostream>
using namespace std;
int main(){
	int n=3,sum=600;
	int a[n+1][sum+1];

		for(int i=0;i<=n;i++){
		
		for(int j=0;j<=sum;j++){
			a[i][j]=0;
		}
		a[i][0]=1;
	}
		for(int i=1;i<=9;i++){
	a[1][i]=1;
	}
	for(int i=2;i<=n;i++){
		for(int s=1;s<=sum;s++){
			a[i][s]=0;
		cout<<a[i][s]<<" "<<i<<" "<<s<<endl;
		for(int j=1;j<10;j++){
			if(s>j){
				cout<<i-1<<" "<<s-j<<endl;
				a[i][s]+=(a[i-1][s-j]);
			}
			 
		}
		
		a[i][s]+=a[i-1][s];
		
		}
	}
	cout<<a[n][sum]<<endl;
}
