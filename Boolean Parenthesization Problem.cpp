#include<iostream>
using namespace std;
int countParenth(char symb[], char oper[], int n)
{
    int F[n][n], T[n][n];
 
    // Fill diaginal entries first
    // All diagonal entries in T[i][i] are 1 if symbol[i]
    // is T (true).  Similarly, all F[i][i] entries are 1 if
    // symbol[i] is F (False)
    for (int i = 0; i < n; i++)
    {
        F[i][i] = (symb[i] == 'F')? 1: 0;
        T[i][i] = (symb[i] == 'T')? 1: 0;
    }
 
    // Now fill T[i][i+1], T[i][i+2], T[i][i+3]... in order
    // And F[i][i+1], F[i][i+2], F[i][i+3]... in order
    for (int gap=1; gap<n; gap++)
    {
    	
        for (int i=0, j=gap; j<n; i++, j++)
        {
        	
        int index2=i+gap-1;
            T[i][j] = F[i][j] = 0;
            for (int g=0; g<gap; g++)
            {
                // Find place of parenthesization using current value
                // of gap
                int k = i + g;
 
                // Store Total[i][k] and Total[k+1][j]
                int tik = T[i][k] + F[i][k];
                int tkj = T[k+1][j] + F[k+1][j];
 
                // Follow the recursive formulas according to the current
                // operator
                if (oper[k] == '&')
                {
                    T[i][j] += T[i][k]*T[k+1][j];
                    F[i][j] += (tik*tkj - T[i][k]*T[k+1][j]);
                }
                if (oper[k] == '|')
                {
                    F[i][j] += F[i][k]*F[k+1][j];
                    T[i][j] += (tik*tkj - F[i][k]*F[k+1][j]);
                }
                if (oper[k] == '^')
                {
                    T[i][j] += F[i][k]*T[k+1][j] + T[i][k]*F[k+1][j];
                    F[i][j] += T[i][k]*T[k+1][j] + F[i][k]*F[k+1][j];
                }
            }
        }
    }
    return T[0][n-1];
}
int main(){
	char symbols[] = "TTFT";
    char operators[] = "|&^";
    int n = strlen(symbols);
    int T[n][n],F[n][n];
    for(int i=0;i<n;i++){
    	if(symbols[i]=='F'){
    		T[i][i]=0;
    		F[i][i]=1;
		}else{
				T[i][i]=1;
    		F[i][i]=0;
		}
	}
    for(int L=2;L<=n;L++){
    	int index1=n-L+1;
    	for(int i=0;i<index1;i++){
    	int	index2=i+L-1;
    		T[i][index2]=0;
    		F[i][index2]=0;
    		for(int j=i;j<index2;j++){
    			int total_i_to_j=T[i][j]+F[i][j];
    			int total_j_to_index2=T[j+1][index2]+F[j+1][index2];
    			switch(operators[j]){
    				case '|':{
						T[i][index2]+=(total_i_to_j*total_j_to_index2- F[i][j]*F[j+1][index2]);
						F[i][index2]+=F[i][j]*F[j+1][index2];
						break;
					} 
    				case '&': {
    						T[i][index2]+=T[i][j]*T[j+1][index2];
    						F[i][index2]+=(total_i_to_j*total_j_to_index2-T[i][j]*T[j+1][index2]);
						break;
					}
    				case '^': {
    					T[i][index2]+=(F[i][j]*T[j+1][index2]+T[i][j]*F[j+1][index2]);
    					T[i][index2]+=(F[i][j]*F[j+1][index2]+T[i][j]*T[j+1][index2]);
						break;
					}
    				
				}
			}
		}
	}
	cout<<F[0][3]<<endl<<endl;
	 cout << countParenth(symbols, operators, n)<<endl;
	 for(int i=0;i<4;++i){
	 	//cout<<i<<endl;
	 }
}
