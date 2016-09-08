#include<iostream>
#include<list>
using namespace std;
class Graph{
	list<int> *adj;
	public:
	Graph(int V){
		adj=new list<int>[V];
	}
	void addEdge(int n,int m){
		adj[n].push_back(m);
	}
	void BFS(int start,int V){
		list<int> queue;
		int visited[V];
		for(int i=0;i<V;i++){
			visited[i]=0;
		}
		queue.push_back(start);
		visited[start]=1;
		while(!queue.empty()){
			int s=queue.front();
			cout<<s<<" ";
			queue.pop_front();
			list<int>::iterator i;
			for(i=adj[s].begin();i!=adj[s].end();i++){
				if(visited[*i]!=1){
					queue.push_back(*i);
					visited[*i]=1;
				}
				
			}
		}
	}
	void utility(int start,int visited[]){
		visited[start]=1;
		cout<<start<<" ";
		list<int>::iterator i;
		for(i=adj[start].begin();i!=adj[start].end();i++){
			if(visited[*i]!=1){
				utility(*i,visited);
			}
		}
	}
	void DFS(int start,int V){
		int visited[V];
		for(int i=0;i<V;i++){
			visited[i]=0;
		}
		utility(start,visited);
	}
	int cycleutil( int i,int visited[],int isinstack[],int V){
		if(visited[i]==0){
		
			    visited[i]=1;
				isinstack[i]=1;
				list<int>::iterator it;
				for(it=adj[i].begin();it!=adj[i].end();it++){
					if(cycleutil(*it,visited,isinstack,V)==1){
						return 1;
					}
					 
				}
				isinstack[i]=0;
			
		}
		else{
			if(isinstack[i]==1) return 1;
		}
	return 0;
	}
	void findcycle(int V){
		int visited[V],isinstack[V];
		for(int i=0;i<V;i++){
			visited[i]=0;
			isinstack[i]=0;
		}
		for(int i=0;i<V;i++){
			if(	cycleutil( i,visited,isinstack,V)==1){
				cout<<"cycle pesent"<<endl;
				return ;
			}
			 
		}
			cout<<"No cycle"<<endl;
	
	}
	int Pathutility(int start,int end,int visited[],int stack[],int &top){
		if(start==end){
			return 1;
		}
		else{ if(visited[start]==0){
				visited[start]=1;
				list<int>::iterator it;
				
				for(it=adj[start].begin();it!=adj[start].end();it++){
				stack[++top]=*it;	
				//cout<<top<<endl;
					if(Pathutility(*it,end,visited,stack,top)==1){
						return 1;
					}
					else
					{
						stack[top--]=0;
					}
					
				}
			}
			
			
		}
		return 0;
	}
	void pathfinding(int V,int start,int end){
		int visited[V],stack[V],top=-1;
		for(int i=0;i<V;i++){
			visited[i]=0;
		}
		stack[++top]=start;
		if(Pathutility(start,end,visited,stack,top)==1){
			cout<<"Path:"<<endl;
			for(int i=0;i<=top;i++){
				cout<<stack[i]<<" ";
			
			}
		}
		else{
			cout<<"No path present"<<endl;
		}
		
	}
	int topologyutil(int i,int visited[],int V,int stack[],int &top){
		
		visited[i]=1;
		list<int>:: iterator it;
		for(it=adj[i].begin();it!=adj[i].end();it++){
			if(visited[*it]==0){
				
				topologyutil(*it,visited,V,stack,top);
			}
		}
		stack[++top]=i;
		
	}
	void topological_sorting(int V){
		int visited[V];
		for(int i=0;i<V;i++){
			visited[i]=0;
		}
		int stack[V];
		int top=-1;
		for(int i=0;i<V;i++){
			if(visited[i]!=1){
				topologyutil(i,visited,V,stack,top);
			}
		}
		while(top!=-1){
			cout<<stack[top]<<" ";
			top--;
		}
	
	}
	int colorutil(int visited[],int color[],int start,int inicolor){
		visited[start]=1;
		color[start]=inicolor;
		list<int>::iterator it;
		for(it=adj[start].begin();it!=adj[start].end();it++){
			if(visited[*it]==0){
				colorutil(visited,color,*it,(inicolor+1)%2);
			}
			else if(inicolor==color[*it]){
				return 0;
			}
		}
		return 1;
	}
	void checkBipartite(int V){
		int visited[V];int color[V];
		for(int i=0;i<V;i++){
			visited[i]=0;
			color[i]=-1;
		}
		
		if(colorutil(visited,color,0,0)==1){
			cout<<"Bipartite Graph"<<endl;
		}
		else{
			cout<<"Not Bipartite"<<endl;
		}
		
		
	}
};
int main(){
	int V=6;
	Graph g(V);
 g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);
    g.BFS(2,V);
    cout<<endl;
    g.DFS(2,V);
    g.findcycle(V);
    g.pathfinding(V,2,1);
    cout<<endl;
    g.topological_sorting(V);
    cout<<endl;
    g.checkBipartite(V);
}
