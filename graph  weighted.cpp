#include<iostream>
#include<list>
#define INT_MAX 100000
#define INT_MIN -100000
using namespace std;
struct data{
	int neighbour;
	int weight;
};
class Graph{
	list<data> *adj;
	public:
	Graph(int V){
		adj=new list<data>[V];
	}
	void addEdge(int n,int m,int w){
		data *dt=new data;
		dt->neighbour=m;
		dt->weight=w;
		adj[n].push_back(*dt);
	}
	
	void print(int i){
		list<data>::iterator it;
    for(it=adj[i].begin();it!=adj[i].end();it++){
    	cout<<(*it).weight<<" ";
	}
	}
	
	
	int topologicallistutil(int start,int V,int stack[],int &top,int visited[]){
		if(visited[start]==0){
			
		
		visited[start]=1;
		
		list<data>::iterator it;
		for(it=adj[start].begin();it!=adj[start].end();it++){
			if(visited[(*it).neighbour]==0){
				topologicallistutil((*it).neighbour,V,stack,top,visited);
			}
		}
		stack[++top]=start;
	}
	}
	void topologicallist(int V,int stack[],int &top){
		int visited[V];
		for(int i=0;i<V;i++){
			visited[i]=0;
		}
		for(int i=0;i<V;i++){
			topologicallistutil(i,V,stack,top,visited);
		}
		cout<<top<<endl;
		for(int i=0;i<=top;i++){
			cout<<stack[i]<<" ";
		}
		cout<<endl;
	}
	void shortestpathutil(int V,int visited[],int start){
		int stack[V];
		int top=-1;
		topologicallist(V,stack,top);
		int length[V];
		for(int i=0;i<V;i++){
			length[i]=INT_MAX;
		}
		length[start]=0;
		while(top!=-1){
			int node=stack[top];
			top--;
			list<data>::iterator it;
			for(it=adj[node].begin();it!=adj[node].end();it++){
				if(length[(*it).neighbour]>length[node]+(*it).weight){
				length[(*it).neighbour]=length[node]+(*it).weight;
				}
			}
		}
		cout<<endl;
		for(int i=0;i<V;i++){
			cout<<length[i]<<" ";
		}
	}
	void shortestlength(int V){
		int visited[V];
		for(int i=0;i<V;i++){
			visited[i]=0;
		}
		shortestpathutil(V,visited,1);
	}
		void longestpathutil(int V,int visited[],int start){
		int stack[V];
		int top=-1;
		topologicallist(V,stack,top);
		int length[V];
		for(int i=0;i<V;i++){
			length[i]=INT_MIN;
		}
		length[start]=0;
		while(top!=-1){
			int node=stack[top];
			top--;
			list<data>::iterator it;
			for(it=adj[node].begin();it!=adj[node].end();it++){
				if(length[(*it).neighbour]<length[node]+(*it).weight){
				length[(*it).neighbour]=length[node]+(*it).weight;
				}
			}
		}
		cout<<endl;
		for(int i=0;i<V;i++){
			cout<<length[i]<<" ";
		}
	}
	void longestlength(int V){
		int visited[V];
		for(int i=0;i<V;i++){
			visited[i]=0;
		}
		longestpathutil(V,visited,1);
	}
};
int main(){
		int V=6;
	Graph g(V);
 	g.addEdge(0, 1, 5);
    g.addEdge(0, 2, 3);
    g.addEdge(1, 3, 6);
    g.addEdge(1, 2, 2);
    g.addEdge(2, 4, 4);
    g.addEdge(2, 5, 2);
    g.addEdge(2, 3, 7);
    g.addEdge(3, 5, 1);
    g.addEdge(3, 4, -1);
    g.addEdge(4, 5, -2);
    
    //g.print(0);
    g.shortestlength(V);
    cout<<endl;
    g.longestlength(V);
}
