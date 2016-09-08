#include<iostream>
using namespace std;
int main(){
	int arr[] = {12, 1, 12, 3, 12, 1, 1, 2, 3, 3};
	int n=10;
	int stack[n];
	int top=-1;
	int area=0;
	stack[++top]=0;
	for(int i=1;i<n;i++){
		while(top!=-1&&arr[stack[top]]>arr[i]){
			int val=arr[stack[top--]];
			if(top==-1){
				int temp=val*i;
				if(temp>area){
					area=temp;
				
				}	cout<<temp<<" "<<i<<endl;
			}
			else{
				int temp=val*(i-stack[top]-1);
					if(temp>area){
					area=temp;
					
				}	cout<<temp<<" "<<i<<endl;
			}
		}
		stack[++top]=i;
	}
	cout<<area<<endl;
	int i=n;
	while(top!=-1){
		int val=arr[stack[top--]];
			if(top==-1){
				int temp=val*i;
				if(temp>area){
					area=temp;
				}
				cout<<temp<<" "<<i<<endl;
			}
			else{
				int temp=val*(i-stack[top]-1);
					if(temp>area){
					area=temp;
				}
				cout<<temp<<" "<<i<<endl;
			}
	}
	cout<<area;
}
