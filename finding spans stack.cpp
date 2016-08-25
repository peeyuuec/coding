#include<iostream>
using namespace std;
int main(){
	int price[] = {10, 4, 5, 90, 120, 80};
    int n = sizeof(price)/sizeof(price[0]);
    int S[n];
    int top=-1;
    S[++top]=0;
    for(int i=1;i<n;i++){
    	while(top!=-1&&price[i]>=price[S[top]]){
    	top--;	
		}
		if(top==-1){
			cout<<i<<" "<<i+1<<endl;
		}
		else{
			
			cout<<i<<": "<<i-S[top]<<endl;
			
		}
		S[++top]=i;
	}
}
