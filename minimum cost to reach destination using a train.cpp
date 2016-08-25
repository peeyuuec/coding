#include<iostream>
using namespace std;
#define INF 10000
int min(int a,int b){
	return a>b?b:a;
}
int main(){
	int N=4;
	int ticket[N][N] = {  {0, 15, 80, 90},
            			  {INF, 0, 40, 50},
			              {INF, INF, 0, 70},
			              {INF, INF, INF, 0}
             };
             
    int cost[N+1];
    cost[1]=0;
    for(int i=2;i<=N;i++){
    	cost[i]=INF;
    	for(int j=1;j<i;j++){
    		cost[i]=min(cost[i],cost[j]+ticket[j-1][i-1]);
		}
	}
	cout<<cost[N]<<endl;
}
