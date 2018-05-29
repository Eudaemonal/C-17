#include <iostream>
#include <vector>
#include <utility>



int knapsack(int w, std::vector<std::pair<int, int>> v){
	int n = v.size();
	int dp[n+1][w+1];
	for(int i=0; i<= n; ++i){
		for(int j=0; j <=w; ++j){
			if(i==0 || j==0)
				dp[i][j] = 0;
			else if(v[i-1].second <= w)
				dp[i][j] = std::max(dp[i-1][j], v[i-1].first + dp[i-1][j-v[i-1].second]);
			else 
				dp[i][j] = dp[i-1][j];
		}
	}
	return dp[n][w];
}

int main(int argc, char *argv[]){
	int w, n, value, weight;
	std::cin >> w >> n;
	std::vector<std::pair<int, int>> v(n);
	for(int i=0; i < n; ++i){
		std::cin >> value >> weight;
		v[i] = std::make_pair(value, weight);
	}

	std::cout << knapsack(w, v) << "\n";
	return 0;
}
