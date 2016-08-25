#include<iostream>
using namespace std;
int main(){
	 int l[] = {3, 2, 2, 5};
    int n = sizeof(l)/sizeof(l[0]);
    int M = 6;
  
    int lc[n+1][n+1];
    int extras[n+1][n+1];
    	
			for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			extras[i][j]=0;
			lc[i][j]=1000;
		}
		 }
		
    for(int i=1;i<=n;i++){
    	extras[i][i]=M-l[i-1];
    	for(int j=i+1;j<=n;j++){
    		extras[i][j]=extras[i][j-1]-l[j-1]-1;
		}
	}
		for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cout<<extras[i][j]<<" ";
		}
		cout<<endl; }
		cout<<endl;
	for(int i=1;i<=n;i++){
		 
		for(int j=1;j<=n;j++){
			if(extras[i][j]<0){
				lc[i][j]=1000;
			}
			else if(j==n){
				lc[i][j]=0;
			}
			else{
				lc[i][j]=extras[i][j]*extras[i][j];
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cout<<lc[i][j]<<" ";
		}
		cout<<endl;
	}cout<<endl;
	
	int cost[n+1];
	cost[0]=0;
	for(int i=1;i<=n;i++){
		int min=1000;
		cost[i]=1000;
		for(int j=1;j<=i;j++){
			if(cost[i-1]!=1000&&lc[j][i]!=1000&&min>cost[j-1]+lc[j][i])
			min=cost[j-1]+lc[j][i];
		}
		cost[i]=min;
	}
	cout<<endl;
	for(int i=0;i<=n;i++)
	cout<<cost[i]<<" ";
}
