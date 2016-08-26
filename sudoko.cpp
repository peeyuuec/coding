#include<iostream>
using namespace std;
#define N 9
#define M 3
int issafe(int grid[N][N],int x,int y,int val){
	for(int i=0;i<N;i++){
		//cout<<grid[x][i]<<" "<<grid[i][y]<<" "<<val<<endl;
		if(grid[x][i]==val||grid[i][y]==val){
		//cout<<x<<" "<<y<<" "<<val<<" "<<grid[x][i]<<" "<<grid[i][y]<<" "<<val<<endl;
		return 0;	
		}
	}
	return 1;
}
int getnext(int grid[N][N],int &a,int &b,int present[]){
	for(int x=0;x<N;x=x+M){
		for(int y=0;y<N;y=y+M){
			for(int p=0;p<M;p++){
				for(int q=0;q<M;q++){
								if(grid[x+p][y+q]==0){
									a=x+p;
									b=y+q;
									for(int p=0;p<M;p++){
									for(int q=0;q<M;q++){
										
										if(grid[x+p][y+q]>0){
											
											present[grid[x+p][y+q]]=1;
										}
								}
							}
							//cout<<a<<" "<<b<<" ";
							return 1;	
								}
								
								}}
			
		}
	}
	return 0;
}
utility(int grid[N][N],int i,int j,int originx,int originy,int count,int intercellcount){

	int x,y;
	int present[N];
	for(int l=1;l<N+1;l++){
								present[l]=0;
	}
        int c=getnext(grid,x,y,present);
        //cout<<c<<" ";
		if(c==0) {
							for(int p=0;p<N;p++){
					for(int q=0;q<N;q++){
						cout<<grid[p][q]<<"|";
					}
					cout<<endl;
				}
			return 1; 
		}
        for(int s=1;s<=N;s++){
        	if(present[s]==0){
        		//cout<<"a";
        		
        		//cout<<x<<" "<<y<<" "<<s<<endl;;
        		if(issafe(grid,x,y,s)==1){
        			
				grid[x][y]=s;
        
				for(int p=0;p<N;p++){
					for(int q=0;q<N;q++){
					//	cout<<grid[p][q]<<" ";
					}
					//cout<<endl;
					}
					//cout<<endl;
				
        		if(utility(grid,i,j,originx,originy,count,intercellcount)==1){
					return 1;
				}
				else{
					grid[x][y]=0;
					
				}
			}
		}}
   return 0;

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
                      {0, 0, 5, 2, 0, 6, 3, 0, 0}};
            int count=0;
        for(int p=0;p<N;p++){
		for(int q=0;q<N;q++){
			if(grid[p][q]>0)count++;
		}
	}
 
                      sudoko(grid,count,6);
}
