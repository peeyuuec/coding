#include<iostream>
using namespace std;
int main(){
	int a=89,b=53,c=917;
	int arr[2]={1,1};
	cout<<!0;
	for(int i=31;i>=0;i--){
		int t=1<<i;
		int x=(a&t);
		x=x>>i;
		int y=(b&t);
		y=y>>i;
		int z=(c&t);
		z=z>>i;
		 if(x==1&&y==1&&z==0){
			cout<<a<<b<<endl;
			cout<<c;
			return 1;
		}
		else if(x==1&&z==1&&y==0){
			
			cout<<b;
			return 1;
		}
		else if(z==1&&y==1&&x==0){
			cout<<a;
			return 1;
		}
		else if(x==0&&y==0&&z==1){
			c=1<<31;
			c=c-1;
		}
		else if(x==0&&z==0&&y==1){
			b=1<<31;
			b=b-1;
		}
		else if(z==0&&y==0&&x==1){
		a=1<<31;
			a=a-1;
		}
	}
}
