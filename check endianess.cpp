#include <stdio.h>
 #include<iostream>
 using namespace std;
/* function to show bytes in memory, from location start to start+n*/
void show_mem_rep(char *start, int n) 
{
    int i;
    for (i = 0; i < n; i++)
         printf(" %.2x", start[i]);
    printf("\n");
}
 
/*Main function to call above function for 0x01234567*/
int main()
{
   int i = 0x01234567;
   
   //printf("%2d\n",1234);
   cout<<printf(" %2x\n", *&i);
   show_mem_rep((char *)&i, sizeof(i));
  // getchar();
  int a[100000];
   return 0;
}

