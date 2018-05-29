#include <iostream>
#include <string>

int lcs(std::string &x, std::string &y){
	int dp[x.length()+1][y.length()+1];
	for(int i = 0; i <= x.length(); ++i){
		for(int j=0; j <= y.length(); ++j){
			if(i==0 || j==0)
				dp[i][j] = 0;
			else if(x.at(i-1)==y.at(j-1))
				dp[i][j] = dp[i-1][j-1] + 1;
			else
				dp[i][j] = std::max(dp[i-1][j], dp[i][j-1]);
		}
	}
	return dp[x.length()][y.length()];
}

int main(int argc, char *argv[]){
	std::string a, b;
	std::cin >> a >> b;
	std::cout << lcs(a, b) << "\n";
	return 0;
}
