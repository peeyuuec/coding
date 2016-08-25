#include<iostream>
using namespace std;
int binarysearch(int *array,int start,int end,int element){
    
    if(start<=end){
    int mid= start+ (end-start)/2;
	if(array[mid]==element)return mid;
    
	
	else if(array[mid]<element) return binarysearch(array,mid+1,end,element);
    else return binarysearch(array,start,mid-1,element);
     }
         return -1;
    }
int main(void){
 int array[5]={1,2,3,4,5};
 int n=5;
    int element;
    cin>>element;
   cout<<binarysearch(array,0,n-1,element);
   return 0;
}

