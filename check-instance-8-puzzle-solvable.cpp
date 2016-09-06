#include<iostream>
using namespace std;
#define N 3
void issolvable(int puzzle[N][N],int n){
	int inversion=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
		for(int p=j;p<n;p++){
			if(puzzle[i][p]!=0&&puzzle[i][j]>puzzle[i][p]){
				inversion++;
				
			}
		}
			for(int k=i+1;k<n;k++){
		for(int l=0;l<n;l++){
		
			if(puzzle[k][l]!=0&&puzzle[i][j]>puzzle[k][l]){
				inversion++;
				
			}
		}
	}
	cout<<endl;
		}
	}
	cout<<inversion<<endl;
	
	
	if(n%2!=0){
		if(inversion%2!=0){
			cout<<"Not Possible"<<endl;
		}
		else{
			cout<<"Possible"<<endl;
		}
	}
	else{
		if(inversion%2==0){
			cout<<"Not Possible"<<endl;
		}
		else{
			cout<<"Possible"<<endl;
		}
	}
	
	
}

int main(){
	int puzzle[3][3] =  {{1, 8, 2},
                      {0, 4, 3},  // Value 0 is used for empty space
                      {7, 6, 5}};
    issolvable(puzzle,3);
 
}
