#include<iostream>
#include<cmath>
#include<climits>
using namespace std;
#define INT_MAX 1000
int main()
{
	
	string s="110111100000101101101011001110100111011001";
	int n=s.length();
	int a[n][n];
	/*
	for(int i=0;i<n;i++){
		if(s[i]=='1'){
			a[i][i]=0;
		}
		else{
			a[i][i]=INT_MAX;
		}
	}
	
	*/
	for(int j=0;j<n;j++){
	long long num=0;
	
	for(int i=j;i<n;i++){
		if(s[j]=='1'){
		
		num=num*2+(s[i]-'0');
		if(num>0){
			int logval=((float)log(num))/((float)log(5));
		if(pow(5,logval)==num){
			a[j][i]=0;
		}
		else{
			a[j][i]=INT_MAX;
		}
		}
		else{ 
		a[j][i]=INT_MAX;
		}
		cout<<a[j][i]<<" ";
	}
	else{
		a[j][i]=INT_MAX;
	}
	}cout<<endl;
}
	
	
	for(int len=2;len<=n;len++){
		int limit1=n-len;
		for(int i=0;i<=limit1;i++){
			int j=i+len-1;
			int mini=a[i][j];
			for(int k=i+1;k<=j;k++){
				if(a[i][k-1]+a[k][j]+1<mini){
					mini=a[i][k-1]+a[k][j]+1;
				}
			}
			a[i][j]=mini;
		}
	}
	
	
	cout<<endl;
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
				cout<<a[i][j]<<" ";
		
		}
			cout<<endl;
	}
	cout<<a[0][n-1];
	}
