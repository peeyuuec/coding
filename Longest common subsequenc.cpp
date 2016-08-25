#include<iostream>
using namespace std;
int main(){
	int n=5,m=6;
	char *s1="abcde";
	char *s2="dfid";
	int A[n+1][m+1];
	for(int i=0;i<=n;i++)
	A[i][0]=0;
	for(int i=0;i<=m;i++)
	A[0][i]=0;
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(s1[i-1]==s2[j-1]){
				A[i][j]=A[i-1][j-1]+1;
			}
			else{
				if(A[i][j-1]>A[i-1][j]){
					A[i][j]=A[i][j-1];
				}
				else{
				A[i][j]=A[i-1][j];	
				}
			}
		}
	}
	cout<<A[n][m];
}
