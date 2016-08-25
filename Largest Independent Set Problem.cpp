#include<iostream>
using namespace std;
int maxset(int graph[9][9],int available[],int n,int V){
		if(n<=0)return 0;
		int max=0;
		for(int i=0;i<V;i++){
			if(available[i]==1){
				int temp[V];
				for(int i=0;i<V;i++){
					temp[i]=available[i];
				}
				available[i]=0;
				for(int j=0;j<V;j++){
					if(graph[i][j]>0){
		
						available[j]=0;
					}
				}
				n=0;
				for(int i=0;i<V;i++){
					
					n+=available[i];
					cout<<available[i]<<" ";
				}
				cout<<endl;
				//cout<<i<<" "<<n<<endl;
				int t=1+maxset(graph,available,n,V);
				if(t>max){
					
					max=t;
				}
				for(int i=0;i<V;i++){
					available[i]=temp[i];
				}
			}
		}
		return max;	
	
}
int main(){
	int V=8;
	//int graph[8][8]={{0,1,1,0,0,0,0,0},{1,0,0,1,1,0,0,0},{1,0,0,0,0,1,0,0},
	//				 {0,1,0,0,0,0,0,0},{0,1,0,0,0,0,1,1},{0,0,1,0,0,0,0,0},
	//				 {0,0,0,0,1,0,0,0},{0,0,0,0,1,0,0,0}};
	  V=9;
   int graph[9][9] = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
                      {4, 0, 8, 0, 0, 0, 0, 11, 0},
                      {0, 8, 0, 7, 0, 4, 0, 0, 2},
                      {0, 0, 7, 0, 9, 14, 0, 0, 0},
                      {0, 0, 0, 9, 0, 10, 0, 0, 0},
                      {0, 0, 4, 0, 10, 0, 2, 0, 0},
                      {0, 0, 0, 14, 0, 2, 0, 1, 6},
                      {8, 11, 0, 0, 0, 0, 1, 0, 7},
                      {0, 0, 2, 0, 0, 0, 6, 7, 0}
                     };
int available[V]={1,1,1,1,1,1,1,1,1};
cout<<maxset(graph,available,V,V);
}
