#include<iostream>
using namespace std;
int max(int a,int b){
	return a>b?a:b;
}
int LCS(char* str1,char* str2,int arr1[], int arr2[], int n,int m){
	
	int a[n+1][m+1];
	for(int i=0;i<=n;i++){
		a[i][0]=0;
	}
		for(int i=0;i<=m;i++){
		a[0][i]=0;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(str1[i-1]==str2[j-1]){
				a[i][j]=1+a[i-1][j-1];
			}
			else{
				a[i][j]=max(a[i-1][j],a[i][j-1]);
			}
			
		}
	}
	
	
	int len=a[n][m];
	char ans[len+1];
	int t=len;
	ans[t]='\0';
int index1=n,index2=m;
while(index1>0&&index2>0){
	if(str1[index1-1]==str2[index2-1]){
		ans[len-1]=str1[index1-1];
		index1--;
		index2--;
		len--;
	}
	else if(a[index1-1][index2]>a[index1][index2-1]){
		index1--;
	}
	else{
		index2--;
	}
}
cout<<ans;
len=t;
cout<<endl;

index1=n,index2=m;
while(index1!=0&&index2!=0){
	int temp=a[index1][index2];
	if(str1[index1-1]==str2[index2-1]||(a[index1][index2-1]<temp&&a[index1-1][index2]<temp)){
		arr1[index1-1]=1;
		arr2[index2-1]=1;
		index1--;
		index2--;
		
	}
	else if(a[index1][index2-1]==temp&&a[index1-1][index2]==temp)
	{
		index1--;
	}
	else{
		if(a[index1][index2-1]<temp&&a[index1-1][index2]==temp){
			arr2[index2-1]=1;
			
			while(str1[index1-1]!=str2[index2-1]){
				index1--;
			}
			arr1[index1-1]=1;
			index1--;
			index2--;
			
		}
		else{
		arr1[index1-1]=1;
			
			while(str2[index2-1]!=str1[index1-1]){
				index2--;
			}
			arr2[index2-1]=1;
			index2--;
			index1--;	
		}
	}
}

cout<<endl;
for(int i=0;i<n;i++){
	cout<<arr1[i]<<" ";
}
cout<<endl;
for(int j=0;j<m;j++){
	cout<<arr2[j]<<" ";
}
cout<<endl;
char result[m+n-a[n][m]];
index1=0,index2=0;
int i;
for(i=0;i<m+n-a[n][m];i++){

	if(arr1[index1]==0){
		result[i]=str1[index1];
		index1++;
	}
	else if(arr2[index2]==0){
		result[i]=str2[index2];
		index2++;
	}
	else{
		result[i]=str1[index1];
		index1++;
		index2++;
	}
}
cout<<a[n][m];
for(int p=0;p<i;p++){
	cout<<result[p];
}
cout<<endl;
	
}
int main(){
	int n=6,m=7;
	char *str1 = "AGGTAB";
	char *str2 = "GXTXAYB";
	int arr1[n],arr2[m];
	for(int i=0;i<n;i++){
		arr1[i]=0;
		
	}
		for(int i=0;i<m;i++){
		arr2[i]=0;
		
	}
	LCS(str1,str2,arr1,arr2,n,m);
}
