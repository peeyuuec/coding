#include<iostream>
using namespace std;
int main(){
	int sum=11;
	int coin[]={1,5,6,9};
	int size=4;
	int cost[sum+1][size+1];
	
	for(int i=0;i<=sum;i++ ){
		for(int j=0;j<=size;j++){
			cost[i][j]=1000;
		}
	}
	for(int i=0;i<=size;i++ ){
		cost[0][i]=0;
	}
	for(int i=1;i<=sum;i++){
		for(int j=1;j<=size;j++){
			if(i>=coin[j-1]){
				cost[i][j]=min(cost[i][j-1],cost[i-coin[j-1]][j]+1);
			}
			else{
				cost[i][j]=	cost[i][j-1];
			}
			
		}
	}
	cout<<sum<<endl;
	for(int i=1;i<=sum;i++ ){
		for(int j=1;j<=size;j++){
			cout<<cost[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<cost[sum][size];
}
