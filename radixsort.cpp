#include<iostream>
using namespace std;
int countingsort(int *array,int n,int exp){
	int temp[n],value[n];
	for(int i=0;i<n;i++)
	temp[i]=0;
	for(int i=0;i<n;i++){
	int index=(array[i]/exp)%n;
		{
		temp[index]++;
	}
	}
	for(int i=1;i<n;i++){
		temp[i]+=temp[i-1];
	}
	for(int i=n-1;i>=0;i--){
		value[temp[(array[i]/exp)%n]-1]=array[i];
		temp[(array[i]/exp)%n]--;
	}
	
	int j=0;
	for(int i=0;i<n;i++){
	array[i]=value[i];
	}
}
void printarray(int *array,int n){
	for(int i=0;i<n;i++)
	cout<<array[i]<<" ";
}
void radixsort(int *array,int n){
	countingsort(array,n,1);
	countingsort(array,n,n);
}
int main(){
		//int array[] ={12, 16, 22, 30, 35, 39, 42,
              // 45, 48, 50, 53, 55, 56}; 
               	int array[10]={19, 7, 8, 9, 11, 5,7,33,1,36};  
 int n=10;
       radixsort(array,10);
	   // int n=13;
        //countingsort(array,n,1);
        printarray(array,n);
}
