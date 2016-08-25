#include<iostream>
using namespace std;
int checkpalindromStack(char *array,int n){
	int top=0;
	char stack[n];
	while(array[top]!='X'){
		stack[top]=array[top];
		top++;
	}
	int i=top+1;
	top--;
	while(top>=0){
		if(stack[top]!=array[i]){
			return 0;
		}
		i++;
		top--;
	}
	return 1;
}
int main(){
	char array[5]={'a','b','X','b','a'};
	cout<<checkpalindromStack(array,5);
}
