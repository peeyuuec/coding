#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#define ll long long int
using namespace std;

ll histogram(ll a[],ll n){
    ll area=a[0];
    ll i=0;
    ll stack[n];
    ll top=-1;
    ll max=a[0];
    //2 1 2
    for(i=0;i<n;i++){
    	
    	if(top==-1||a[stack[top]]<=a[i]){
    		stack[++top]=i;
		}
		else{
			while(top!=-1&&a[stack[top]]>a[i]){
				ll temp=a[stack[top]];
				top--;
				if(top==-1){
					ll t=temp*(i);
					if(area<t){
						area=t;
					}
					
				}
				else{
						ll t=temp*(i-stack[top]-1);
							if(area<t){
						area=t;
					}
					}
			}
			stack[++top]=i;
		}
   }
   cout<<stack[top]<<stack[top-1]<<stack[top-2]<<endl;
   while(top!=-1){
   			ll temp=stack[top];
				top--;
				if(top==-1){
					ll t=a[temp]*(n);
					if(area<t){
						area=t;
					}
					
				}
				else{
						ll t=a[temp]*(n-stack[top]-1);
							if(area<t){
						area=t;
					}
					}
					cout<<area<<" "<<n<<" "<< stack[top]<<endl;
   }
    return area;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    ll n;
    cin>>n;
    while(n!=0){
	
        ll a[n];
        for(ll i=0;i<n;i++){
            cin>>a[i];
        }
    
        cout<<histogram(a,n)<<endl;
        
      cin>>n;  
    }
    return 0;
}

