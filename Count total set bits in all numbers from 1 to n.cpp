#include<iostream>
using namespace std;
int calculate(int num[],int bits,int index,int n){
	if(n==0||n==1)return n;
	while(index<bits&&num[index]==0){
		index++;
	}
	if(index>=bits)return 0;
	int temp=1<<(bits-index-1);
	n=n-temp;
	num[index]=0;
	index++;
	cout<<bits-index-1<<endl;
	return (n+1+(bits-index)*(temp>>1)+calculate(num,bits,index,n));
	
	
}
int main(){
	int number=3;
	int n=number;
  
	int bits=0;
	while(n>=1){
		bits++;
		n=n/2;
	}
	//cout<<bits;
	int num[bits];
	n=number;
	for(int i=bits-1;i>=0;i--){
		if(n%2==0){
			num[i]=0;
		}else{
			num[i]=1;
		}
		n=n/2;
	}
	
	for(int i=0;i<bits;i++){
	//	cout<<num[i]<<" ";
	}
cout<<calculate(num,bits,0,number);

}
