#include<iostream>
#include<math.h>
using namespace std;
double distance(int points[][2],int a,int b){
    double pointa_b_x=(points[a][0]-points[b][0])*(points[a][0]-points[b][0]);
    double pointa_b_y=(points[a][1]-points[b][1])*(points[a][1]-points[b][1]);
	return sqrt(pointa_b_x+pointa_b_y);
}
double curcumference(int points[][2],int i,int k,int index2){
	cout<<distance(points,i,k)+distance(points,k,index2)+distance(points,index2,i)<<endl;
	return (distance(points,i,k)+distance(points,k,index2)+distance(points,index2,i));
}
double triangulation(int points[][2],int n){
	double cost[n][n];
	for(int i=0;i<n-1;i++){
		cost[i][i]=0.0;
		cost[i][i+1]=0.0;
	}
	cost[n-1][n-1]=0.0;
	for(int gap=2;gap<=n-1;gap++){
		int index1=n-gap;
		for(int i=0;i<index1;i++){
			int index2=i+gap;
			double min=1000;
			for(int k=i+1;k<index2;k++){
				double temp=cost[i][k]+cost[k][index2]+curcumference(points,i,k,index2);
				if(temp<min){
					min=temp;
				}
				cost[i][index2]=min;
			}
		}
	}
	return cost[0][n-1];
}
int main(){
	int  points[][2] = {{0, 0}, {1, 0}, {2, 1}, {1, 2}, {0, 2}};
    int n = 5;
    cout<<triangulation(points,n)<<endl;
    cout<<curcumference(points,0,1,2);
}
