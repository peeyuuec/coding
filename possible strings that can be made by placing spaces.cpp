#include<iostream>
using namespace std;
void permutation(char str[],int n,char temp[],int index){
	if(index==n){
		cout<<temp<<endl;
		return;
	}
	int size=strlen(temp);
	temp[size]=' ';
	temp[size+1]=str[index];
	temp[size+2]='\0';
	permutation(str,n,temp,index+1);
	temp[size]=str[index];
	temp[size+1]='\0';
	permutation(str,n,temp,index+1);
	
	
}
int main(){
	char str[]="ABCD";
	int n=strlen(str);
	char temp[n];
	temp[0]=str[0];
	temp[1]='\0';
	permutation(str,n,temp,1);
}
