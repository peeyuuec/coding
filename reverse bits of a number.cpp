#include<iostream>
using namespace std;
int main(){
	int num=7;
	int reverse=0;
	
	for(int i=0;i<31;i++){
		int start=num&1;
	
		reverse=reverse|start;
		num=num>>1;
		reverse=reverse<<1;
			cout<<start;
	}
	cout<<endl;
	int n=3;
	if(n<0)
	cout<<"negative number"<<endl;
	else{
		
			int ans=n&(~((~n)+1));
	cout<<ans;
	}
cout<<endl;
n=43;

int a=0x5555;
int t1=n&a;
t1=t1<<1;
a=a<<1;	
int t2=n&a;
t2=t2>>1;
int ans=t1|t2;
cout<<ans;

}
