#include<iostream>
using namespace std;
#define INF 1000
int main(){
	int V=4;
	
	 int graph[V][V] = { {0,   5,  INF, 10},
                        {INF, 0,   3, INF},
                        {INF, INF, 0,   1},
                        {INF, INF, INF, 0}
                      };
                      
    for(int i=0;i<V;i++){
    	for(int j=0;j<V;j++){
    		for(int k=0;k<V;k++){
    			if(graph[i][j]>graph[i][k]+graph[k][j]){
    				graph[i][j]=graph[i][k]+graph[k][j];
				}
			}
		}
	}
	for(int i=0;i<V;i++)
	{
		for(int j=0;j<V;j++){
			cout<<graph[i][j]<<" ";
		}
		cout<<endl;
	}
}
