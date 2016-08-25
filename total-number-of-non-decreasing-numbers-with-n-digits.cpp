#include<iostream>
using namespace std;
int count;
void printnondecreasing(int index,int n,int a[]){
	if(index==0){
		for(int i=0;i<n;i++){
			cout<<a[i];
		}
		cout<<endl;
		count++;
		return;
	}
	for(int i=0;i<=9;i++){
		if(a[n-index-1]<=i){
			a[n-index]=i;
			printnondecreasing(index-1, n, a);
		}
	}
}
int countnondecreasing(int n){
	int count[10];
	for(int i=0;i<10;i++){
		count[i]=1;
	}
	for(int i=2;i<=n;i++){
		int temp[10];
		for(int p=0;p<10;p++){
			temp[p]=count[p];
		}
		for(int j=0;j<10;j++){
			
			for(int k=j+1;k<10;k++){
				count[k]=count[k]+temp[j];
			}	
			
			
		}
	}
	int temp=0;
	for(int i=0;i<10;i++){
		temp+=count[i];
	}
	return temp;
}
int main(){
	count=0;
	int n=1;
	int a[n];
	for(int i=0;i<10;i++){
		a[0]=i;
	printnondecreasing(n-1, n, a);	
	}
	cout<<count<<endl;
	cout<<countnondecreasing(n);
	
}
