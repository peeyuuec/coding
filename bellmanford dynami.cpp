#include<iostream>
using namespace std;
int bellmanford(int a[][3],int V,int E,int result[]){

	for(int i=0;i<V;i++){
		result[i]=1000;
	}
	result[0]=0;
	for(int i=0;i<V;i++){
		for(int j=0;j<E;j++){
			if(result[a[j][1]]>result[a[j][0]]+a[j][2]){
				result[a[j][1]]=result[a[j][0]]+a[j][2];
			}
		}
	}
}
int main(){
	int V=5;
	int E=5;
	int a[5][3]={{0,1,4},{0,3,2},{1,3,3},{2,3,2},{3,4,1}};
	int result[V];
	bellmanford(a,V,E,result);
	for(int i=0;i<V;i++){
		cout<<result[i]<<" ";
	}
}
