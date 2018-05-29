#include <iostream>
#include <vector>
#include <algorithm>

int mc(int w, std::vector<int> v){
	std::vector<int> dp(w+1);
	std::fill(dp.begin(), dp.end(), INT_MAX);

	for(int i=0; i<= w; ++i){
		if(i==0)
			dp[i]=0;
		else{
			for(int j=0; j<v.size(); ++j){
				if(j <= i && dp[i] > dp[i-j] + v[j]){
					dp[i] = dp[i-j] + v[j];
				}
			}
		}
	}
	return dp.back();
}

int main(int argc, char *argv[]){
	int w, n;
	std::cin >> w;
	std::cin >> n;
	std::vector<int> v(n+1);
	v[0] = 0;
	for(int i=1; i<= n; ++i){
		std::cin >> v[i];
	}

	std::cout << mc(w, v)<< "\n";
	return 0;
}
