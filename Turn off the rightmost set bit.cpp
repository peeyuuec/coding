#include<iostream>
using namespace std;
int main(){
	int n=15;
	int t=~n;
	int p=n^(t+1);
	cout<<(p&n)<<endl;

int a=-5;
int b=-1*a;
cout<<endl<<(a>b)<<endl;
int ans=a^((a^b)&(a>>31));	
int q=a>>1;
cout<< q;
}
