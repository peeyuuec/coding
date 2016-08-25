#include<iostream>
using namespace std;
int selectionsort(int *array,int n){
    int	index=0;
	for(int i=0;i<n;i++){
		index=i;
		int min=array[i];
		for(int j=i;j<n;j++){
			if(min>array[j]){
				min=array[j];
				index=j;
			}
		}
		int temp=array[i];
		array[i]=array[index];
		array[index]=temp;
	}
}
int bubblesort(int *array,int n){
for(int i=0;i<n;i++){
	for(int j=0;j<n-1;j++){
		if(array[j]>array[j+1]){
		int temp=array[j];
		array[j]=array[j+1];
		array[j+1]=temp;	
		}
	}
}	
}

int insertionsort(int *array,int n){
	for(int i=1;i<n;i++){
		for(int j=0;j<i;j++){
			if(array[j]>array[i]){
			int temp=array[i];
				for(int k=i-1;k>=j;k--){
				array[k+1]=array[k];
					
				
				}
				array[j]=temp;
				j=i;
			}
		}
	}
}

int merge(int *array,int left,int mid,int right){

int l1=left,r1=mid,l2=mid+1,r2=right;
int size=right-left+1;
int aux[size],index=0;
  while(l1<=r1&&l2<=r2){
  	if(array[l1]<array[l2]){
  		aux[index]=array[l1];
  		index++;
  		l1++;
	  }
	  if(array[l1]>array[l2]){
  		aux[index]=array[l2];
  		index++;
  		l2++;
	  }
  }
  while(l1<=r1){
  	aux[index]=array[l1];
  		index++;
  		l1++;
  }
  while(l2<=r2){
  	aux[index]=array[l2];
  		index++;
  		l2++;
  }
  
  for(int i=0;i<size;i++){
  	array[left]=aux[i];
  	left++;
  }
}
int mergesort(int *array,int left,int right){
if(left<right){

	int mid=left+(right-left)/2;
	mergesort(array,left,mid);
	mergesort(array,mid+1,right);
	merge(array,left,mid,right);
}
}
int quicksort(int *array,int left,int right){
	
	if(left<right){
	
	int pivot=right;
	int l=left,r=right-1;
	while(l<r){
		while(array[l]<=array[pivot]){
			l++;
		}
		while(array[r]>array[pivot]){
			r--;
		}
		if(l<r){
		
		int temp=array[r];
		array[r]=array[l];
		array[l]=temp;
		l++;
		r--;
	}
	}
	int temp=array[pivot];
	array[pivot]=array[l];
	array[l]=temp;
	pivot=l;
	
	
	quicksort(array,left,pivot-1);
    quicksort(array,pivot+1,right);
}

}
int main(void)
{
	int array[6]={10, 7, 8, 9, 1, 5};  
 int n=6;
 //mergesort(array,0,4);
 //insertionsort(array,5);
 //bubblesort(array,5);
//selectionsort(array,5);
quicksort(array,0,5);
//quicksort(array,2,4);
//quicksort(array,3,4);
for(int i=0;i<6;i++){
	cout<<array[i]<< " ";
}	
}
