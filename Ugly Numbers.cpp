#include<iostream>
using namespace std;
int min(int a,int b,int c){
	if(a<b){
		return c<a?c:a;
	}
	else{
		return c<b?c:b;
	}
}
int main(){
	int n=150;
	int ugly[n];
	ugly[0]=1;int multiplefor2=0,multiplefor3=0,multiplefor5=0;
	for(int i=1;i<n;i++){
	
	
	int potentialnextuglynumber1=ugly[multiplefor2]*2;
	int potentialnextuglynumber2=ugly[multiplefor3]*3;
	int potentialnextuglynumber3=ugly[multiplefor5]*5;
	int minvalue=min(potentialnextuglynumber1,potentialnextuglynumber2,potentialnextuglynumber3);
	if(minvalue==potentialnextuglynumber1){
		multiplefor2++;
		
	}
	 	if(minvalue==potentialnextuglynumber2){
		multiplefor3++;
	}
	 	if(minvalue==potentialnextuglynumber3){
		multiplefor5++;
	}
	ugly[i]=minvalue;
}
for(int i=0;i<n;i++)
cout<<ugly[i]<<" ";
	
}
