#include <iostream>

#define MAX 5

int maxCost(int mat[][MAX], int n){
	int dp[MAX][MAX];

	memset(dp, 0, MAX*MAX);
	for(int i=0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			if(i==0 && j==0)
				dp[i][j] = mat[i][j];
			else{
				if(j-1 <0)
					dp[i][j] = mat[i][j] + dp[i-1][j];
				else if(i==j)
					dp[i][j] = mat[i][j] + dp[i-1][j-1];
				else
					dp[i][j] = std::max(mat[i][j] + dp[i-1][j], mat[i][j] + dp[i-1][j-1]);
				
			}
		}
	}
	int max = 0;
	for(int i=0; i < n; ++i){
		if(max < dp[MAX-1][i])
			max = dp[MAX-1][i];
	}

	return max;
}


int main(int argc, char *argv[]){
	int mat[MAX][MAX] = {  
		{  4,  1,  5,  6, 1 },
        	{  2,  9,  2, 11,10 },
        	{ 15,  1,  3, 15, 2 },
        	{ 16, 92, 41,  4, 3 },
        	{  8,142,  6,  4, 8 }
    	};
    
	int n = 5;
    
	std::cout << maxCost(mat, n) <<"\n";
	return 0;
}
