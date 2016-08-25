#include<iostream>
using namespace std;
int minimumlengthunsortedarray(int *array,int n){
	int min,max;
	int left=0,right=n-1;
	while(left<n-1&&array[left]<=array[left+1]){
		left++;
	}
	while(right>0&&array[right-1]<=array[right]){
		right--;
	}
	min=array[left];
	max=array[right];
	for(int i=left;i<=right;i++){
		if(array[i]<min){
			min=array[i];
		}
		if(array[i]>max){
			max=array[i];
		}
		
	}
	while(min<array[left]){
		left--;
	}
	while(max>array[right]){
		right++;
	}
	
	cout<<"left:"<<left+1<<endl<<"right:"<<right-1<<endl;
	
}
int main(){
	int array[9]={0, 1, 15, 25, 6, 7, 30, 40, 50};
	minimumlengthunsortedarray(array,9);
}
