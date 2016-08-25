#include<iostream>
using namespace std;
void longestISeuence(int *arr,int n,int *result){
	for(int i=0;i<n;i++)
	result[i]=1;

	cout<<endl;
	for(int i=0;i<n;i++){
		for(int j=0;j<i;j++){
			if(arr[i]>arr[j]&&result[i]<=result[j]){
				result[i]=result[j]+1;
			}
		}
	}

}
int main(){
	int n=6;
	 
	 int arr[n] = {80, 60, 30, 40, 20, 10};
	 int result1[n];

	 int temp[n];
	 longestISeuence(arr,n,result1);

	 	
	 	
	 		 for(int i=0;i<n;i++)
		temp[i]=arr[n-i-1];
		 
	 	cout<<endl;
	 	 int second[n];
		 longestISeuence(temp,n,second);
	 	
		for(int i=0;i<n;i++)
		cout<<	result1[i]<<" ";
cout<<endl;	
	for(int i=0;i<n;i++)
		temp[i]=second[n-i-1];

	for(int i=0;i<n;i++)
		cout<<	temp[i]<<" ";
		cout<<endl;
		int max=0;
		for(int i=0;i<n;i++){
			if(max<result1[i]+temp[i]-1){
				max=result1[i]+temp[i]-1;
				cout<<result1[i]<<temp[i]<<" ";
			}
		}
		cout<<max;
		
}
