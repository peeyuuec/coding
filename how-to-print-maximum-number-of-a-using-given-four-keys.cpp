#include<iostream>
using namespace std;
int max(int a,int b){
	return a>b?a:b;
}
int maxA(int n){
	if(n<7){
		return n;
	}
	int maxvalue=0;
	for(int i=n-3;i>=0;i--){
		maxvalue=max(maxvalue,(n-i-1)*maxA(i));
	}
	return maxvalue;
}
int maxADynamic(int n){
	int a[n];
	for(int i=0;i<7;i++){
		a[i]=i;
	}
	
	for(int p=7;p<=n;p++){
		int maxvalue=0;
		for(int i=p-3;i>=0;i--){
		maxvalue=max(maxvalue,(p-i-1)*maxA(i));
	}
	a[p]=maxvalue;
	}
	
	return a[n];
}
int main(){
	int n=9;
	for(int i=6;i<15;i++){
		cout<<i<<" :"<<maxADynamic(i)<<endl;
	}
	
	
}
