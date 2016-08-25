#include<iostream>
#include<stdlib.h>
using namespace std;
int binarysearch(int *array,int start,int end,int element,int* closest){
	if(start<=end){
	
	int mid=start+(end-start)/2;
	
	if(abs(array[*closest]-element)>abs(array[mid]-element)){
			*closest=mid;
		}
		
	if(array[mid]==element) {
		
	return mid;}
	
	if(array[mid]>element)
    {
		return binarysearch(array,start,mid-1,element,closest);
    }
	else if(array[mid]<element)
  {
  return binarysearch(array,mid+1,end,element,closest);}
}
return -1;
}
void printknearest(int *array,int n,int element){
	
}
int main(){

	int k=4,element=35;
		int array[] ={12, 16, 22, 30, 35, 39, 42,
               45, 48, 50, 53, 55, 56}; 
        int n=13;
        	int closest=n;
        cout<<endl<<binarysearch(array,0,n-1,element,&closest);
        cout<<closest<<endl;
        if(k>n){
        	cout<<"invalid k value"<<endl;
		}
		else{
		int left=closest-1,right=closest+1;
		int size;
		if(array[closest]==element) size=k;
		else {cout<<array[closest]<<" ";
		size=k-1;}
		for(int i=0;i<size;i++){
			
		if(left>=0&&right<n){
			if(element-array[left]<array[right]-element){
				cout<<array[left]<<" ";
				left--;
			}
			else{
				cout<<array[right]<<" ";
				right++;
			}
		}
		else if(left>=0&&right>=n){
			cout<<array[left]<<" ";
			left--;}
	    else if(right<n&&left<0){
			cout<<array[right]<<" ";
			right++;
		}
		}
		
		
	}

}
