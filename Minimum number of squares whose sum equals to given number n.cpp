#include<iostream>
#include<cmath>
using namespace std;
int min(int a,int b){
	return (a<b?a:b);
}
int main(){
	int n=41;
	int d[n+1];
	d[0]=0;
	d[1]=1;

	for(int i=2;i<=n;i++){
		int temp=sqrt(i);
		int value=1000;
		
		for(int j=1;j<=temp;j++){
		
		value=min(value,d[i-j*j]+1);
		}
		d[i]=value;
	}
	cout<<d[n];
}
