#include<iostream>
using namespace std;
int main(){
	int n;
	
	while(1){
		cin>>n;
		int size=2;
		int index=81;
		while((n-1)/index>=1){
			index=index*9;
			size++;
		}
		cout<<size<<endl;
		int a[size];
		int possible=1;
		for(int i=size-1;i>=0;i--){
			int yes=0;
			for(int j=9;j>=1;j--){
				if(n%j==0){
					n=n/j;
					a[i]=j;
					yes=1;
					break;
				}
			}
		}
		if(n>1){
			cout<<"not possible"<<endl;
		}
		else{
			for(int i=0;i<size;i++){
				cout<<a[i]<<" ";
			}
			cout<<endl;
		}
	}
}
