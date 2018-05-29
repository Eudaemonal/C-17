#include <iostream>
#include <vector>

int step(std::vector<int> v){
	std::vector<int> dp(v.size());
	int min;
	for(int i = 0 ; i<v.size(); ++i){
		if(i==0)
			dp[i] = 0;
		else{
			min = INT_MAX;
			for(int j=0; j < i; ++j){
				if(j+v[j] >= i && dp[j]+1 < min)
					min =dp[j]+1;
			}
			dp[i] = min;
		}
	}
	for(int i = 0; i < dp.size(); ++i){
		std::cout << dp[i] << " ";
	}
	std::cout << "\n";

	return 0;
}

int main(int argc, char *argv[]){
	int n;
	std::cin >> n;
	std::vector<int> v(n);
	for(int i=0; i < n; ++i){
		std::cin >> v[i];
	}
	std::cout << step(v) << "\n";
	return 0;
}
