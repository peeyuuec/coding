#include<iostream>
using namespace std;
int sumdigits(int n){
	int temp=0;
	while(n!=0){
		temp+=n%10;
		n=n/10;
	}
	return temp;
}
int main(){
	int n=328;
	int sum[n+1];
	sum[0]=0;
	sum[1]=1;
	for(int i=2;i<=n;i++){
		sum[i]=sum[i-1]+sumdigits(i);
	}
	cout<<sum[n]<<endl;
}
