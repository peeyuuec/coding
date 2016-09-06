#include<iostream>
using namespace std;
void sorting(char str[],int index,int len){
	int a[256];
	for(int i=0;i<256;i++){
		a[i]=0;
	}
	for(int i=index;i<len;i++){
		a[str[i]-'0']=1;
	}
	int temp=index;
	for(int i=0;i<256;i++){
		if(a[i]==1){
				a[temp]=(char)(a[i]+'0');
		}
	
	}
	a[len]='\0';
}
void permutation(char str[],int index,int len){
	if(index==len){
		cout<<str<<endl;
		return ;
	}
	
	for(int i=index;i<len;i++){
		
		
		char temp=str[index];
		str[index]=str[i];
		str[i]=temp;
		char temparray[len];
		for(int p=0;p<len;p++){
			temparray[p]=str[p];
		}
		sorting(str,index+1,len);
		permutation(str,index+1,len);
		for(int p=0;p<len;p++){
			str[p]=temparray[p];
		}
	}
	
}
int main(){
	char str[]="ABC";
	char result[3];
	permutation(str,0,3);
}
