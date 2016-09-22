#include<iostream>
#include<list>
using namespace std;
int min(int a,int b){
	return a<b?a:b;
}
struct node{
	int id;
	int w;
};
int t=0;
class graph{
	list<node> *adj;
	public:
		graph(int V){
			adj=new list<node>[V];
		}
		addEdge(int n,int m,int w){
			node newnode;
			newnode.id=m;
			newnode.w=w;
			adj[n].push_back(newnode);
			node newnode2;
			newnode2.id=n;
			newnode2.w=w;
			adj[m].push_back(newnode2);
		}
		int utility(list<node>*adj,int V,int visited[],int start,int low[],int dis[],int parent[],int result[]){
			visited[start]=1;
			dis[start]=t;
			low[start]=t++;
			cout<<t<<endl;
			list<node>::iterator itr;
			int children=0;
			for(itr=adj[start].begin();itr!=adj[start].end();itr++){
				cout<<"a";
				int neig=(*itr).id;
				if(visited[neig]==0){
					
					
					parent[neig]=start;
					children++;
					if(utility(adj,V,visited,neig,low,dis,parent,result)==1)
					{
						return 1;
					}
					if(parent[start]==-1&&children>=2){
						cout<<"point$ :"<<start<<endl;
						result[start]=1;
						//return 1;
					}
					if(parent[start]!=-1&&low[neig]>=low[start]){
						cout<<"point# :"<<start<<endl;
						result[start]=1;
						//return 1;
					}
					low[start]=min(low[start],low[neig]);
				}
				else{
					if(parent[start]!=neig){
						low[start]=min(low[start],dis[neig]);
					}
					
				}
			}
			return 0;
		}
	void	Arti(int V){
			int visited[V];
			memset(visited,0,V*sizeof(int));
			int dis[V];
			int low[V];
			int parent[V];
			parent[0]=-1;
			int result[V];
			memset(result,0,V*sizeof(V));
			if(utility(adj,V,visited,0,low,dis,parent,result)==1)cout<<"Point Present"<<endl;
			else{ cout<<"No point"<<endl;
			}
		}
		void printlist(int V){
			list<node>::iterator itr;
			for(int i=0;i<V;i++){
				cout<<i<<" :";
				for(itr=adj[i].begin();itr!=adj[i].end();itr++){
				cout<<(*itr).id<<" ";
			}	
			cout<<endl;
			}
		
		}
};
int main(){
	graph g1(5);
    g1.addEdge(1, 0,1);
    g1.addEdge(0, 2,1);
    g1.addEdge(2, 1,1);
    g1.addEdge(0, 3,1);
    g1.addEdge(3, 4,1);
    g1.Arti(5);
    //g1.printlist(5);
    graph g2(4);
    g2.addEdge(0, 1,1);
    g2.addEdge(1, 2,1);
    g2.addEdge(2, 3,1);
    g2.Arti(4);
    
    graph g3(7);
    g3.addEdge(0, 1,1);
    g3.addEdge(1, 2,1);
    g3.addEdge(2, 0,1);
    g3.addEdge(1, 3,1);
    g3.addEdge(1, 4,1);
    g3.addEdge(1, 6,1);
    g3.addEdge(3, 5,1);
    g3.addEdge(4, 5,1);
    g3.Arti(7);
}
