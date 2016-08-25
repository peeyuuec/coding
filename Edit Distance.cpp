#include<iostream>
using namespace std;
int min(int a,int b,int c){
	if(a<b){
		 return c<a?c:a;
	}
	else{
		return b<c?b:c;
	}
}
int main(){
		int n=6,m=8;
	char *s1="sunday";
	char *s2="saturday";
	int A[n+1][m+1];
	for(int i=0;i<=n;i++){
		A[i][0]=i;
		
	}
		for(int i=0;i<=m;i++){
		A[0][i]=i;
		
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(s1[i-1]==s2[j-1]){
				A[i][j]=A[i-1][j-1];
			}
			else{
			A[i][j]=1+min(A[i][j-1],A[i-1][j],A[i-1][j-1]);
			}
		}
	}
		for(int i=0;i<=n;i++){
				for(int j=0;j<=m;j++){
               	cout<<A[i][j]<<" ";}
				   cout<<endl;}
cout<<A[n][m]<<" ";
}
