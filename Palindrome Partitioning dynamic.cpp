#include<iostream>
using namespace std;
int checkpalindrom(char *array,int n,int m){

	int mid=n+(m-n)/2;
	for(int i=n;i<=mid;i++){
		if(array[n]!=array[m])return 0;
		n++;
		m--;
	}
	return 1;
}
int palindromcutN3(char* arr,int n){
	
	int A[n][n],c[n][n];

	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			c[i][j]=1000;
				A[i][j]=0;
		}
	}
		for(int i=0;i<n;i++){
		A[i][i]=1;
		c[i][i]=0;
	}
	A[0][n-1]=checkpalindrom(arr,0,n-1);
	if(A[0][n-1]==1)return 0;
	for(int L=2;L<=n;L++){
		for(int j=0;j<n-L+1;j++){
			int index2=j+L-1;
			if(L==2){
				if (arr[j]==arr[index2])
				A[j][index2]=1;
				else{ 
				A[j][index2]=0;
				}
				}
				else{if(A[j+1][index2-1]==1&&(arr[j]==arr[index2])){
				
					A[j][index2]=1;}
					else{
							A[j][index2]=0;
					}
				}
			if(A[j][index2]==1){
				c[j][index2]=0;
			}
			else{
			int min=1000;
			for(int k=j;k<index2;k++){
				if(min>c[j][k]+c[k+1][index2]+1){
					min=c[j][k]+c[k+1][index2]+1;
				}
			}
			c[j][index2]=min;
			}
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<c[i][j]<<" ";
		}cout<<endl;
	}
		for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<A[i][j]<<" ";
		}cout<<endl;
	}
	return c[0][n-1];
	
}
int palindromcutN2(char* arr,int n){
	
	int A[n][n] ;
	int c[n][n];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
	 
				A[i][j]=0;
				c[i][j]=1000;
		}
		
	}
		for(int i=0;i<n;i++){
		A[i][i]=1;
		c[i][i]=0;
	 
	}
	A[0][n-1]=checkpalindrom(arr,0,n-1);
	if(A[0][n-1]==1)return 0;
	for(int L=2;L<=n;L++){
		for(int j=0;j<n-L+1;j++){
			int index2=j+L-1;
			if(L==2){
				if (arr[j]==arr[index2])
				A[j][index2]=1;
				else{ 
				A[j][index2]=0;
				}
				}
				else{if(A[j+1][index2-1]==1&&(arr[j]==arr[index2])){
				
					A[j][index2]=1;}
					else{
							A[j][index2]=0;
					}
				}
		}
	}
 
		for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<A[i][j]<<" ";
		}cout<<endl;
	}
 
	for(int L=2;L<=n;L++){
		int index2=L-1;
		if(A[0][index2]==1){
			c[0][index2]=0;
		}else{
			int min=1000;
			for(int i=0;i<index2;i++){
				if(A[i+1][index2]==1){
				
				if(min>c[0][i]+1){
					min=c[0][i]+1;
				}
				}
			}
			c[0][index2]=min;
		}
	}
	for(int i=0;i<n;i++){
		cout<<c[0][i]<<" ";
	}
	cout<<endl;
}
int main(){
	
	char str[] = "ababbbabbababa";
	int n=14;

	cout<<palindromcutN2(str,14);
}
