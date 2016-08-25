#include<iostream>
using namespace std;
struct Edge{
	int x,y,weight;
};
struct graph{
	int E,V;
	struct Edge* edge;
	
};

graph* createGraph(int E,int V){
	struct graph *G=new graph;
	G->E=E;
	G->V=V;
	G->edge=(struct Edge*)malloc(G->E*sizeof(struct Edge));
	return G;
}
void add(graph* graph,int x,int y,int i,int weight){
	graph->edge[i].x=x;
	graph->edge[i].y=y;
	graph->edge[i].weight=weight;
}
int find(int *array,int x){
	while(array[x]!=-1){
		x=array[x];
	}
	return x;
}
int Union(int *array,int x,int y){
	x=find(array,x);
	y=find(array,y);
	array[x]=y;
}
int iscycle(graph* G){
	int E=G->E;
	int V=G->V;
		int array[E];
		for(int i=0;i<E;i++)
		array[i]=-1;
	for(int i=0;i<E;i++){
		if(find(array,G->edge[i].x)==find(array,G->edge[i].y)){
			cout<<"cycle present"<<endl;
		return 0;
		}
		int g1=find(array,G->edge[i].x);
		int g2=find(array,G->edge[i].y);
		Union(array,g1,g2);
	}
	return 1;
}
void kruskalMST(graph *G){
		int E=G->E;
	int V=G->V;
		int array[E];
		for(int i=0;i<E;i++)
		array[i]=-1;
		for(int i=0;i<E;i++){
			for(int j=0;j<E-1;j++){
				if(G->edge[j].weight>G->edge[j+1].weight){
					int temp=G->edge[j].weight;
					G->edge[j].weight=G->edge[j+1].weight;
					G->edge[j+1].weight=temp;
					
					temp=G->edge[j].x;
					G->edge[j].x=G->edge[j+1].x;
					G->edge[j+1].weight=temp;
					
					 temp=G->edge[j].y;
					G->edge[j].y=G->edge[j+1].y;
					G->edge[j+1].y=temp;
				}
			}
		}
			for(int i=0;i<E;i++){
		if(find(array,G->edge[i].x)!=find(array,G->edge[i].y)){
		int g1=find(array,G->edge[i].x);
		int g2=find(array,G->edge[i].y);
		Union(array,g1,g2);
		cout<<"x:"<<G->edge[i].x<<" "<<"y:"<<G->edge[i].y<<endl;
		}
		
	}
		
}
int main(){
	 int V = 3, E = 3;
	graph* G=createGraph(E,V);
	
	add(G,0,1,0,3);
	add(G,1,2,1,1);
	add(G,0,2,2,1);

	iscycle(G);
	kruskalMST(G);
}
