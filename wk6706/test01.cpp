#include <iostream>
#include <vector>
#include <algorithm>


int mspsd(int k, std::vector<int> v){
	std::vector<int> dp(v.size());

	std::sort(v.begin(), v.end());

	dp[0] = 0;
	for(int i=1; i<v.size(); ++i){
		dp[i] = dp[i-1];
		if(v[i] - v[i-1] < k){
			if(i>=2)
				dp[i] = std::max(dp[i], dp[i-2] + v[i] + v[i-1]);
			else 
				dp[i] = std::max(dp[i], v[i] + v[i-1]);
		}
	}

	return dp.back();
}

int main(int argc, char *argv[]){
	int k, n;
	std::cin >> k >> n;
	std::vector<int> v(n);

	for(int i=0; i < n; ++i){
		std::cin >>v[i];
	}

	std::cout << mspsd(k, v) << "\n";
	return 0;
}
