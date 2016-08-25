#include<iostream>
using namespace std;
int sortinwave(int *array,int n){
	for(int i=0;i<n-1;i++){
		if(i%2==0){
		
		if(array[i]<array[i+1]){
			int temp=array[i];
			array[i]=array[i+1];
			array[i+1]=temp;
		}
	}
	else{
		if(array[i]>array[i+1]){
			int temp=array[i];
			array[i]=array[i+1];
			array[i+1]=temp;
		}
	}
	}
}
int main(){
		int array[8]={10, 5, 6, 3, 2, 20, 100, 80};  
 int n=8;
	sortinwave(array,n);
	for(int i=0;i<n;i++)
	cout<<array[i]<<" ";
	
}
