#include <iostream>
#include <vector>

int ways(int m, std::vector<int> v){
	std::vector<int> dp(m+1);
	dp[0] = 1;
	for(auto elem: v){
		for(int i=elem; i <=m; ++i)
			dp[i] += dp[i-elem];
	}

	for(auto elem: dp)
		std::cout << elem << " ";
	std::cout << "\n";
	
	return dp.back();
}

int main(int argc, char *argv[]){
	int m, n;
	std::cin >>m >> n;
	std::vector<int> v(n);
	for(int i = 0; i < n; ++i){
		std::cin >> v[i];
	}

	std::cout << ways(m, v) << "\n";

	return 0;
}
