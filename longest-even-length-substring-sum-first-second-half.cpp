#include<iostream>
using namespace std;
int strtoarray(char *str,int arr[]){
	int n=strlen(str);
	for(int i=0;i<n;i++){
		char c=str[i];
		int value=c-'0';
		arr[i]=value;
	}
}
int main(){
	char  str[] = "1538023";
	int n=strlen(str);
	int arr[n];
	strtoarray(str,arr);
	for(int i=0;i<n;i++){
		cout<<arr[i];
	}
int sum[n][n];
for(int i=0;i<n;i++){
	for(int j=0;j<n;j++){
		 sum[i][j]=0;
	}
 
}
for(int i=0;i<n;i++){
	sum[i][i]=arr[i];
}
for(int i=0;i<n;i++){
	for(int j=i+1;j<n;j++){
		sum[i][j]=sum[i][j-1]+arr[j];
	}
}
cout<<endl;
for(int i=0;i<n;i++){
	for(int j=0;j<n;j++){
		cout<<sum[i][j]<<" ";
	}
	cout<<endl;
}
int length=0;
int left=-1,right=-1;
for(int L=2;L<=n;L=L+2){
	int index1=n-L+1;
	for(int i=0;i<=index1;i++){
		int index2=i+L-1;
		int mid=i+(index2-i)/2;
		if(sum[i][mid]==sum[mid+1][index2]){
			length=max(length,L);
			left=i;
			right=index2;
		}
	}
}
cout<<length<<" "<<left<<" "<<right;
}
