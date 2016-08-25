#include<iostream>
#include<math.h>
using namespace std;
int fillreachmatrix(int reach[],int i){
	switch (i){
		case 0:{
			reach[0]=1;
			reach[8]=1;
			break;
		}
		case 1:{
			reach[1]=1;
			reach[2]=1;
			reach[4]=1;
			break;
		}
		case 2:{
			reach[2]=1;
			reach[1]=1;
			reach[3]=1;
			reach[5]=1;
			break;
		}
		case 3:{
				reach[2]=1;
			reach[6]=1;
			reach[3]=1;
			break;
		}case 4:{
			reach[4]=1;
			reach[1]=1;
			reach[7]=1;
			reach[5]=1;
			break;
		}
		case 5:{
			reach[5]=1;
			reach[2]=1;
			reach[4]=1;
			reach[8]=1;
			reach[6]=1;
			break;
		}
		case 6:{
			reach[6]=1;
			reach[3]=1;
			reach[5]=1;
			reach[9]=1;
			break;
		}
		case 7:{
			reach[7]=1;
			reach[4]=1;
			reach[8]=1;
			
			break;
		}
		case 8:{
			reach[8]=1;
			reach[5]=1;
			reach[7]=1;
			reach[9]=1;
			reach[0]=1;
			break;
		}
		case 9:{
			reach[9]=1;
			reach[8]=1;
			reach[6]=1;
			break;
		}
	}
}
void totalpossibledynamin(int n){

    int reach[10];
    int temp[10];
    int total=0;
 
    for(int j=0;j<=9;j++){
    	   for(int i=0;i<10;i++){
    	reach[i]=0;
	}
    	//fillreachmatrix(reach,j);	
		reach[j]=1;
    for(int i=2;i<=n;i++){
    	for(int q=0;q<10;q++){
    	cout<<reach[q]<<" ";
	}cout<<endl;
		for(int p=0;p<10;p++){
			temp[p]=reach[p];
		}
    	if(temp[0]>0){
    		reach[8]+=temp[0];
    		
		}
		if(temp[1]>0){
    		reach[2]+=temp[1];
    		reach[4]+=temp[1];
    		
		}
		if(temp[2]>0){
    		reach[1]+=temp[2];
    		reach[3]+=temp[2];
    		reach[5]+=temp[2];
		}
		if(temp[3]>0){
    		reach[2]+=temp[3];
    		reach[6]+=temp[3];
    		
		}
		if(temp[4]>0){
    		reach[1]+=temp[4];
    		reach[5]+=temp[4];
    		reach[7]+=temp[4];
		}
		if(temp[5]>0){
    		reach[2]+=temp[5];
    		reach[4]+=temp[5];
    		reach[6]+=temp[5];
    		reach[8]+=temp[5];
		}
		if(temp[6]>0){
    		reach[3]+=temp[6];
    		reach[5]+=temp[6];
    		reach[9]+=temp[6];
		}
		if(temp[7]>0){
    		reach[8]+=temp[7];
    		reach[4]+=temp[7];
		}
		if(temp[8]>0){
    		reach[0]+=temp[8];
    		reach[5]+=temp[8];
    		reach[7]+=temp[8];
    		reach[9]+=temp[8];
		}
		if(temp[9]>0){
    		reach[6]+=temp[9];
    		reach[8]+=temp[9];
		}
			
	}
	for(int q=0;q<10;q++){
    	cout<<reach[q]<<" ";
	}cout<<endl;
cout<<endl;
	total=total+reach[0]+reach[1]+reach[2]+reach[3]+reach[4]+reach[5]+reach[6]+reach[7]+reach[8]+reach[9];
	 //total=total+reach[0]*2+reach[1]*3+reach[2]*4+reach[3]*3+reach[4]*4+reach[5]*5+reach[6]*4+reach[7]*3+reach[8]*5+reach[9]*3;
}
cout<<total<<endl;
}
int count;
void printnumbers(int i,int n,char s[],int index){
	

		s[index]=char('0'+i);
		s[index+1]='\0';
		//cout<<char('0'+i);
		index++;
			if(index>=n){
	cout<<s<< " ";
	count++;
	return;}
	switch(i){
		case 0:{
			printnumbers(0,n,s,index);
			printnumbers(8,n,s,index);
			break;
		}
				case 1:{
			printnumbers(1,n,s,index);
			printnumbers(2,n,s,index);
			printnumbers(4,n,s,index);
			break;
		}
				case 2:{
			
			printnumbers(2,n,s,index);
			printnumbers(3,n,s,index);
			printnumbers(1,n,s,index);
			printnumbers(5,n,s,index);
			break;
		}
				case 3:{
			
			printnumbers(3,n,s,index);
			printnumbers(2,n,s,index);
			printnumbers(6,n,s,index);
			break;
		}
				case 4:{
			 
			printnumbers(4,n,s,index);
			printnumbers(5,n,s,index);
			printnumbers(7,n,s,index);
			printnumbers(1,n,s,index);
			break;
		}
				case 5:{
			 
			printnumbers(5,n,s,index);
			printnumbers(2,n,s,index);
			printnumbers(4,n,s,index);
			printnumbers(6,n,s,index);
			printnumbers(8,n,s,index);
			break;
		}
				case 6:{
			 
			printnumbers(6,n,s,index);
			printnumbers(3,n,s,index);
			printnumbers(5,n,s,index);
			printnumbers(9,n,s,index);
			
			break;
		}
				case 7:{
			 
			printnumbers(7,n,s,index);
			printnumbers(4,n,s,index);
			printnumbers(8,n,s,index);
			
			break;
		}
				case 8:{
			 
			printnumbers(8,n,s,index);
			printnumbers(5,n,s,index);
			printnumbers(7,n,s,index);
			printnumbers(9,n,s,index);
			printnumbers(0,n,s,index);
			break;
		}
				case 9:{
		 
			printnumbers(9,n,s,index);
			printnumbers(8,n,s,index);
			printnumbers(6,n,s,index);
			break;
		}
		
		
	}
}
int main(){
	int n=4;
	char s[n+1];
	s[0]='\0';
	int index=0;
	count=0;
	for(int i=0;i<10;i++){
		printnumbers(i,n,s,index);
		cout<<endl;
		
	}
	cout<<count<<endl;
	totalpossibledynamin(5);
}
