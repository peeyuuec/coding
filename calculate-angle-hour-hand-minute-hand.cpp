#include<iostream>
using namespace std;
int min(int a,int b){
	return a>b?b:a;
}
int main(){
	int h=9;
	int m=59;
	int mangle=(m%60)*6;
	int hangle=(h%12)*30+(m%60)/2;
	int angle=mangle>hangle?(mangle-hangle):(hangle-mangle);
	cout<<min(angle,360-angle);
}
