#include<iostream>
using namespace std;
#define N 8
int issafe(int i,int j){
	if(i<N&&i>=0&&j<N&&j>=0)return 1;
	return 0;
}
int knighttourUtil(int hor[],int ver[],int tour[N][N],int i,int j,int count){
	if(count==N*N-1){
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			cout<<tour[i][j]<<" ";
		}
		cout<<endl;
		
	}
	return 1;	
	}
	//cout<<i<<" "<<j<<" "<<count<<endl;
	for(int p=0;p<N;p++){
		if(issafe(i+hor[p],j+ver[p])==1&&tour[i+hor[p]][j+ver[p]]<0){
			tour[i+hor[p]][j+ver[p]]=count+1;
		if(knighttourUtil(hor,ver,	tour,i+hor[p],j+ver[p],count+1)==1){
			return 1;
		}
		else{
			tour[i+hor[p]][j+ver[p]]=-1;
		}
		}
	}
	return 0;
	
}
void knighttour(int hor[N],int ver[N]){
	int tour[N][N];
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			tour[i][j]=-1;
		}
	}
	tour[0][0]=0;
	clock_t t1,t2;
    t1=clock();
	cout<<knighttourUtil(hor,ver,tour,0,0,0);
	t2=clock();
    float diff ((float)t2-(float)t1);
    cout<<diff/CLOCKS_PER_SEC<<endl;
}
int main(){
	
	//int hor[]={2,2,-2,-2,-1,-1,1,1};
	//int ver[]={1,-1,1,-1,2,-2,2,-2};
	int hor[8] = {  2, 1, -1, -2, 2, -1,  1,  -2 };
    int ver[8] = {  1, 2,  2,  1, -1, -2, -2, -1 };
	knighttour(hor,ver);
}
