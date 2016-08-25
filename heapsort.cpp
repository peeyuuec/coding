#include<iostream>
using namespace std;
int bottomupHeapify(int *array,int index){
	while(index>0){
		int parent=(index-1)/2;
		int max=array[parent];
        int leftchild=parent*2+1,rightchild=parent*2+2;
        if(rightchild==index){
		
        if(max>array[leftchild]&&max<array[rightchild]){
        	array[parent]=array[rightchild];
        	array[rightchild]=max;
		}
		else if(max<array[leftchild]&&max>array[rightchild]){
        	array[parent]=array[leftchild];
        	array[leftchild]=max;
		}
		else if(max<array[leftchild]&&max<array[rightchild]){
			if(array[leftchild]>array[rightchild]){
				array[parent]=array[leftchild];
				array[leftchild]=max;
			}
			else {
			array[parent]=array[rightchild];
				array[rightchild]=max;	
			}
		}
		index=parent;
	}
	else {
		if(max<array[leftchild]){
			array[parent]=array[leftchild];
			array[leftchild]=max;
		}
		index=parent;
	}
	
	}
}
int makeheap(int *array,int n){
	for(int i=0;i<n;i++){
		bottomupHeapify(array,i);
	}
}

int updownheapify(int *array,int size){
	int parent=0;
	int leftchild=2*parent+1;
int	rightchild=2*parent+2;
	int max=array[parent];
	while(leftchild<=size||rightchild<=size){
		if(array[rightchild]==size){
			   if(max>array[leftchild]&&max<array[rightchild]){
        	array[parent]=array[rightchild];
        	array[rightchild]=max;
        	parent=rightchild;
		}
		else if(max<array[leftchild]&&max>array[rightchild]){
        	array[parent]=array[leftchild];
        	array[leftchild]=max;
        	parent=leftchild;
		}
		else if(max<array[leftchild]&&max<array[rightchild]){
			if(array[leftchild]>array[rightchild]){
				array[parent]=array[leftchild];
				array[leftchild]=max;
				parent=leftchild;
			}
			else {
			array[parent]=array[rightchild];
				array[rightchild]=max;	
				parent=rightchild;
			}
		}
		else {
			break;
		}

		}
		else if(array[leftchild]==size){
			if(max<array[leftchild]){
			array[parent]=array[leftchild];
			array[leftchild]=max;
			parent=leftchild;
		} else {
			break;
		}

		}
	
	}
}

int heapsort(int *array,int n){
int aux[n];
int size=n;
for(int i=0;i<n;i++){
	aux[i]=array[0];
	size--;
	array[0]=array[size];
	updownheapify(array,size-1);
}
for(int j=0;j<n;j++){
	array[j]=aux[j];
}
}
int main(){
		int array[6]={12, 11, 13, 5, 6, 7};
 int n=6;
 makeheap(array,6);
  for(int i=0;i<6;i++)
	cout<<array[i]<< " ";
	cout<<endl;
 heapsort(array,6);
 for(int i=0;i<6;i++)
	cout<<array[i]<< " ";
}
