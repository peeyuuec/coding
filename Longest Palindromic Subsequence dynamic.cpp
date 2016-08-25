#include<iostream>
using namespace std;
int max(int a,int b){
	return a>b?a:b;
}
int main(){
	 char *seq = "GEEKS FOR GEEKS";
	 //char *seq ="abcd";
	 int length=strlen(seq);
	 char reverse[length];
	 for(int i=0;i<strlen(seq);i++){
	 	reverse[i]=seq[length-i-1];
	 }
	 cout<<reverse<<endl;
	 
	 int A[length+1][length+1];
	 for(int i=0;i<=length;i++)
	 A[0][i]=0;
	  for(int i=0;i<=length;i++)
	 A[i][0]=0;
	 for(int i=1;i<=length;i++){
	 	for(int j=1;j<=length;j++){
	 		if(seq[i-1]==reverse[j-1]){
	 			A[i][j]=1+A[i-1][j-1];
	 			cout<<seq[i];
			 }else{
			 	A[i][j]=max(A[i-1][j],A[i][j-1]);
			 }
		 }
	 }
	 
	 cout<<A[length][length];
}
