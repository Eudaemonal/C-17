#include <iostream>
#include <vector>



int get_max(std::vector<std::vector<int>> mat, int n, int m){
	std::vector<std::vector<int>> dp(n, std::vector<int>(m));
	for(int i = n-1; i >=0; --i){
		for(int j = m-1; j >=0; --j){
			if(i==n-1 && j==m-1){
				dp[i][j]= mat[i][j];
			}
			else if(i==n-1){
				dp[i][j]= mat[i][j] + dp[i][j+1];
			}
			else if(j==m-1){
				dp[i][j]= mat[i][j] + dp[i+1][j];
			}
			else{
				dp[i][j] = mat[i][j] + std::max(dp[i][j+1],dp[i+1][j] );
			}
		}
	}
	return dp[0][0];
}


int main(int argc, char *argv[]){
	int n, m;
	std::cin >> n >> m;
	std::vector<std::vector<int>> mat(n, std::vector<int>(m));
	for(int i=0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			std::cin >> mat[i][j];
		}
	}

	std::cout << get_max(mat, n, m) << "\n";
	
	
	return 0;
}
