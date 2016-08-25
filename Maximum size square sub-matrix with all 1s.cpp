#include<iostream>
using namespace std;
int main(){
	int R=6,C=5;
	 bool M[R][C] =  {{0, 1, 1, 0, 1}, 
                   {1, 1, 0, 1, 0}, 
                   {0, 1, 1, 1, 0},
                   {1, 1, 1, 1, 0},
                   {1, 1, 1, 1, 1},
                   {0, 0, 0, 0, 0}};
    int A[R][C];
         for(int i=0;i<R;i++){
         
         	A[i][0]=M[i][0];
		 }   
		         for(int i=0;i<C;i++){
         
         	A[0][i]=M[0][i];
		 }         
		 for(int i=1;i<R;i++){
		 	for(int j=1;j<C;j++){
		 		if(M[i][j]==0) A[i][j]=0;
		 		else{
		 			int min;
		 			
		 			int leftmatrix=A[i][j-1];
		 			int abovematrix=A[i-1][j];
		 			min=leftmatrix<abovematrix?leftmatrix:abovematrix;
		 			if(M[i-min][j-min]==1){
		 				A[i][j]=min+1;
					 }else{
					 	A[i][j]=min;
					 }
				 }
			 }
		 }
	 for(int i=0;i<R;i++){
         for(int j=0;j<C;j++){
         	cout<<A[i][j]<<" ";
		 }   	 cout<<endl;}
}
