#include<iostream>
#include<list>
#include<vector>
using namespace std;
int main(){
	int aa= (1<<-1);
	cout<<aa;
	cout<<endl;
	char *s1="hlelo";
	char *s2="hello";
	int n1=strlen(s1);
	int n2=strlen(s2);
	if(n1!=n2){
		cout<<-1;return -1;
	}
	vector<int> v(256,0);
	for(int i=0;i<n1;i++){
		v[s1[i]]++;
		v[s2[i]]--;
}
	for(int i=0;i<256;i++){
		if(v[i]!=0){
			cout<<-1;
			return 0;
		}
	}
	int moves=0;
	for(int i=n1-1,j=n1-1;i>=0;){
		if(s1[i]==s2[j]){
			i--;
			j--;
		}
		else{
			while(i>=0&&s1[i]!=s2[j]){
				i--;
				moves++;
			}
		}
	}
	cout<<moves;
	return 1;
}
