#include<iostream>
using namespace std;
int main(){
		int ar1[4]={1,4,40,40};
     int   ar2[4] = {10,40,30,40};
     int ar3[4]= {10,20,40,40};
     int i=0,j=0,k=0;
     int size1=4,size2=4,size3=4;
     while(i!=size1&&j!=size2&&k!=size3){
     	int max=ar1[i];
     	if(ar2[j]>max)max=ar2[j];
     	if(ar3[k]>max)max=ar3[k];
     	
     	while(ar1[i]<max&&i!=size1){
     		i++;
		 }
		 	while(ar2[j]<max&&j!=size2){
     		j++;
		 }
		 	while(ar3[k]<max&&k!=size3){
     		k++;
		 }
		 if(ar1[i]==ar2[j]&&ar2[j]==ar3[k]&&ar1[i]==ar3[k]){
		 	cout<<ar1[i]<<" "<<i<<endl;
		 	i++;
		 	j++;
		 	k++;
		 }
		 
		 
	 }
}
