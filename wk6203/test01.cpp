#include <iostream>
#include <vector>



int main(int argc, char *argv[]){
	int n;
	std::cin >> n;
	std::vector<int> v(n);
	int min;

	for(int i = 0; i < n; ++i){
		std::cin >> v[i];
	}
	
	std::vector<int> dp(n);
	for(int i = 0; i<n; ++i){
		if(i==0)
			dp[i] = 0;
		else{
			min = INT_MAX;
			for(int j = 0; j < i; ++j){
				if(v[j]+j>=i){
					if(dp[j] + 1 < min)
						min = dp[j]+1;
				}
				dp[i] = min;
			}
		}
	}
	std::cout << dp[n-1];

	
	return 0;
}
