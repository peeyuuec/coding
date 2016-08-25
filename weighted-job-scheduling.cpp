#include<iostream>
using namespace std;
int main(){
	int n=4;
	 int arr[][3] = {{1, 2, 50},{3, 5, 20}, {6, 19, 100}, {2, 100, 200}};
	 int maxtime=arr[3][1]+1;
	 int a[maxtime][n+1];
	 
	 
	 for(int i=0;i<=maxtime;i++){
	 	a[i][0]=0;
	 }
	 for(int i=0;i<=n;i++){
	 	a[0][i]=0;
	 }
	 for(int i=1;i<=maxtime;i++){
	 	for(int j=1;j<=n;j++){
	 		if(i>=arr[j-1][1]){
	 			a[i][j]=max(a[arr[j-1][0]][j-1]+arr[j-1][2],a[i][j-1]);
			 }
			 else{
			 	a[i][j]=a[i][j-1];
			 }
		 }
	 }
	 
	 for(int i=1;i<=maxtime;i++){
	 	for(int j=1;j<=n;j++){
	 		cout<<a[i][j]<<" ";
	 	}cout<<endl;
	 }
	 	
}
