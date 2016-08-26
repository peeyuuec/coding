#include<iostream>
using namespace std;
#define V 4
int utility(int graph[V][V],int x[V],int y[V],int result[V],int i,int count){
	if(count==V){
		for(int p=0;p<V;p++){
			if(graph[0][p]==1&&result[p]==count-1){
	            for(int k=0;k<V;k++){
	            	cout<<result[k]<<" ";
				}
				return 1;
			}
		}
		return 0;
	}
	for(int l=0;l<V;l++){
		
		if(graph[i][l]==1&&result[l]<0){
				result[l]=count;
			if(utility(graph,x,y,result,l,count+1)==1){
				return 1;
			}	else{
			result[l]=-1;
		}
		}
	
	}
	
}
void hamiltoncycle(int graph[V][V],int x[V],int y[V]){
	int result[V];
	
		for(int j=0;j<V;j++){
			result[j]=-1;
		}
	result[0]=0;
	utility(graph,x,y,result,0,1);
}
int main(){
	int x[]={1,1,0,-1,-1,-1,0,1};
	int y[]={0,1,1,1,0,-1,-1,-1};
		   	int graph[V][V] = {{0, 1, 1, 1},
				        {1, 0, 1, 0},
				        {1, 1, 0, 1},
				        {1, 0, 1, 0},
    };
	hamiltoncycle(graph,x,y);
}
