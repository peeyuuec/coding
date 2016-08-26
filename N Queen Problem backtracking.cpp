#include<iostream>
using namespace std;
#define N 4
int issafe(int i,int j){
	if(i<N&&i>=0&&j<N&&j>=0)return 1;
	return 0;
}
int notaround(int queen[N][N],int p,int q){
	int aroundx[]={1,1,0,-1,-1,-1,0,1};
	int aroundy[]={0,1,1,1,0,-1,-1,-1};
	for(int i=0;i<8;i++){
		if(issafe(p+aroundx[i],q+aroundy[i])==1&&queen[p+aroundx[i]][q+aroundy[i]]==1){
			return 0;
		}
	}
	return 1;
}
int utility(int x[],int y[],int queen[N][N],int i,int j,int count){
	
	if(count==0){
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
		cout<<queen[i][j]<<" ";
		}
		cout<<endl;
	}
	return 1;	
	}
	for(int p=0;p<16;p++){
		if(issafe(i+x[p],j+y[p])&&queen[i+x[p]][j+y[p]]!=1&&notaround(queen,i+x[p],j+y[p])==1){
			queen[i+x[p]][j+y[p]]=1;
		if(utility(x,y,queen,i+x[p],j+y[p],count-1)==1){
			return 1;
		}
		else{
			queen[i+x[p]][j+y[p]]=0;
		}
		}
	}
	return 0;
	
}
void placequeen(int x[],int y[]){
		int queen[N][N];
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			queen[i][j]=0;
		}
	}
	queen[0][0]=1;
	utility(x,y,queen,0,0,N-1);
}
int main(){
	int x[]={2,2,2,1,0,-1,-2,-2,-2,-2,-2,-1,0,1,2,2};
	int y[]={0,1,2,2,2,2,2,1,0,-1,-2,-2,-2,-2,-2,-1};

	placequeen(x,y);
}
