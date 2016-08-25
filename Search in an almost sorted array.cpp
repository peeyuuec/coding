#include<iostream>
using namespace std;
int binarysearchnearlysirted(int *array,int left,int right,int element){
	if(left<=right){
		int mid=left+(right-left)/2;
		if(array[mid]==element) return mid;
		if(mid-1>=0&&array[mid-1]==element) return mid-1;
		if(mid+1<=right&&array[mid+1]==element) return mid+1;
		
		if(array[mid]>element) return binarysearchnearlysirted(array,left,mid-1,element);
		if(array[mid]<element) return binarysearchnearlysirted(array,mid+1,right,element);
	}
	return -1;
}
int main(){
	int array[7]={10, 3, 40, 20, 50, 80, 70};  
 int n=7;
 	cout<<binarysearchnearlysirted(array,0,n-1,10);
}
