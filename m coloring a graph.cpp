#include<iostream>
using namespace std;
#define V 4
int issafe(int graph[V][V],int color,int index,int result[]){
	for(int i=0;i<V;i++){
	 
		if(graph[index][i]==1){
			if(result[i]==color){
 
				return 0;
			}
		}
	}
 
	return 1;
}
int utility(int graph[V][V],int m,int colors[],int result[],int index){
	if(index==V){
		for(int i=0;i<V;i++){
			cout<<result[i]<<" ";
			
		}
		cout<<endl;
		return 1;
	}
	for(int i=0;i<m;i++){
		
		if(issafe(graph,colors[i],index,result)==1){
			
			result[index]=colors[i];
		//cout<<index<<" ";
			utility(graph,m,colors,result,index+1);
			return 1;
		}
		else{
				result[index]=-1;
		}
	}
}
void coloring(int graph[V][V],int m){
	int colors[m];
	for(int i=0;i<m;i++){
		colors[i]=i;
	}
	int result[V];
	for(int i=0;i<V;i++){
		result[i]=-1;
	}
	utility(graph,m,colors,result,0);
}
int main(){
	int graph[V][V] = {{0, 1, 1, 1},
				        {1, 0, 1, 0},
				        {1, 1, 0, 1},
				        {1, 0, 1, 0},
    };
    int m=3;
    coloring(graph,m);
}
