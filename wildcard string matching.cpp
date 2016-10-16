#include<iostream>
#include<vector>
using namespace std;
int matcher2(string p,string s){//*b aa
	int n=p.length();
	int m=s.length();
	vector<int>pre(m+1,0);
	vector<int>curr(m+1,0);
	for(int i=0;i<=m;i++){
		pre[i]=0;
	}
	pre[0]=1;
	for(int i=1;i<=n;i++){
		curr[0]=1;
		for(int j=0;j<i;j++){
			if(p[j]!='*'){
				curr[0]=0;
				break;
			}
		}
		for(int k=1;k<=m;k++){
			if(p[i-1]==s[k-1]||p[i-1]=='?'){
				curr[k]=pre[k-1];
			}
			else if(p[i-1]=='*'){
				if((curr[k-1]==1||pre[k]==1)){
					curr[k]=1;
				}
				else{
					curr[k]=0;
				}
				
			}
			else {
				curr[k]=0;
			}
			cout<<curr[k]<<" ";
		}
		cout<<endl;
		pre.clear();
		pre=curr;
		curr.clear();
	}
	cout<<pre[m]<<endl;
	return pre[m];
}


void test(string first,string second)
{  if(matcher2(first, second)==1){
	
cout<<"yes"<<endl;
	}
	else cout<<"No"<<endl; 

}
int main(){
	test("*b", "aa");
	test("ab*cd?i*de", "abefcdgiescdfimde"); // Yes
    test("ge?ks*", "geeksforgeeks"); // Yes
    test("g*k", "gee");  // No because 'k' is not in second
    test("*pqrs", "pqrst"); // No because 't' is not in first
    test("abc*bcd", "abcdhghgbcd"); // Yes
    test("abc*c?d", "abcd"); // No because second must have 2
                             // instances of 'c'
    test("*c*d", "abcd"); // Yes
    test("*?c*d", "abcd"); // Yes
}
