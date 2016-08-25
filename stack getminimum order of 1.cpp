#include<iostream>
using namespace std;

int createstack(int *array,int n,int *stack,int *aux){
	
	for(int i=0;i<n;i++){
		stack[i]=array[i];
		
		aux[i]=array[i];
	}
	for(int i=1;i<n;i++){
		if(aux[i]>aux[i-1]) aux[i]=aux[i-1];
	}
		
}
void printmin(int *stack,int n,int *aux){
	for(int i=0;i<n;i++)
	cout<<aux[i]<<" ";
}
int main(){
		int array[6]={10, 7, 8, 9, 1, 5};  
 int n=6;
 int stack[n],aux[n];
 createstack(array,n,stack,aux);
 printmin(stack,n,aux);
}
