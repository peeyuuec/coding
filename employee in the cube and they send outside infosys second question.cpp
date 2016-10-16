#include<iostream>
#define ARRAY_SIZE 10000000
int glb[10000007]={0};
using namespace std;
int positive(int a){
	if(a<0) a=-1*a;
	return a;
}
int calculate(int a[],int n,int left,int right){
	if(right<left)return 0;
	int sum=0;
	int mid=left+(right-left)/2;
	int num=-1;
	int index;
	for(int i=0;i<n;i++){
		if(a[i]>=left&&a[i]<=right&&a[i]!=-1){
			if(positive(mid-num)>positive(mid-a[i])){
				num=a[i];
				index=i;
			}
		}
	}
	if(num!=-1){
		a[index]=-1;
		sum=(right-left)+calculate(a,n,left,num-1)+calculate(a,n,num+1,right);	
	}
	
	return sum;
	
}
int main(){
	char *array= new char[ARRAY_SIZE]();
	int *aaaa=new int [ARRAY_SIZE]();
	aaaa[0]=1;
	string s;
	cin>>s;
	int num=0;
	int index=0;
	while(s[index]!='#'){
		num=num*10+(s[index]-'0');
		index++;
	}
	
	int len=s.length();
	int a[10000];
	int count=0;
	for(int i=index+1;i<len;i++){
		int t=0;
		while(i<len&&s[i]!=','){
			t= t*10+(s[i]-'0');
			i++;
		}
		a[count]=t;
		count++;
	}
	cout<<calculate(a,count,1,num);
	}
