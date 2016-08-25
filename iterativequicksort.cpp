#include<iostream>
using namespace std;
int partition(int *array,int l,int r){//1,5,8,9,10,7
	
	int pivot=r;
	int left=l,right=r;
	right--;
	while(left<=right){
		while(left<=r-1&&array[left]<=array[pivot]){
			left++;
		}
		while(right>=l&&array[right]>=array[pivot]){
			right--;
		}
		if(left<=right){
		int temp=array[left];
		array[left]=array[right];
		array[right]=temp;
		}
	}
		int temp=array[pivot];
		array[pivot]=array[left];
		array[left]=temp;
		return left;
}
int quicksortIterative(int *array,int left,int right){
	int stack[right-left+1];
	int top=-1;
	stack[++top]=left;
	stack[++top]=right;
	while(top>=0){
		right=stack[top--];
		left=stack[top--];
		int pivot=partition(array,left,right);
		cout<<pivot<<endl;
		if(pivot>left+1){
			stack[++top]=left;
			stack[++top]=pivot-1;
		}
		if(pivot<right-1){
			stack[++top]=pivot+1;
			stack[++top]=right;
		}
	}
}
int main(){
	int array[6]={10, 7, 8, 9, 1, 5};  
 int n=6;
 quicksortIterative(array,0,5);
 for(int i=0;i<6;i++){
	cout<<array[i]<< " ";
}
}
