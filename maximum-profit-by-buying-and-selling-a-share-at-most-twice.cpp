#include<iostream>
using namespace std;
int min(int a,int b){
	return a<b?a:b;
}
int max(int a,int b){
	return a>b?a:b;
}
int main(){
	int n=7;
	int price[] = {2, 30, 15, 10, 8, 25, 80};
	int profit_l_r[7];
	int profit_r_l[7];
	int min_l_r[7],max_r_l[7];
	min_l_r[0]=price[0];
	max_r_l[n-1]=price[n-1];
	for(int i=1;i<n;i++){
		min_l_r[i]=min(min_l_r[i-1],price[i]);
		cout<<min_l_r[i]<<" ";
	}cout<<endl;
		for(int i=n-2;i>=0;i--){
		max_r_l[i]=max(max_r_l[i+1],price[i]);
		cout<<max_r_l[i]<<" ";
	}cout<<endl;
	
	profit_l_r[0]=0;
	for(int i=1;i<n;i++){
		profit_l_r[i]=max(price[i]-min_l_r[i-1],profit_l_r[i-1]);
		cout<<profit_l_r[i]<<" ";
	}cout<<endl;
	profit_r_l[n-1]=0;
	for(int i=n-2;i>=0;i--){
		profit_r_l[i]=max(profit_r_l[i+1],max_r_l[i+1]-price[i]);
		cout<<	profit_r_l[i]<<" ";
	}cout<<endl;
	int profitonetrade=0;
	for(int i=1;i<n;i++){
		profitonetrade=max(profitonetrade,profit_l_r[i]);
	}
	
	
	cout<<profitonetrade<<endl;
	int maxprofit=profitonetrade;
	for(int i=0;i<n-1;i++){
		maxprofit=max(maxprofit,profit_l_r[i]+profit_r_l[i+1]);
	}
	cout<<maxprofit<<endl;
	
}
