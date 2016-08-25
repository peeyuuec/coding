#include<iostream>

using namespace std;
int main(){
	int n=13;
	
	int score[3]={3,5,10};
	int a[n+1][4];
	a[0][0]=1;
	a[0][1]=1;
	a[0][2]=1;
	a[0][3]=1;
	for(int i=0;i<=n;i++){
		a[i][0]=0;
	}
	for(int p=1;p<=n;p++){
	for(int j=1;j<=3;j++){
		if(p-score[j-1]>=0){
			a[p][j]=a[p][j-1]+a[p-score[j-1]][j];
		}
		else{
			a[p][j]=a[p][j-1];
		}
	}
	
	}
	cout<<a[n][3];

}
