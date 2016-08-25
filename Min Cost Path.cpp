#include<iostream>
using namespace std;
int min(int a,int b,int c){
	if(a<b){
		 return c<a?c:a;
	}
	else{
		return b<c?b:c;
	}
}
int main()
{
	int R=3,C=3;
	int matrix[R][C] = { {1, 2, 3},
                      {4, 8, 2},
                      {1, 5, 3} };

int cost[R][C];
cost[0][0]=matrix[0][0];
for(int i=1;i<R;i++){
	cost[i][0]=cost[i-1][0]+matrix[i][0];
}

for(int i=1;i<C;i++){
	cost[0][i]=cost[0][i-1]+matrix[0][i];
	
}

for(int i=1;i<R;i++){
	for(int j=1;j<C;j++){
		
		cost[i][j]=matrix[i][j]+min(cost[i-1][j],cost[i][j-1],cost[i-1][j-1]);
	}
}

for(int i=0;i<R;i++){
	for(int j=0;j<C;j++){
		
		cout<<cost[i][j]<<" ";
	}
	cout<<endl;
}
}
