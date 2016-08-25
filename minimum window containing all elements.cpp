#include<iostream>
using namespace std;
void findwindow(char txt[],char pat[]){
	int n=strlen(txt);
	int m=strlen(pat);
	int table1[256];
	int table2[256];
	for(int i=0;i<256;i++){
		table1[i]=0;
		table2[i]=0;
	}
	for(int i=0;i<m;i++){
		table1[pat[i]]=1;
		table2[pat[i]]+=1;
	}
	int count=m;
	int left=0,right=0;
	int min=10000;
	while(right<n){
		while(right<n&&count!=0){
			//cout<<"a ";
			if(table1[txt[right]]>0){
				if(table2[txt[right]]>0){
					count--;
				}
				table2[txt[right]]--;
			}
			right++;
		}
		if(table1[txt[left]]>0){
			
			table2[txt[left]]++;
			if(table2[txt[left]]>0){
				count++;
			}
		}
		if(min>right-left){
			min=right-left;
		}
		cout<<left<<" "<<right-1<<endl;
		left++;
		
		
	}
	cout<<min<<endl;
	
}

int main(){
			char txt[] = "BACCDGAqBCDA" ;
	char pat[] = "ABCD";
	findwindow(txt,pat);
}
