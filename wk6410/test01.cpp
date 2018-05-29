#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>


int mlcp(std::vector<std::pair<int, int>> v){
	std::vector<int> dp(v.size());
	std::sort(v.begin(), v.end(), [](auto &a, auto &b){
		return a.second < b.second;		
	});
	
	for(int i = 0; i < v.size(); ++i){
		if(i==0)
			dp[i] = 1;
		else{
			for(int j = 0; j < i; ++j){
				if(v[j].second < v[i].first && dp[i] < dp[j]+1)
					dp[i] = dp[j]+1;
			}
		}
	}
	return dp.back();
}

int main(int argc, char *argv[]){
	int n, a, b;
	std::cin >> n;
	std::vector<std::pair<int,int>> v(n);
	for(int i=0; i < n; ++i){
		std::cin >> a >> b;
		v[i] = std::make_pair(a, b);
	}
	std::cout << mlcp(v) << "\n";

	
	return 0;
}
