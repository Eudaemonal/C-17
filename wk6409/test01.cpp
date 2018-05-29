#include <iostream>
#include <vector>
#include <algorithm>


int lis(std::vector<int> v){
	std::vector<int> dp(v.size());
	for(int i =0; i < v.size(); ++i){
		if(i==0)
			dp[i]=1;
		else{
			for(int j = 0; j < i; ++j){
				if(v[j] < v[i] && dp[i] < dp[j] + 1)
					dp[i] = dp[j] + 1;
			}
		}
	}

	return dp.back();
}

int msis(std::vector<int> v){
	std::vector<int> dp(v.size());
	for(int i =0; i < v.size(); ++i){
		if(i==0)
			dp[i]=v[i];
		else{
			for(int j = 0; j < i; ++j){
				if(v[j] < v[i] && dp[i] < dp[j] + v[i])
					dp[i] = dp[j] + v[i];
			}
		}
	}

	return *std::max_element(dp.begin(), dp.end());
}

int main(int argc, char *argv[]){
	int n;
	std::cin >> n;
	std::vector<int> v(n);
	for(int i= 0; i < n; ++i){
		std::cin >> v[i];
	}
	std::cout << msis(v) << "\n";
	
	return 0;
}
