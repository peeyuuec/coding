#include<iostream>
using namespace std;
int main(){
		int V=9;
 int graph[V][V] = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
                      {4, 0, 8, 0, 0, 0, 0, 11, 0},
                      {0, 8, 0, 7, 0, 4, 0, 0, 2},
                      {0, 0, 7, 0, 9, 14, 0, 0, 0},
                      {0, 0, 0, 9, 0, 10, 0, 0, 0},
                      {0, 0, 4, 0, 10, 0, 2, 0, 0},
                      {0, 0, 0, 14, 0, 2, 0, 1, 6},
                      {8, 11, 0, 0, 0, 0, 1, 0, 7},
                      {0, 0, 2, 0, 0, 0, 6, 7, 0}
                     };
    int Distance[V];
    int visited[V];
    int parent[V];
    for(int i=0;i<V;i++){
    	Distance[i]=1000;
    	visited[i]=0;
	}
	int current=0;
	Distance[current]=0;
	parent[current]=-1;
	for(int i=1;i<V;i++){
		visited[current]=1;
		for(int j=0;j<V;j++){
			if(visited[j]!=1&&graph[current][j]!=0){
				int dis=Distance[current]+graph[current][j];
				if(dis<Distance[j]){
					Distance[j]=dis;
						parent[j]=current;
				}
			}
		}
		int min=1000,minindex;
		for(int k=0;k<V;k++){
			if(visited[k]!=1){
				if(min>Distance[k]){
					min=Distance[k];
					minindex=k;
				
				}
			}
		}
		current=minindex;
		cout<<minindex<<endl;
	}
		for(int i=0;i<V;i++)
		cout<<parent[i]<<" ";
		cout<<endl;
	for(int i=0;i<V;i++)
	cout<<i<<": "<<Distance[i]<<endl;
}
