#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	// your code goes here
	
	int t;
	cin>>t;
	for(int test=0;test<t;test++){
		
		int n,cow;
		cin>>n>>cow;
		
	vector<int>v(n);
	for(int i=0;i<n;i++){
		cin>>v[i];
	}
	sort(v.begin(),v.begin()+v.size());
	vector<int>right(n);
	vector<int>left(n);
	right[n-1]=0;
	left[0]=0;
	for(int i=1;i<n;i++){
		left[i]=v[i]-v[0];
	}
	for(int i=n-2;i>=0;i--){
		right[i]=v[n-1]-v[i];
	}
		int max=0;
	for(int kou=3;kou<=cow;kou++){
	max=0;
		int index;
		for(int j=0;j<n;j++){
			int t=min(left[j],right[j]);
			if(t>max){
				max=t;
				index=j;
			}
			
		}
		//cout<<max<<index;
		int t=index+1;
		int minus=left[index];
		left[index]=0;
		while(t<n&left[t]!=0){
			left[t]=left[t]-minus;
			t++;
		}
		t=index-1;
		minus=right[index];
		right[index]=0;
		while(t>=0&&right[t]!=0){
			right[t]=right[t]-minus;
			t--;
		}
		
	}
	cout<<max<<endl;
	/*
	for(int i=0;i<n;i++){
		cout<<left[i]<<" ";
	}
	cout<<endl;
	for(int i=0;i<n;i++){
		cout<<right[i]<<" ";
	}
	cout<<endl;*/
	}
	return 0;
}
