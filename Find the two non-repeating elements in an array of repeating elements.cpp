#include<iostream>
using namespace std;
int main(){
	int a[]={11,3,11,5,5,8};
	int n=6;
	int axorb=0;
	for(int i=0;i<n;i++){
		axorb=axorb^a[i];
	}
	int bitnum=0;
	while(axorb%2!=1){
		bitnum++;
		axorb=axorb/2;
	}
	cout<<bitnum<<endl;
	int first=0;
	int selector=1<<bitnum;
	cout<<selector;
	for(int i=0;i<n;i++){
		if((a[i]&selector)!=0){
			cout<<"a";
			first=first^a[i];
		}
	}
	cout<<first<<endl;
	
	int x = 2147483640;
	x=x>>30;
	cout<<x;
}
