#include<iostream>
using namespace std;
int d[3][3];
#define R 3
#define C 3
int max(int len[],int n){
		int max=0;
		for(int i=0;i<n;i++){
			if(max<len[i]){
				max=len[i];
			}
		}
		return max;
	}
int invalid(int i, int j){
	
	if(i>=R||i<0||j>=C||j<0){
		return 1;
	}
	return 0;
}

int getlength(char mat[R][C],int i,int j,char c,char lastchar){
	if(invalid(i,j)==1||lastchar+1!=mat[i][j]){
		
		return 0;
	}
	int result=mat[i][j]-lastchar;
		cout<<result<<" "<<mat[i][j]<<" "<<lastchar<<endl;
	if(d[i][j]!=-1){
		return d[i][j];
	}
	int len[8];
			len[0]=getlength(mat,i,j-1, c,mat[i][j] );
		  	len[1]=getlength(mat,i,j+1, c,mat[i][j] );
		  	len[2]=getlength(mat,i-1,j-1, c,mat[i][j] );
		  	len[3]=getlength(mat,i-1,j+1, c,mat[i][j] );
		  	len[4]=getlength(mat,i-1,j, c,mat[i][j] );
		  	len[5]=getlength(mat,i+1,j, c,mat[i][j] );
		  	len[6]=getlength(mat,i+1,j+1, c,mat[i][j] );
		  	len[7]=getlength(mat,i+1,j-1, c,mat[i][j] );
	d[i][j]=1+max(len,8);
	return 1+max(len,8);
	
}
int main(){

	char mat[R][C] = { {'p','c','d'},
                     { 'h','b','a'},
                     { 'i','g','a'}};
    
    for(int i=0;i<R;i++){
    	for(int j=0;j<C;j++){
    		d[i][j]=-1;
		}
	}
	int len[8]={0,0,0,0,0,0,0,0};
	char c='a';int maxc=0;
	for(int i=0;i<R;i++){
		for(int j=0;j<C;j++){
			
		  if(mat[i][j]==c){
		  	d[i][j]=1;
		  	
		  	len[0]=getlength(mat,i,j-1, c,mat[i][j] ); //1 1
		  	len[1]=getlength(mat,i,j+1, c,mat[i][j] );// 1,3
		  	len[2]=getlength(mat,i-1,j-1, c,mat[i][j] ); //0 1
		  	len[3]=getlength(mat,i-1,j+1, c,mat[i][j] );// 0 3
		  	len[4]=getlength(mat,i-1,j, c,mat[i][j] );//0 2
		  	len[5]=getlength(mat,i+1,j, c,mat[i][j] );//2 2 
		  	len[6]=getlength(mat,i+1,j+1, c,mat[i][j] );//2 3
		  	len[7]=getlength(mat,i+1,j-1, c,mat[i][j] );//2 1
		  	int temp=1+max(len,8);
		  	
		  	maxc=maxc>1+temp?maxc:temp;
		  }
		}
	}
	cout<<maxc<<endl;
	
}

