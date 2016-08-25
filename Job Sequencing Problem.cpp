#include<iostream>
using namespace std;
int main(){
int n=5;
	 int arr[4][3] = { {'a', 4, 20}, {'b', 1, 10}, {'c', 1, 40},
                   {'d', 1, 30}};
 
    char jobs[n];
    int done[n];
    for(int i=0;i<n;i++)
    {
	jobs[i]='#';
	done[i]=0;
}
    for(int i=0;i<n;i++){
    	int max=0,index;
    	for(int j=0;j<n;j++){
    		if(done[j]!=1&&max<arr[j][2]){
    			max=arr[j][2];
    			index=j;
			}
		}
		for(int i=arr[index][1]-1;i>=0;i--){
			if(jobs[i]=='#'){
				jobs[i]=arr[index][0];
			break;
			}	
		}
		done[index]=1;
	}
   for(int i=0;i<n;i++)
    {
cout<<jobs[i]<<" ";
}	
}
