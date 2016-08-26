#include<iostream>
using namespace std;

int utility(int arr[],int n,int included[],int set1,int set2,int maxset1,int maxset2,int &min,int result[]){
	
	if(set1==maxset1&&set2==maxset2){
		int sum1=0,sum2=0;
		for(int i=0;i<n;i++)
		{//cout<<included[i]<<" ";
			if(included[i]==1){
				sum1+=arr[i];
			}
			if(included[i]==2){
				sum2+=arr[i];
			}
			
		}
		int temp=sum1>sum2?(sum1-sum2):(sum2-sum1);
	      if(min>temp){
	      	min=temp;
	      	for(int i=0;i<n;i++){
	      		result[i]=included[i];
			  }
		  }
	      return min;
	}
	
	for(int i=0;i<n;i++){
		if(included[i]!=1){
			included[i]=1;
			utility(arr,n,included,set1+1,set2-1,maxset1,maxset2,min,result);
			included[i]=2;
		}
	}
	
}
void divide(int arr[],int n){
	int a,b;
	if(n%2==0){
		a=n/2;
		b=n/2;
	}
	else{
		a=(n-1)/2;
		b=(n+1)/2;
	}
	int min=10000;
	int included[n];
	for(int i=0;i<n;i++)
	included[i]=2;
	int set1[a],set2[b];
	int result[n];
	utility(arr,n,included,0,n,a,b,min,result);
	cout<<min<<endl;
	for(int i=0;i<n;i++){
		cout<<result[i]<<" ";
	}
}
int main(){
	int arr[] = {23, 45, -34, 12, 0, 98, -99, 4, 189, -1, 4};
	int n=11;
	divide(arr,n);
}
