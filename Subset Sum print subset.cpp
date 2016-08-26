#include<iostream>
using namespace std;
int utility(int weight[],int target,int n,int subset[],int size,int sum,int index){
	if(sum>target||index>=n)return 0;
	if(sum==target){
		for(int i=0;i<size;i++){
			cout<<subset[i]<<" ";
		}
		return 1;
	}
	for(int i=index;i<n;i++){
		
		subset[size]=weight[i];
	if(utility(weight,target,n,subset,size+1,sum+weight[i],i+1)==1){
		return 1;
	}
	else{
			subset[size]=-1;
	}
	}
	
}
void findsubset(int weight[],int target,int n){
	int subset[n];
	int size=0;
	utility(weight,target,n,subset,size,0,0);
}
int main(){
	int weights[] = {10, 7, 5, 18, 12, 20, 15};
    int target = 35;
    int n=8;
    findsubset(weights,target,n);
}
