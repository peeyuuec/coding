#include<iostream>
using namespace std;
int main(){
	 int n=4;
	int ar1[n]={1,4,8,40};
    int number=45;
    int diff=10000;
    int i=0,j=n-1;
    int index1,index2;
    while(i<j){
    int sum=ar1[i]+ar1[j];
    if(sum==number){
    	index1=i;
    	index2=j;
    	cout<<index1<<" "<<index2<<endl;
    	return diff;
	}
	else	if(sum>number){
		int temp=sum-number;
		if(diff>temp){
			diff=temp;
			index1=i;
    		index2=j;
		}
			j--;
			
		}
		else if(sum<number){
				int temp=number-sum;
		if(diff>temp){
			diff=temp;
			index1=i;
    		index2=j;
		}
			i++;
		}
	}
	cout<<index1<<" "<<index2<<endl;
}
