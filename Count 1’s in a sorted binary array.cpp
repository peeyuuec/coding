#include<iostream>
using namespace std;

int count1s(int *array,int left,int right){
	if(left<=right){
		int mid=left+(right-left)/2;
		if(array[mid]==1){
			if(mid==right||array[mid+1]==0){
				return mid+1;
			}
			return count1s(array,mid+1,right);
			
		}
		else{
			return count1s(array,left,mid-1);
		}
	}
	return 0;
}
int main(){
	int n=7;
	int ar1[n]={1, 1, 0, 0, 0, 0, 0};
	cout<<count1s(ar1,0,6);
}
