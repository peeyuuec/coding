#include<iostream>
using namespace std;
int main(){
	char num[]="1809";
	int n=strlen(num);
		int count=0;
	for(int i=0;i<n;i++){
		int sum=0;
		for(int j=i;j<n;j++){
			sum+=(num[j]-'0');
			if(sum%9==0&&sum!=0){
				
				count++;
				cout<<i<<" "<<j<<endl;
			}
		
			
		}
	}

	cout<<count;
}
