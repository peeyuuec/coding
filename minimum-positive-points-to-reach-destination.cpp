#include<iostream>
using namespace std;
int main(){
	int R=3,C=3;
	
	int points[R][C] = { {-2,-3,3},
                      {-1,-10,1},
                      {10,30,-5}};
        int a[R][C];
                      for(int i=0;i<R;i++){
                      	for(int j=0;j<C;j++){
                      		a[i][j]=points[i][j];
						  }
					  }
					  a[R-1][C-1]=1;
					  for(int i=R-2;i>=0;i--){
					  	int temp=a[i+1][C-1]-points[i+1][C-1];
					  	if(temp<=0){
					  		a[i][C-1]=1;
						  }
						  else{
						  	a[i][C-1]=temp;
						  }
					  	
					  }
					    for(int i=C-2;i>=0;i--){
					  	int temp=a[R-1][i+1]-points[R-1][i+1];
					  	if(temp<=0){
					  		a[R-1][i]=1;
						  }
						  else{
						  	a[R-1][i]=temp;
						  }
					  	
					  }
		
		for(int i=R-2;i>=0;i--){
            for(int j=C-2;j>=0;j--){
                      		
                a[i][j]=min(a[i+1][j]-points[i+1][j],a[i][j+1]-points[i][j+1]);
                if(a[i][j]<=0){
                	a[i][j]=1;
				}
						  }
					  }
					  for(int i=0;i<R;i++){
					  	for(int j=0;j<C;j++){
					  		cout<<a[i][j]<<" ";
					  		
						  }cout<<endl;
						  
					  }
					  cout<<a[0][0]-points[0][0];
                      
}
