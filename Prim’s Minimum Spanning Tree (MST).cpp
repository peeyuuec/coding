#include<iostream>
using namespace std;
int main(){
	int V=5;
	
	int graph[V][V] = {{0, 2, 0, 6, 0},
                      {2, 0, 3, 8, 5},
                      {0, 3, 0, 0, 7},
                      {6, 8, 0, 0, 9},
                      {0, 5, 7, 9, 0},
                     };
    int Array[V];
    int startingVertex=0;
    int visited[V];
    for(int i=0;i<V;i++){
    	Array[i]=1000;
    	visited[i]=0;
	}
	Array[startingVertex]=0;
	
	int current=startingVertex;
	int next=startingVertex;
	
	int pair[V];
	
	for(int i=1;i<V;i++){
		
		current=next;
		
		visited[current]=1;
		for(int k=0;k<V;k++){
			if(visited[k]!=1&&graph[current][k]!=0){
				if(graph[current][k]<Array[k]){
					Array[k]=graph[current][k];
						pair[k]=current;
				}
			}
		}
				
				int min=1000;
		for(int j=0;j<V;j++){
			if(visited[j]!=1){
				if(min>Array[j]){
					min=Array[j];
					next=j;
				}
			}
		}
		
		cout<<"x:"<<pair[next]<<" "<<"y:"<<next<<" "<<"weight:"<<graph[pair[next]][next]<<endl;
		
	}
	
	
}
