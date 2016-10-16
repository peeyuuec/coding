#include<iostream>
#include<vector>
using namespace std;

int mincoin(int n,int coins[],vector<int>&temp){
	int count=0;
	for(int i=3;i>=0;i--){
		int t=0;
		while(n>coins[i]){
			t++;
			n=n-coins[i];
		}
		temp[coins[i]]=t;
	}
	return 1;
}
int main(){
	int n=99;
	int coins[]={1,5,10,25};
	int count=0;
	
	vector<int> coincount(coins[3]+1,0);
	for(int i=1;i<=n;i++){
		vector<int>temp(coins[3]+1,0);
		mincoin(i,coins,temp);
		int ii=1;
		for(int j=0;j<coins[3]+1;j++){
			coincount[j]=max(coincount[j],temp[j]);
			if(coincount[j]>0){
				ii+=(coincount[j]*j);
			}
			
		}
		cout<<ii<<" ";
		i=ii;
	}
	for(int i=0;i<coins[3]+1;i++){
		if(coincount[i]>0){
			cout<<coincount[i]<<" ";
		}
	}
}
