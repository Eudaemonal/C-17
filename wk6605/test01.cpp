#include <iostream>
#include <string>

int min(int x, int y, int z){
	return std::min(x, std::min(y, z));
}

int dist(std::string &x, std::string &y){
	int dp[x.length() + 1][y.length() + 1];
	for(int i = 0; i <= x.length(); ++i){
		for(int j= 0; j <= y.length(); ++j){
			if(i==0)
				dp[i][j] = j;
			else if(j==0)
				dp[i][j] = i;
			else if(x.at(i-1)==y.at(j-1))
				dp[i][j] = dp[i-1][j-1];
			else
				dp[i][j] = 1 + min(dp[i][j-1], dp[i-1][j], dp[i-1][j-1]);
		}
	}
	return dp[x.length()][y.length()];
}

int main(int argc, char *argv[]){
	std::string a, b;
	std::cin >> a >> b;
	std::cout << dist(a, b) << "\n";
	return 0;
}
