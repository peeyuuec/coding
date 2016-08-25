#include<iostream>
using namespace std;
void fillKMPtable(int *table,char* pat){
	int m=strlen(pat);
	int index=1;
	table[0]=0;
	int len=0;
	while(index<m){
		if(pat[index]==pat[len]){
			table[index]=len+1;
			len++;
			index++;
		}
		else if(index<m&&len>0){
			len=table[len-1];
		}
		else if(index<m&&len==0){
			table[index]=0;
			index++;
		}
	}
}
void searchKMP(char *pat,char *str){
	int l=strlen(pat);
	int table[l];
	fillKMPtable(table,pat);
	for(int i=0;i<l;i++){
		cout<<table[i]<<" ";
	}
	cout<<endl;	
	int n=strlen(str);
	int m=strlen(pat);
	int i=0;
	int j=0;
	while(i<n){
		while(j<m&&str[i]==pat[j]){
			i++;
			j++;
		}
		if(j==m){
			cout<<i-m<<endl;
		}
		if(i<n&&str[i]!=pat[j]){
			if(j>0){
				j=table[j-1];
			}
			else{
				i++;
			}
		}
	}
	
}
int main(){
	char* str="ABABDABACDABABCABAB";
	char *pat="ABA";
    searchKMP(pat,str);
	
}
