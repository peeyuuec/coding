#include<iostream>
#include <unistd.h>
using namespace std;
int main(){
	int v1=3,v2=7;
	if(v1>v2){
		int t=v1;
		v1=v2;
		v2=v1;
	}
	while(v1!=1||v2!=1){
		int t=v2-v1;
		if(t>v1){
			v2=t;
		}
		else{
			v2=v1;
		v1=t;	
		}
	
		cout<<v1<<" "<<v2<<endl;
		
	}
}
