#include<iostream>
using namespace std;
int main(){
	int n=2,k=36;
	int A[n+1][k+1];
    int res;
    int i, j, x;
    for(int i=1;i<=n;i++){
    	A[i][0]=0;
	}
	   for(int i=1;i<=k;i++){
    	A[1][i]=i;
	}
	for(int i=1;i<=n;i++){
		A[i][1]=1;
	}
	for(int i=2;i<=n;i++){
		for(int j=2;j<=k;j++){
			int min=1000;
			for(int f=2;f<=j;f++){
				if(A[i-1][f-1]>A[i][j-f]){
					if(min>A[i-1][f-1])
					min=A[i-1][f-1];
					
				}
				else{
						if(min>A[i][j-f])
					min=A[i][j-f];
				}
			}
			A[i][j]=1+min;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=k;j++){
			cout<<A[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<A[n][k];
}
