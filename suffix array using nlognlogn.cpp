#include<iostream>
using namespace std;
void sorting(int rank1[],int rank2[],int sorted[],int n){
		for(int i=0;i<n;i++){
		cout<<rank1[i]<<" "<<rank2[i]<<" "<<sorted[i]<<endl;
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n-1;j++){
			if(rank1[j]>rank1[j+1]||(rank1[j]==rank1[j+1]&&rank2[j]>rank2[j+1])){
				int temp=rank1[j];
				rank1[j]=rank1[j+1];
				rank1[j+1]=temp;
				temp=rank2[j];
				rank2[j]=rank2[j+1];
				rank2[j+1]=temp;
				temp=sorted[j];
				sorted[j]=sorted[j+1];
				sorted[j+1]=temp;
			}
		}
	}
	cout<<"sorting"<<endl;
	for(int i=0;i<n;i++){
		cout<<rank1[i]<<" "<<rank2[i]<<" "<<sorted[i]<<endl;
	}
}
void suffixarray(char str[]){
	int n=strlen(str);
	char *suffix[n];
	int sorted[n];
	int reverse[n];
	for(int i=0;i<n;i++){
		
		suffix[i]=(str+i);
		sorted[i]=i;
		reverse[sorted[i]]=i;
	}
	int rank1[n],rank2[n];
	for(int i=0;i<n;i++){
		rank1[i]=suffix[i][0]-'a';
	}


	int index=1;
	while(index<2*n){
		cout<<"step"<<endl;
		
			for(int i=0;i<n;i++){
		if(sorted[i]+1<n){
			rank2[i]=rank1[reverse[sorted[i]+1]];
		}
		else{
			rank2[i]=-1;
		}
		
	}
	for(int i=0;i<n;i++){
		cout<<rank1[i]<<" "<<rank2[i]<<endl;
	}
	sorting(rank1,rank2,sorted,n);
	for(int i=0;i<n;i++){
		reverse[sorted[i]]=i;
	}
		int temp[n];
		temp[0]=0;
	for(int i=1;i<n;i++){
		if(rank1[i]==rank1[i-1]&&rank2[i]==rank2[i-1]){
			temp[i]=temp[i-1];
		}
		else{
			temp[i]=temp[i-1]+1;
		}
	}
	
		for(int i=0;i<n;i++){
			rank1[i]=temp[i];
		}
		index=index*2;
	
	}
			for(int i=0;i<n;i++){
	cout<<sorted[i]<<" ";
	}
	
}
int main(){
		char str[]="banana";
		suffixarray(str);
}
