#include<iostream>
using namespace std;
int main(){
	int n=11;
	int a[8]=  {-2, -3, 4, -1, -2, 1, 5, -3};
	int A[11];
	A[0]=a[0];
	int max=A[0];
	int index=0;
	for(int i=1;i<n;i++){
		A[i]=A[i-1]+a[i];
		if(max<A[i]){
			max=A[i];
			index=i;
		}
	}
	int left;
	int sum=0;
	for(int j=0;j<index;j++){
		if(sum<A[index]-A[j]+a[j]){
			sum=A[index]-A[j]+a[j];
			left=j;
		}
	}
	cout<<left<<" "<<index<<endl;
	
	
}
