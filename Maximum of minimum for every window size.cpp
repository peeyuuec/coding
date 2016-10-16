#include <stdio.h>
#include<iostream>
#include<vector>
int max(int a,int b){
	return a>b?a:b;
}
using namespace std;
void sol(int a[],int n){

	int stack[n];
	int top=-1;
	int left[n];
	
	stack[++top]=-1;
	for(int i=0;i<n;i++){
		while(top>0&&a[i]<=a[stack[top]]){
			top--;
			
		}
		left[i]=stack[top];
		stack[++top]=i;
	}
	
		int stackright[n];
	int topright=-1;
	int right[n];
	
	stackright[++topright]=n;
	for(int i=n-1;i>=0;i--){
		while(topright>0&&a[i]<=a[stackright[topright]]){
			topright--;
			
		}
		right[i]=stackright[topright];
		stackright[++topright]=i;
	}

	
	vector<int>result(n+1,0);
	for(int i=0;i<n;i++){
		result[right[i]-left[i]-1]=a[i];
		
	}
	
	for(int i=n-1;i>0;i--){
		result[i]=max(result[i],result[i+1]);
	}
	for(int i=1;i<=n;i++){
		cout<<result[i]<<" ";
		
	}
}
int main() {
	//code
	
	int t;
	cin>>t;
	
	for(int c=0;c<t;c++){
	    int n;
	    cin>>n;
	    
	   
	    int a[n];
	    for(int i=0;i<n;i++){
	        cin>>a[i];
	    }
		sol(a,n);
	    /*
	     vector<vector<int> >v(n,vector<int>(n));
	    for(int i=0;i<n;i++){
	        v[i][i]=a[i];
	    }
	    for(int i=0;i<n;i++){
	        for(int j=i+1;j<n;j++){
	            v[i][j]=min(v[i][j-1],a[j]);
	        }
	    }
	    for(int len=1;len<n;len++){
	        int maxi=0;
	        int limit=n-len;
	        for(int i=0;i<=limit;i++){
	            int j=i+len-1;
	            if(maxi<v[i][j]){
	                maxi=v[i][j];
	            }
	        }
	        cout<<maxi<<" ";
	    }
	    
	}
	*/
}
	return 0;
}
