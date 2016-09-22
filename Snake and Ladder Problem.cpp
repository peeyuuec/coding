#include<iostream>
#include<list>

using namespace std;
#define INT_MAX 10000
struct data{
	int id;
	int weight;
};
class Graph{
	list<data> *adj;
	public:
	Graph(int V){
		adj=new list<data>[V];
	}
	void addEdge(int n,int m,int weight){
		data newdata;
		newdata.id=m;
		newdata.weight=weight;
		adj[n].push_back(newdata);
	}
	void creategraph(int moves[],int V){
	 
	int dice=6;
	for(int i=0;i<V;i++){
		for(int j=1;j<=dice;j++){
			if(i+j<30&&moves[i]==-1){
				
			if(moves[i+j]==-1){
				addEdge(i,i+j,1);
			}else{
				addEdge(i,moves[i+j],1);
			}	
			}
			
		}
	}
	for(int i=0;i<V;i++){
		cout<<i<<":";
			list<data>::iterator it;
	for(it=adj[i].begin();it!=adj[i].end();it++){
		cout<<(*it).id<<" ";
	}
	cout<<endl;
	}
	
}
int topologicalsortutil(int visited[],int V,int stack[],int &top,int i){
	cout<<"A"<<endl;
	if(visited[i]==0){
		
			visited[i]=1;
	list<data>::iterator it;
	for(it=adj[i].begin();it!=adj[i].end();it++){
		if(visited[(*it).id]==0){
			topologicalsortutil(visited,V,stack,top,(*it).id);
		}
	}
	stack[++top]=i;
	}

}
void topologicalsort(int V,int stack[],int &top){
	int visited[V];
	for(int i=0;i<V;i++){
		visited[i]=0;
	}
	for(int i=0;i<V;i++){
		topologicalsortutil(visited,V,stack,top,i);
	}
 
	
}
void shortestpathutil(int V,int start,int distance[]){
	int stack[V];
	int top=-1;
	topologicalsort(V,stack,top);
	
while(top!=-1){
	int node=stack[top];
	top--;
	list<data>::iterator it;
	for(it=adj[node].begin();it!=adj[node].end();it++){
		if(distance[(*it).id]>distance[node]+(*it).weight){
			distance[(*it).id]=distance[node]+(*it).weight;
		}
	}
}
}
void shortestpath(int V,int start){
	int distance[V];
	for(int i=0;i<V;i++){
		distance[i]=INT_MAX;
	}
	distance[start]=0;
	shortestpathutil(V,start,distance);
	for(int i=0;i<V;i++){
	cout<<	i<<"	";
	}
	cout<<endl;
   for(int i=0;i<V;i++){
	cout<<	distance[i]<<"	";
	}
}
};


int main(){

	int N = 30;
		Graph g(N);
    int moves[N];
    for (int i = 0; i<N; i++)
        moves[i] = -1;
 
    // Ladders
    moves[2] = 21;
    moves[4] = 7;
    moves[10] = 25;
    moves[19] = 28;
 
    // Snakes
    moves[26] = 0;
    moves[20] = 8;
    moves[16] = 3;
    moves[18] = 6;
    g.creategraph(moves,30);
    g.shortestpath(N,0);
}
