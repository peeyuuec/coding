#include<iostream>
using namespace std;
void printpermutation(char str[],char t[],int index,int aux){
	int m=strlen(str);
	
	if(index>0){
		cout<<t<<endl;
	}
	for(int i=aux+1;i<m;i++){
		t[index]=str[i];
		t[index+1]='\0';
		printpermutation(str,t,index+1,i);
	}
	
}
int main(){
		char str[]="abc";

	int n=strlen(str);
	char temp[n];
	printpermutation(str,temp,0,-1);
	
}
