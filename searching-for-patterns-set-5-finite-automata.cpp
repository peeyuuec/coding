#include<iostream>
using namespace std;
getmaxlength(char *pat,char *txt,int state,int newchar){
	char temp[state+1];
	for(int i=0;i<state;i++ ){
		temp[i]=pat[i];
	}
	temp[state]=(char)newchar;
	temp[state+1]='\0';
	//cout<<temp<<endl;
		int index=0;
	
	for(int i=state+1;i>0;i--){
		int count=0;
		for(int j=0;j<i;j++){
		if(pat[j]==temp[index+j]){
			count++;
			//cout<<txt[j]<<" ";
		}	
		}
		//cout<<endl;
		if(count==i)return count;
		index++;
	}
	return 0;
}
void search(char *pat, char*txt){
	int n=strlen(txt);
	int m=strlen(pat);
	int automata[m+1][256];
	for(int i=0;i<=m;i++){
		for(int j=0;j<256;j++){
			automata[i][j]=0;
			if((char)j!='\0'){
				int length=getmaxlength(pat,txt,i,j);
			automata[i][j]=length;
			}
			
		}
	}
	for(int i=0;i<=m;i++){
		cout<<i<<" ";
		for(int j=0;j<256;j++){
			if(automata[i][j]>0){
				cout<<(char)j<<":"<<automata[i][j]<<" ";
			}
			
		}
		cout<<endl;
	}
	int state=0;
	for(int i=0;i<n;i++){
		if(automata[state][int(txt[i])]==m){
			cout<<i-m+1<<endl;
		}
		state=automata[state][int(txt[i])];
		
	}
}
int main(){
	
	char *txt = "AABAACAADAABAAABAA";
   char *pat = "AABA";
   search(pat, txt);
   //cout<<endl<<getmaxlength(pat,txt,0,(int)'A');
}
