#include <stdio.h>
#include<iostream>
using namespace std;
int main() {
	//code
	int t;
	cin>>t;
	for(int c=0;c<t;c++){
	    string s;
	    cin>>s;
	    int n=s.length();
	    int t=n-2;
	    while(t>=0&&s[t]>=s[t+1]){
	        t--;
	    }
	    if(t<0){
	        cout<<"not possible"<<endl;
	    }else{
	        int index=t;
	        while(index<n-1&&s[t]<s[index+1]){
	            index++;
	        }
	        char temp=s[index];
	        s[index]=s[t];
	        s[t]=temp;
	        cout<<s<<endl;
	        int l=t+1;
	        int r=n-1;
	        while(l<r){
	            temp=s[l];
	        s[l]=s[r];
	        s[r]=temp;
	        l++;
	        r--;
	        }
	        cout<<s<<endl;
	    }
	    
	}
	return 0;
}
