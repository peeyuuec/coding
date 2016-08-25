#include<iostream>
using namespace std;
void printpermutation(char str[],int index){
	int m=strlen(str);
	if(index==m){
		cout<<str<<endl;
	}
	for(int i=index;i<m;i++){
		char temp=str[index];
		str[index]=str[i];
		str[i]=temp;
		printpermutation(str,index+1);
	}
	
}
int main(){
		char str[]="abcckk";

	int n=strlen(str);
	char temp[n];
	printpermutation(str,0);
	
}
