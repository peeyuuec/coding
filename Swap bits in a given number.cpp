#include<iostream>
using namespace std;
int main(){
	int num=28;
		int n=num;
  
	int bits=0;
	while(n>=1){
		bits++;
		n=n/2;
	}
		int p1=0,p2=3;
	int count=2;
	for(int i=0;i<count;i++){
		
		
	int t=1<<30;
	t=t-1;
	int a=num&(1<<p1);
	int b=num&(1<<p2);
	cout<<a<<" "<<b<<endl;
	int t1=t-(1<<p1);
	int t2=t-(1<<p2);
	cout<<t1<<" "<<t2<<endl;
	num=num&t1;
	num=num&t2;
	num=num|(a<<(p2-p1));
	num=num|(b>>(p2-p1));
	int tt=b>>(p2-p1);
	cout<<tt<<endl;
	cout<<num;
		p1++;
		p2++;
	}

	 
}
