#include<iostream>
using namespace std;
int multiply(int a[2][2],int b[2][2]){
	int x=a[0][0]*b[0][0]+a[0][1]*b[1][0];
	int y=a[0][0]*b[0][1]+a[0][1]*b[1][1];
	int z=a[1][0]*b[0][0]+a[1][1]*b[1][0];
	int w=a[1][0]*b[0][1]+a[1][1]*b[1][1];
	a[0][0]=x;
	a[0][1]=y;
	a[1][0]=z;
	a[1][1]=w;
}
int fibonacci(int answer[2][2],int unit[2][2],int n){
	if(n==0||n==1)return 0;
	fibonacci(answer,unit,n/2);
	multiply(answer,answer);
	if(n%2!=0){
	multiply(answer,unit);	
	}
}
int main(){
	int unit[2][2]={{1,1},{1,0}};
	int answer[2][2]={{1,1},{1,0}};
	int n=4;
	fibonacci(answer,unit,n);
	cout<<answer[0][0]<<" "<<answer[0][1]<<endl<<answer[1][0]<<" "<<answer[1][1]<<endl;
}
