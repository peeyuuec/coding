#include<iostream>
using namespace std;
void permutation(char str[],int index,int n){
	
	if(index==n){
		cout<<str<<endl;
		return;
	}
	int c[256];
	for(int i=0;i<256;i++){
		c[i]=0;
	}
	for(int i=index;i<n;i++){
		
		if(i==index||(str[index]!=str[i]&&c[str[i]]!=1)){
			char t=str[index];
		str[index]=str[i];
		str[i]=t;
		//cout<<str<<endl;
		permutation(str,index+1,n);
		 t=str[index];
		str[index]=str[i];
		str[i]=t;
		c[str[i]]=1;
		}
		
	}
}

int main(){
	char str[]="AAAbb";
	int n=strlen(str);
	permutation(str,0,n);
}
