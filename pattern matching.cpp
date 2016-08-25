#include<iostream>
#include<cmath>
using namespace std;
int Bruteforce(char* str, char* ptr){
	int n=strlen(str);
	int m=strlen(ptr);
	for(int i=0;i<=n-m;i++){
		int count=0;
	for(int j=0;j<m;j++){
		if(str[i+j]==ptr[j]){
			count++;
		}
	}
	if(count==m){
		cout<<i<<endl;
	}	
	}
	return -1;
}
void RobinKarpforinteger(char* str, char* ptr){
	int n=strlen(str);
	int m=strlen(ptr);
	long int ptrhash=0;
	long int tenpowerm=pow(10,m-1);
	for(int i=0;i<m;i++){
		ptrhash=ptrhash+tenpowerm*(ptr[i]-'0');
		tenpowerm=tenpowerm/10;
	}
	tenpowerm=pow(10,m-1);
	long int strhash=0;
		for(int i=0;i<m;i++){
		strhash=strhash+tenpowerm*(str[i]-'0');
		tenpowerm=tenpowerm/10;
	}
	
	tenpowerm=pow(10,m-1);
	for(int i=m;i<=n;i++){
		
		if(strhash==ptrhash){
			
			cout<<i-m<<endl;
		}
		strhash=strhash%tenpowerm;
		
		strhash=strhash*10;
		
		strhash+=(str[i]-'0');
		//cout<<strhash<<endl;
	}
}
void RobinKarpforallchar(char* str, char* ptr){
	int prime=101;
	int n=strlen(str);
	int m=strlen(ptr);
	long int ptrhash=0;
	int base=256;
	long int basepowerm=pow(base,m-1);
	for(int i=0;i<m;i++){
		ptrhash=ptrhash+basepowerm*(ptr[i]);
		basepowerm=basepowerm/base;
		cout<<endl<<ptrhash<<endl;
	}
	ptrhash=ptrhash%prime;
	basepowerm=pow(base,m-1);
	long int strhash=0;
		for(int i=0;i<m;i++){
		strhash=strhash+basepowerm*(str[i]);
		basepowerm=basepowerm/base;
	}
	strhash=strhash%prime;
	basepowerm=pow(base,m-1);
	for(int i=m;i<=n;i++){
		
		if(strhash==ptrhash){
			
			cout<<i-m<<endl;
		}
		strhash=strhash-(basepowerm*str[i-m])%base;
		
		strhash=strhash*base;
		
		strhash+=(str[i]);
		cout<<strhash<<endl;
	}
}
int main(){
	char *str="123";//49   5100+520+53
	char *ptr="123";
	Bruteforce(str,ptr);
		RobinKarpforallchar(str,ptr);
}
