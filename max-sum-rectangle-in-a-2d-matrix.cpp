#include<iostream>
using namespace std;
int mximumsumsubarray(int *a,int n){
	int max=0;

	
	int sumtillnow=0;
	for(int i=0;i<n;i++){
		sumtillnow=sumtillnow+a[i];
	 
		if(sumtillnow<0)sumtillnow=0;
		if(sumtillnow>max)max=sumtillnow;
		
	}
	if(max==0){
		max=a[0];
			for(int i=1;i<n;i++){
		if(a[i]>max){
			max=a[i];
		}
		}
	}
	
	return max;
}
int maximumsumsubmatrix(){
		int ROW=4;
	int COL=5;
	int M[ROW][COL] = {{ 1,  2, -1,  -4, -20},
                       {-8, -3,  4,  2,   1},
                       { 3,  8,  10, 1,   3},
                       {-4, -1,  1,  7,  -6}
                      };
              int sum[ROW][COL];
              for(int i=0;i<ROW;i++){
              	for(int j=1;j<COL;j++){
              		sum[i][j]=sum[i][j-1]+M[i][j];
				  }
			  }
			  int temp[ROW];
			  int max=0;
			  for(int i=0;i<COL;i++){
			  	for(int j=i;j<COL;j++){
			  		for(int p=0;p<ROW;p++){
			  			temp[p]=sum[p][j]-sum[p][i]+M[p][i];
					  }
					  int newsum=mximumsumsubarray(temp,COL);
					  if(max<newsum){
					  max=newsum;
					  cout<<max<<" ";
				}
				  }
			  }
			  return max;
}
int main(){
        	int M[5] = {1,-2, 1, 2, -20};
        	cout<<mximumsumsubarray(M,5)<<endl;
        	cout<<maximumsumsubmatrix()<<endl;
}
