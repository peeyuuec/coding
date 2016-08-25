#include<iostream>
using namespace std;
int main(){
	char* str1="abcdefghi";
	char* str2="bfgjdhefgi";
	
	int n=strlen(str1);
	int m=strlen(str2);
	int a[n+1][m+1];
	for(int i=0;i<=n;i++){
		a[i][0]=0;
	}
	for(int j=0;j<=m;j++){
		a[0][j]=0;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(str1[i]==str2[j]){
				a[i][j]=1+a[i-1][j-1];
			}
			else{
				a[i][j]=0;
			}
		}
	}
	for(int i=0;i<=n;i++){
		for(int j=0;j<=m;j++){
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
}
