#include<iostream>
#include<algorithm>
using namespace std;
void utility(int a[],int n,int size,int result[],int index,int last){
if(size==last){
	for(int i=0;i<size;i++){
		cout<<result[i]<<" ";
	}cout<<endl;
	return;
}

for(int i=index;i<n;i++){
	int t=result[index];
	result[last]=a[i];
	//	while(a[i]==a[i+1]){
	//	i++;
	//}
	utility(a,n,size,result,i+1,last+1);

}	
}
void printperm(int a[],int n,int size){
	int result[3];
	sort(a,a+n);
	
	utility(a,n,size,result,0,0);
}
int main(){
	int a[]={1,2,3,4,1};
	int n=5;
	int  size=3;
	printperm(a,n,size);
}
