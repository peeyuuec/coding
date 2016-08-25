#include<iostream>
using namespace std;
int main(){
		int n=9;
	int deno[9] = {1, 2, 5, 10, 20, 50, 100, 500, 1000};
	
int m=93;

	for(int i=n-1;i>=0;i--){
		int temp=m/deno[i];
		m=m%deno[i];
		cout<<deno[i]<<": "<<temp<<endl;
	}

}
