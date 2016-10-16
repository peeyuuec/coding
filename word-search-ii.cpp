#include<iostream>
#include<map>
#include<vector>
using namespace std;

int issafe(int x,int y,int n,int m){
    if(x>=0&&y>=0&&x<n&&y<m)return 1;
    return 0;
}
int arrx[]={1,0,-1,0};
int arry[]={0,1,0,-1};
int util(vector<vector<char> >& board,int x,int y,string s,int index,vector<string> &result,vector<vector<int> >visited,int &done,int n,int m)
{
    if(index>=s.length()){
        result.push_back(s);
        done=1;
        return 1;
    }
    for(int i=0;i<4;i++){
        int newx=x+arrx[i];
        int newy=y+arry[i];
        if(issafe(newx,newy,n,m)==1){
            if(visited[newx][newy]==0&&board[newx][newy]==s[index]){
                visited[newx][newy]=1;
                if(util(board,newx,newy,s,index+1,result,visited,done,n,m)==1){
                    return 1;
                }
                visited[newx][newy]=0; 
            }
        }
    }
    return 0;
}


vector<string> findWords(vector<vector<char> >& board, vector<string>& words) {
       vector<string> result;
       int n=board.size();
       int m=board[0].size();
       map<string,int>mp;
       for(int i=0;i<words.size();i++){
           if(mp.find(words[i])==mp.end()){
               mp[words[i]]=1;
           
           int done=0;
           for(int j=0;j<n;j++){
               for(int k=0;k<m;k++){
                   if(board[j][k]==words[i][0]){
                       vector<vector<int> >visited(n,vector<int>(m,0));
                       visited[j][k]=1;
                       util(board,j,k,words[i],1,result,visited,done,n,m);
                       if(done==1){
                           break;
                       }
                   }
               }
               if(done==1){
                           break;
                       }
           }
           
       }
       }
       for(int i=0;i<result.size();i++){
       	cout<<result[i]<<" ";
	   }
       return result;
    }
    
    int main(){
    	int n,m,w;
    	cin>>n>>m>>w;
    	
    	vector<vector<char> > board(n,vector<char>(m));
		 vector<string> words(w);
    	for(int i=0;i<n;i++){
    		for(int j=0;j<m;j++){
    			char t;
    			cin>>t;
    			board[i][j]=t;
			}
		}
		for(int i=0;i<w;i++){
			string s;
			cin>>s;
			words[i]=s;
		}
    	findWords(board,words);
	}
