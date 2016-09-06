#include<iostream>
#include<fstream>
using namespace std;
int merge(int a[],int left,int mid,int right){
    int l1=mid-left+1;
    int l2=right-mid;
    int temp[l1+l2];
    int l=left;
    int r=mid+1;
    int index=0;
    int result=0;
    while(l<=mid&&r<=right){
        if(a[l]>a[r]){
            temp[index]=a[r];
            result++;
            index++;
            r++;
        }
        else{
            temp[index]=a[l];
            l++;
            index++;
        }
    }
    while(l<=mid){
        temp[index]=a[l];
            l++;
            index++;
    }
    while(r<=right){
        temp[index]=a[r];
            
            index++;
            r++;
    }
    index=0;
    for(int i=left;i<=right;i++){
        a[i]=temp[index];
        index++;
    }
    return result;
}
int utility(int a[],int left,int right){
    if(left>=right) return 0;
    int mid=left+(right-left)/2;
    int aval=utility(a,left,mid);
    int bval=utility(a,mid+1,right);
    int cval=merge(a,left,mid,right);
    //cout<<aval<<" "<<bval<<" "<<cval<<endl;
    return aval+bval+cval;
}
int sorting(int a[],int n){
    int bribe=0;
    bribe=utility(a,0,n-1);
    for(int i=0;i<n;i++){
    	cout<<a[i]<<" ";
	}
    return bribe;
}

int main(){
	ofstream myfile;
	ifstream infile;
	infile.open("input.txt");
    myfile.open ("output.txt");
    int T;
    infile >> T;
    for(int a0 = 0; a0 < T; a0++){
        int n;
        infile >> n;
        int a[n];
        for(int i=0;i<n;i++){
            infile>>a[i];
        }
        int bribe=0;
        int yes=1;
        for(int i=0;i<n;i++){
            if(a[i]>i+1){
                if(a[i]-i-1>2){
                    yes=0;
                    break;
                }
            }
        }
        if(yes==0){
            cout<<"Too chaotic"<<endl;
        }else{
           //bribe=sorting(a,n);
            for(int i=0;i<n;i++){
            	int swap=0;
                for(int j=0;j<n-1;j++){
                    if(a[j]>a[j+1]){
                        bribe++;
                        int temp=a[j];
                        a[j]=a[j+1];
                        a[j+1]=temp;
                        swap=1;
                    }
                }
                if(swap==0)break;
            }
            cout<<bribe<<endl;
        }
        
        // your code goes here
    }
    return 0;
}

