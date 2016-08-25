#include<iostream>
#include<stdio.h>
using namespace std;

int closestsumpair(int *array1,int *array2,int n,int m,int number){
	int diff=10000,index1,index2,i,j;
	i=0;
	j=m-1;
	while(i!=n&&j!=-1){
		if(array1[i]+array2[j]==number){
		    diff=0;
			index1=i;
			index2=j;
			break;
		}
		else if(array1[i]+array2[j]>number){
			if(array1[i]+array2[j]-number<diff){
				
				diff=array1[i]+array2[j]-number;
				index1=i;
				index2=j;
			}
		j--;
			
		}else if(array1[i]+array2[j]<number){
			if(number-(array1[i]+array2[j])<diff){
				diff=number-(array1[i]+array2[j]);
				index1=i;
				index2=j;
			}
			i++;
		}
	}
	cout<<index1<<" "<<index2<<endl;
	return diff;
}
int main(){
	int ar1[4]={1,4,5,7};
     int   ar2[4] = {10,20,30,40};
        int x = 32      ;
	cout<<closestsumpair(ar1,ar2,4,4,50);
}
