#include<iostream>
#include<cstring>
using namespace std;
 string longestPalindrome(string s) {
        int n=s.length();
        int A[n][n];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                A[i][j]=0;
            }
            A[i][i]=1;
        }
        for(int i=0;i<n-1;i++){
            if(s[i]==s[i+1]){
                A[i][i+1]=1;
            }
        }
        if(n==1)return s;
        if(n==2){
            if(A[0][1]==1)return s;
           
        }
        int right=0,left=0,max=1;
        for(int L=3;L<=n;L++){
            int index=n-L+1;
            for(int j=0;j<index;j++){
                int index2=j+L-1;
                if(s[j]==s[index2]&&A[j+1][index2-1]==1){
                    A[j][index2]=1;
                
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(A[i][j]==1){
                    if(j-i+1>max){
                        max=j-i+1;
                        left=i;
                        right=j;
                    }
                }
            }
        }
         char result[max];
         for(int i=0;i<max;i++){
             result[i]=s[left];
             result[i+1]='\0';
             left++;
         }
         //cout<<max;
         return result;
        } 
int main(){
	string s="bananas";
	cout<<longestPalindrome(s);
	
}
