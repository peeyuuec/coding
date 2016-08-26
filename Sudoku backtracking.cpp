#include<iostream>
using namespace std;
#define N 9
#define M 3
int issafe(int grid[N][N],int x,int y,int val){
	for(int i=0;i<N;i++){
		if(grid[x][i]==val||grid[i][y]==val)return 0;
	}
	return 1;
}
utility(int grid[N][N],int i,int j,int originx,int originy,int count,int intercellcount){
//cout<<count<<" ";
	if(count==44){
			for(int p=0;p<N;p++){
		for(int q=0;q<N;q++){
			cout<<grid[p][q]<<" ";
		}
		cout<<endl;
	}
	}
	int present[N+1];

		
	for(int x=0;x<N;x=x+M){
		for(int y=0;y<N;y=y+M){
			
							for(int l=0;l<N+1;l++){
								present[l]=0;
									}
	
							for(int p=0;p<M;p++){
								for(int q=0;q<M;q++){
									if(grid[x+p][y+q]>0){
										intercellcount++;
										present[grid[x+p][y+q]]=1;
									}
								}
							}
							for(int l=1;l<N+1;l++){
								cout<<present[l]<<" ";
									}cout<<endl;
				for(int p=0;p<M;p++){
					for(int q=0;q<M;q++){
			for(int z=1;z<=9;z++){
				if(present[z]==0&&grid[x+p][y+q]==0&&issafe(grid,x+p,y+q,z)==1){
					grid[x+p][y+q]=z;
					present[z]=1;
					/*if(utility( grid, i, j, x, y, count+1, intercellcount+1)==1){
						
						return 1;
					}
					else{
						grid[p+x][q+y]=0;
						present[z]=0;
					}*/
				}
			}
			
										}
									}
								}
								
							}
							for(int p=0;p<N;p++){
		for(int q=0;q<N;q++){
			cout<<grid[p][q]<<" ";
		}
		cout<<endl;
	}
 

}
void sudoko(int grid[N][N],int count,int intercellcount){
	utility(grid,0,0,0,0,count, intercellcount);
}
int main(){
	 int grid[N][N] = {{3, 0, 6, 5, 0, 8, 4, 0, 0},
                      {5, 2, 0, 0, 0, 0, 0, 0, 0},
                      {0, 8, 7, 0, 0, 0, 0, 3, 1},
                      {0, 0, 3, 0, 1, 0, 0, 8, 0},
                      {9, 0, 0, 8, 6, 3, 0, 0, 5},
                      {0, 5, 0, 0, 9, 0, 6, 0, 0},
                      {1, 3, 0, 0, 0, 0, 2, 5, 0},
                      {0, 0, 0, 0, 0, 0, 0, 7, 4},
                      {0, 0, 5 , 2, 0, 6, 3, 0, 0}};
            int count=0;
        for(int p=0;p<N;p++){
		for(int q=0;q<N;q++){
			if(grid[p][q]>0)count++;
		}
	}
 
                      sudoko(grid,count,6);
}
