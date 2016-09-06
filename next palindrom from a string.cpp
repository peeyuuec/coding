#include<iostream>
using namespace std;
int ispalindrom(char num[]){
	int n=strlen(num);
	for(int i=0;i<n;i++){
		if(num[i]!=num[n-i-1]){
			return 0;
		}
	}
	return 1;
}
int isall9(char num[]){
	int n=strlen(num);
	for(int i=0;i<n;i++){
		if(num[i]!='9'){
			return 0;
		}
	}
	return 1;
}
void nextpalin(char num[],char result[]){
	int n=strlen(num);
	
	if(n%2==0){
		int carry=1;
		for(int i=n/2-1;i>=0;i--){
			int t=num[i]-'0';
			result[i]=(char)((t+carry)%10+'0');
			result[n-i-1]=result[i];
			carry=(t+carry)/10;
			
		}
	}
	else{
			int carry=1;
		for(int i=((n+1)/2)-1;i>=0;i--){
			int t=num[i]-'0';
			result[i]=(char)((t+carry)%10+'0');
			result[n-i-1]=result[i];
			carry=(t+carry)/10;
			
		}
	}
	result[n]='\0';
}
int issmall(char result[],char num[],int n){
	for(int i=0;i<n;i++){
		int a=result[i]-'0';
		int b=num[i]-'0';
		if(a<b)return 1;
	}
	return 0;
}
int main(){
	char num[]="94187978322";
	
	int n=strlen(num);
	char result[n+1];
	if(isall9(num)){
		result[0]='1';
		result[n]='1';
		for(int i=1;i<n;i++){
			result[i]='0';
		}
		result[n+1]='\0';
		cout<<result;
	}
	else if(ispalindrom(num)){
		nextpalin(num,result);
		cout<<result;
	}
	else{
		
		for(int i=0;i<(n+1)/2;i++){
			result[i]=num[i];
			result[n-i-1]=result[i];
		}
		result[n]='\0';
		cout<<result<<endl;
		char r[n];
		if(issmall(result,num,n)==1){
			nextpalin(result,r);
		}
		cout<<r<<endl;
	}
}
