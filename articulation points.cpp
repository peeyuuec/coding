#include<iostream>
#include<list>
#define INT_MAX 100000
#define INT_MIN -100000
using namespace std;
int min(int a,int b){
	return a<b?a:b;
}
struct data{
	int id;
	int weight;
};
struct listdata{
	int u;
	int v;
};
class Graph{
	list<data> *adj;
	public:
	Graph(int V){
		adj=new list<data>[V];
	}
	void addEdge(int n,int m,int w){
		data *dt=new data;
		dt->id=m;
		dt->weight=w;
		adj[n].push_back(*dt);
		
	}
	
	void print(int i){
		list<data>::iterator it;
    for(it=adj[i].begin();it!=adj[i].end();it++){
    	cout<<(*it).weight<<" ";
	}
	}
int articulationutil(int visited[],int V,int u,list<listdata> *lst,int &time,int disc[],int low[],int parent[],list<int> *articulation){
	//cout<<u<<endl;
	int children=0;
	disc[u]=++time;
	low[u]=time;
	list<data>::iterator it;
	visited[u]=1;
	for(it=adj[u].begin();it!=adj[u].end();it++){
		int v=(*it).id;
		if(visited[v]==0){
			if(u==0){
				//cout<<v<<" ";
			}
			parent[v]=u;
			children++;
			listdata lsdt;
			lsdt.v=v;
			lsdt.u=u;
			lst->push_back(lsdt);
			if(articulationutil(visited,V,v,lst,time,disc,low,parent,articulation)==1){
			return 1;
			}
			if((parent[u]==-1&&children>1)||(parent[u]!=-1&&low[v]>=disc[u])){
				articulation->push_back(u);
				cout<<children<<endl;
			}
			
			low[u]=min(low[u],low[v]);
		}
		else{
			if(v!=parent[u]){
				low[u]=min(low[u],disc[v]);
			}
		}
		
	}
	return 0;
}	
	void articulationpoints(int V){
		int visited[V];
		int disc[V];
		int low[V];
		int parent[V];
		for(int i=0;i<V;i++){
			visited[i]=0;
			disc[i]=INT_MAX;
			low[i]=INT_MAX;
			parent[i]=-1;
		}
		list<listdata> *lst=new list<listdata>[V*V];
		list<int>*articulation=new list<int>[V];
		int time=0;
		
		for(int i=0;i<V;i++){
			if(visited[i]==0){
				articulationutil(visited,V,i,lst,time,disc,low,parent,articulation);
			}
		}
		list<int >::iterator arti;
		cout<<endl;
		for(arti=articulation->begin();arti!=articulation->end();arti++){
			cout<<*arti<<" ";
		}
	}
};

int main(){
		int V=8;
	Graph g(V);
 	g.addEdge(0, 1, 1);
 	g.addEdge(1, 0, 1);
    g.addEdge(0, 2, 1);
    g.addEdge(2, 0, 1);
    g.addEdge(1, 2, 1);
    g.addEdge(2, 1, 1);
    g.addEdge(2, 3, 1);
    g.addEdge(3, 2, 1);
    g.addEdge(3, 4, 1);
    g.addEdge(4, 3, 1);
    g.addEdge(4, 5, 1);
    g.addEdge(5, 4, 1);
    g.addEdge(5, 6, 1);
    g.addEdge(6, 5, 1);
    g.addEdge(4, 6, 1);
    g.addEdge(6, 4, 1);
    g.addEdge(5, 7, 1);
    g.addEdge(7, 5, 1);
    g.print(2);
    g.articulationpoints(V);
    
}
