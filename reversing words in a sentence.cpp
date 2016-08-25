#include<iostream>
using namespace std;
int main(){
		char str[]="this is a string";

	int n=strlen(str);
	int left;
	int right;
	for(int i=0;i<n;i++){
		 left=i;
		
		while(i<n&&str[i]!=' '){
			
			i++;
		}
		 right=i-1;
		while(left<right){
			
			char temp=str[left];
		
			str[left]=str[right];
			
			str[right]=temp;
			left++;
			right--;
		}
		
	}
	left=0;
	right=n-1;
	while(left<right){
		char temp=str[left];
			str[left]=str[right];
			
			str[right]=temp;
			left++;
			right--;
	}
	cout<<str;
}
