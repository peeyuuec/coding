#include<iostream>
using namespace std;
int main(){
	int price[] = {6, 2, 5, 4, 5, 1, 6};
    int n = sizeof(price)/sizeof(price[0]);
    int S[n];
    int top=-1;
    S[++top]=0;
    int area=price[0];
    int left,right;
    int i;
	for( i=1;i<n;i++){
		while(top!=-1&&price[i]<=price[S[top]]){
			int current=S[top--];
				int temp;
			if(top!=-1){
				 temp=(i-S[top]-1)*price[current];
			}
			else{
				temp=i*price[current];
			}
			
			if(area<temp)
			{cout<<"a";
			area=temp;
			left=S[top];
			right=i;
		}
		
		}
	S[++top]=i;
		}
		while(top!=-1){
			int current=S[top--];
				int temp;
			if(top!=-1){
				 temp=(i-S[top]-1)*price[current];
			}
			else{
				temp=i*price[current];
			}
			
			if(area<temp)
			{cout<<"a";
			area=temp;
			left=S[top];
			right=i;
		}
		
		}
	cout<<area;
}
