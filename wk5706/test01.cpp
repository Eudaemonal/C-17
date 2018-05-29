#include <iostream>
#include <vector>



int get_min(std::vector<std::vector<int>> mat, int n, int m){
	std::vector<std::vector<int>> dp(n, std::vector<int>(m));
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			if(i==0 && j==0){
				dp[i][j]= mat[i][j];
			}
			else if(i==0){
				dp[i][j]= mat[i][j] + dp[i][j-1];
			}
			else if(j==0){
				dp[i][j]= mat[i][j] + dp[i-1][j];
			}
			else{
				dp[i][j] = mat[i][j] + std::min(dp[i][j-1], std::min(dp[i-1][j], dp[i-1][j-1]));
			}
		}
	}
	return dp[m-1][n-1];
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
	
	std::cout << get_min(mat, n, m) << "\n";
	
	
	return 0;
}

