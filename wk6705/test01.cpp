#include <iostream>
#include <vector>
#include <stdlib.h>

bool link(int a, int b){
	if(abs(a-b)==1 || a==b)
		return true;
	return false;
}


int snake(std::vector<std::vector<int>> v){
	int n = v.size();
	int m = v[0].size();
	std::vector<std::vector<int>> dp(n, std::vector<int>(m));
	int maxLen;
	for(int i=0; i < n; ++i){
		for(int j=0; j < m; ++j){
			if(j==0 && i==0){
				dp[i][j] = 0;
			}else if(j-1 >=0 && link(v[i][j], v[i][j-1])){
				dp[i][j] = std::max(dp[i][j], dp[i][j-1] + 1);
			}else if(i-1>=0 && link(v[i][j], v[i-1][j])){
				dp[i][j] = std::max(dp[i][j], dp[i-1][j] + 1);
			}
			maxLen = dp[i][j];
		}
	}
	return maxLen;
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
	std::cout << snake(v) << "\n";

	return 0;
}

