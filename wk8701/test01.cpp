#include <iostream>
#include <vector>
#include <utility>

int knapSack(int W, std::vector<std::pair<int, int>> v){
	int n = v.size();
	int dp[n+1][W+1];
	for(int i=0; i <= n; ++i){
		for(int j = 0; j <= W; ++j){
			if(i==0 || j==0)
				dp[i][j] = 0;
			else if(j >= v[i-1].second)
				dp[i][j] = std::max(dp[i-1][j-v[i-1].second] + v[i-1].first, dp[i-1][j]);
			else 
				dp[i][j] = dp[i-1][j];
		}
	}
	
	return dp[n][W];
}


int main(int argc, char *argv[]){
	std::vector<std::pair<int, int>> v = {{60, 10}, {100, 20}, {120, 30}};
	int W = 50;
	std::cout << knapSack(W, v) << "\n";

	return 0;
}
