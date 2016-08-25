#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void findKthmaximum(int *array,int n,int k){
	vector<int> v(array,array+n);
	make_heap(v.begin(),v.end());
	for(int i=0;i<k-1;i++){
		pop_heap(v.begin(),v.end());
		v.pop_back();
	}
	cout<<v.front();
}
int main(){
	int array[6]={10, 7, 8, 9, 1, 5};  
 int n=6;
 int k=2;
 findKthmaximum(array,n,k);
}
