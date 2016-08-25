#include<iostream>
using namespace std;
int main(){
	int s[] =  {1, 3, 0, 5, 8, 5};
    int f[] =  {2, 4, 6, 7, 9, 9};
    int n=6;
    for(int i=0;i<n;i++){
    	for(int j=0;j<n-1;j++){
    		if(f[j]>f[j+1]){
    			int temp=f[j];
    			f[j]=f[j+1];
    			f[j+1]=temp;
    			temp=s[j];
    			s[j]=s[j+1];
    			s[j+1]=temp;
			}
		}
	}
	int lastjobfinish;
	int jobs[n];
	for(int i=0;i<n;i++)
	jobs[i]=0;
	for(int i=0;i<n;i++){
		if(s[i]>lastjobfinish){
			jobs[i]=1;
			lastjobfinish=f[i];
		}
	}
		for(int i=0;i<n;i++)
	cout<<jobs[i]<< " ";
}
