#include<iostream>
using namespace std;
int main(){
	int arr[] = {12, 1, 12, 3, 12, 1, 1, 2, 3, 3};
	int n=10;
	int x=1;
	int ans=0;
		int result=0;
	for(int i=0;i<32;i++){
		
int sum=0;
		for(int j=0;j<n;j++){
			sum+=(arr[j]&x);
		}
		if(sum%3!=0){
			result=result|x;
		}
		x=x<<1;
	}
	cout<<result<<endl;
	int q=-3^-4;
	cout<<q;
}
