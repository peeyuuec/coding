#include<iostream>
using namespace std;
int isoperator(char c){
	if(int(c)<int ('a')||int (c)>int('z')){return 1;
	}
	else return 0;
}
int isoperand(char c){
	if(int(c)<int ('a')||int (c)>int('z')){return 0;
	}
	else return 1;
}
int infixtopostfix(char *array,int n,int *prioritytable){
	char *stack;
	int top=-1;
	for(int i=0;i<n;i++){
		if(isoperand(array[i])){
			cout<<array[i];
		}
		else{
			if(array[i]==')'){
				while(stack[top]!='('){
					cout<<stack[top--];
					
				}
				top--;
			}
			else if(isoperator(array[i])||array[i]=='('){
			
			
				while(top!=-1&&prioritytable[int(stack[top])]>prioritytable[int(array[i])]&&stack[top]!='('){
					cout<<stack[top--];
				}
				stack[++top]=array[i];
			}
			}
		}
	while(top!=-1){
		cout<<stack[top--];
	}
}
int main(){
	int prioritytable[256];
	prioritytable[int('(')]=17;
	prioritytable[int('*')]=16;
	prioritytable[int('/')]=16;
	prioritytable[int('+')]=15;
	prioritytable[int('-')]=15;
	
	char array[7]={'a','*','(','b','+','c',')'};
	int n=7;
	infixtopostfix(array,n,prioritytable);
}
