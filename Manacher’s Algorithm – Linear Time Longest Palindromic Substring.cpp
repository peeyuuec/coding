#include<iostream>
using namespace std;
int min(int a,int b){
	return a<b?a:b;
}
void palindrom(char txt[],int p[]){
	int n=strlen(txt);
    int C=0,R=0,L=0,mirror;
    for(int i=1;i<n;i++){
    	mirror=2*C-i;
    	if(i<R){
    		p[i]=min(R-i,p[mirror]);
		}
		while(txt[i-(1+p[i])]==txt[i+(1+p[i])]){
			p[i]++;
		}
		if(R<i+p[i]){
			R=i+p[i];
			C=i;
		}
	}
	cout<<endl;
	int max=0;
	int center;
	for(int i=0;i<n;i++){
		cout<<p[i]<<"";
		if(max<p[i]){
			max=p[i];
			center=i;
		}
	}
	cout<<endl<<center;
	
}
int main(){
	char str[]="abaaba";
	int n=strlen(str);
	char txt[2*n+3];
	int p[2*n+3];
	
	txt[0]='$';
	for(int i=1;i<=2*n+1;i++){
		if(i%2==0){
			txt[i]=str[i/2-1];
		}
		else{
			txt[i]='|';
		}
	}
	txt[2*n+2]='#';
	txt[2*n+3]='\0';
	cout<<txt;
	for(int i=0;i<2*n+3;i++){
		p[i]=0;
	}
	palindrom(txt,p);
}
