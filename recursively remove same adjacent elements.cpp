#include<iostream>
using namespace std;
removeadjacent(char str[],int m){
	int n=strlen(str);
	for(int i=0;i<n-1;i++){
		if(str[i]==str[i+1]){
			str[i]='$';
		}
	}
	for(int i=0;i<n-1;i++){
		if(str[i]=='$'){
			str[i+1]='$';
			i++;
		}
	}
	
	
	int index=0;
	for(int i=0;i<n;i++){
		if(str[i]!='$'){
			str[index]=str[i];
			index++;
		}
	}
	str[index]='\0';
	//cout<<str;
	if(index!=m){
		removeadjacent(str,index);
	}
}

int main(){
		char str[]="abccbcba";

	int n=strlen(str);
	char temp[n];
	removeadjacent(str,n);
	cout<<str;
}
