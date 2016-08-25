#include<iostream>
using namespace std;
void search(char txt[],char pat[]){
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
	int l=0,r=0;
	int count=m;
	while(r<n&&count!=0){
			if(table2[txt[r]]>0){
				count--;
				table2[txt[r]]--;
			}
				else	if(table1[txt[r]]>0){
			table2[txt[r]]--;
		}
			r++;
		}
		if(r-l==m&&count==0){
			cout<<l<< " "<<r-1<<endl;
		}
	while(r<n){
		if(table1[txt[l]]>0){

				table2[txt[l]]++;
				if(table2[txt[l]]>0){
					count++;
				}
			}
			l++;
			
			
		while(r<n&&count!=0){
			if(table2[txt[r]]>0){
				table2[txt[r]]--;
				count--;
				
			}
		else	if(table1[txt[r]]>0){
			table2[txt[r]]--;
		}
			r++;
		}
		
			if(r-l==m)
			{
			cout<<l<< " "<<r<<" "<<endl;;
		}
		
	}
}

int main(){
	char txt[] = "BACCDGABCDA" ;
	char pat[] = "ABCD";
	search(txt,pat);
}
