#include<iostream>
using namespace std;
int main(){
	int V=4;
		int graph[V][V] = {{0, 10, 7, 6},
                     	   {10, 0, 8, 5},
                     	   {7, 8, 0, 12},
                     	   {6, 5, 12, 0},
                     };
            int current=1;
            int k=3;
            int distance[V];
            for(int i=0;i<V;i++){
				distance[i]=1000;
			} 
			cout<<current<<" ";
			for(int i=1;i<k;i++){
				distance[current]=0;
				
				for(int j=0;j<V;j++){
					int min=1000;
					if(distance[j]!=0){
						for(int k=0;k<V;k++){
							if(distance[k]==0){
								if(graph[j][k]!=0&&min>graph[j][k]){
									min=graph[j][k];
								}
							}
						}
			    	distance[j]=min;
					}
					
					
				}
				int max=0;
				int index;
				for(int p=0;p<V;p++)
				{if(distance[p]!=0&&max<distance[p]){
					max=distance[p];
					index=p;
				}
					
				}
				cout<<index<<" ";
				current=index;
			}         
                     
}
