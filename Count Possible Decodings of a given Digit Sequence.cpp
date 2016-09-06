#include<iostream>
using namespace std;
int main(){
	char digits[] = "121321";
	int n=strlen(digits);
	int a[n];
	a[0]=1;
	for(int i=1;i<n;i++){
		int num=0;
		a[i]=a[i-1];
		num+=((10*(digits[n-i-1]-'0'))+(digits[n-i]-'0'));
		if(num<26){
		if(i>1){
			a[i]+=a[i-2];
		}
		else{
			a[i]+=1;
		}
		}
	}
	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
}
