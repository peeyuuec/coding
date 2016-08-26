#include<iostream>
using namespace std;
#define N 4
int issafe(int i,int j){
	if(i<N&&i>=0&&j<N&&j>=0)return 1;
	return 0;
}
int solveMazeUtil(int maze[N][N],int sol[N][N],int n,int i,int j){
	if(i==N-1&&j==N-1){
		for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			cout<<sol[i][j]<<" ";
		}
		cout<<endl;
	}
	return 1;
	}
	
	if(issafe(i+1,j)==1&&maze[i+1][j]!=0){
		sol[i+1][j]=1;
		if(solveMazeUtil(maze,sol,n, i+1, j)==1){
			return 1;
		}
		else{
			sol[i+1][j]=0;
		}
	}
	if(issafe(i,j+1)==1&&maze[i][j+1]!=0){
		sol[i][j+1]=1;
		if(solveMazeUtil(maze,sol,n, i, j+1)==1){
			return 1;
		}
		else{
			sol[i][j+1]=0;
		}
	}
	
}
void solveMaze(int maze[N][N]){
	int sol[N][N];
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			sol[i][j]=0;
		}
	}
	solveMazeUtil(maze,sol,N,0,0);
}
int main(){
	 int maze[N][N]  =  { {1, 0, 0, 0},
					        {1, 1, 0, 1},
					        {1, 1, 0, 0},
					        {1, 1, 1, 1}
    };
 
    solveMaze(maze);
}
