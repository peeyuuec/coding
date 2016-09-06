#include<iostream>
#include<algorithm>
#include <vector>
#include <fstream>
using namespace std;
bool myfunction (int i,int j) { return (i<j); }
int main(){
	ofstream myfile;
	ifstream infile;
	infile.open("input.txt");
    myfile.open ("output.txt");
	int N;
	infile>>N;
	int answer[N][2];
	for(int i=0;i<N;i++){
		int c;
		int items;
		infile>>c>>items;
		int a[items];
		int temp[items];
		for(int j=0;j<items;j++){
			infile>>a[j];
			temp[j]=a[j];
		}
		sort (a, a+items); 
		int left=0,right=items-1;
		int sum=a[left]+a[right];
		while(sum!=c){
			if(sum>c){
				right--;
			}else{
				left++;
			}
			sum=a[left]+a[right];
		}
		for(int z=0;z<items;z++){
			if(temp[z]==a[left]){
				left=z;
				break;
			}
		}
		for(int z=items;z>=0;z--){
			if(temp[z]==a[right]){
				right=z;
				break;
			}
		}
		left++;
		right++;
		if(left<right){
			answer[i][0]=left;
			answer[i][1]=right;
			//cout<<"case #"<<i+1<<": "<<left<<" "<<right<<endl;
		}
		
		else{
			answer[i][0]=right;
			answer[i][1]=left;
			//cout<<"case #"<<i+1<<": "<<right<<" "<<left<<endl;
		}
	}
	for(int i=0;i<N;i++){
		myfile<<"case #"<<i+1<<": "<<answer[i][0]<<" "<<answer[i][1]<<endl;
	}
	myfile.close();
}
