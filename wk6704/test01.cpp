#include <iostream>
#include <vector>


double maxPath(std::vector<std::vector<int>> v){
	int n = v.size();
	int m = v[0].size();
	std::vector<std::vector<int>> dp(n, std::vector<int>(m));
	double step = n + m -1;
	for(int i=0; i < n; ++i){
		for(int j=0; j < m; ++j){
			if(i==0 && j==0){
				dp[i][j] = v[i][j];
			}else if(i==0){
				dp[i][j] = v[i][j] + dp[i][j-1];
			}else if(j==0){
				dp[i][j] = v[i][j] + dp[i-1][j];
			}else{
				dp[i][j] = v[i][j] + std::max(dp[i-1][j], dp[i][j-1]);
			}
		}
	}
	return (double)dp[n-1][m-1]/step;
}


int main(int argc, char *argv[]){
	int n, m;
	std::cin >> n >> m;
	std::vector<std::vector<int>> v(n, std::vector<int>(m));
	
	for(int i=0; i < n; ++i){
		for(int j=0; j < m; ++j){
			std::cin >> v[i][j];
		}
	}
	std::cout << maxPath(v) << "\n";

	return 0;
}
