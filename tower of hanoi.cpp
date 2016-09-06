#include<iostream>
#include<string.h>
using namespace std;
void utility(string o,string aux,string result,int n){
	if(n==2){
		cout<<"transfer "<<n-1<< "from "<<o<<" to "<<aux<<endl;
		cout<<"transfer "<<n<< "from "<<o<<" to "<<result<<endl;
		cout<<"transfer "<<n-1<< "from "<<aux<<" to "<<result<<endl;
		return;
		 
	}
	utility(o,result,aux,n-1);
	cout<<"transfer "<<n<<" from"<<o<<" to "<<result<<endl;
	utility(aux,o,result,n-1);
}
void tower(int n){
	string o="A";
	string aux="B";
	string result="C";
	int stack1=-1,stack2=-1,stack3=-1;
	utility(o,aux,result,n);
}
int main(){
	int n=4;
	tower(n);
}
