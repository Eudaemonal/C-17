#include <iostream>
#include <vector>

// same argument as rec version only for simplicity
int solu_dp(std::vector<int> coeff, int start, int end, int rhs){
	std::vector<int> dp(rhs + 1);
	dp[0] = 1;
	
	for(int i=0; i < coeff.size(); ++i){
		for(int j = coeff[i];j <= rhs; j++){
			dp[j] = dp[j] + dp[j - coeff[i]];
		}
	}
	return dp.back();
}


int solu_rec(std::vector<int> coeff, int start, int end, int rhs){
	if(rhs==0)
		return 1;
	int result = 0;
	for(int i=start; i < end; ++i){
		if(rhs >= coeff[i])
			result += solu_rec(coeff, i, end, rhs-coeff[i]);
	}
	return result;
}

int main(int argc, char *argv[]){
	int rhs, n;
	std::cin >> rhs;
	std::cin >> n;
	std::vector<int> coeff(n);
	for(int i=0; i < n; ++i){
		std::cin >> coeff[i];
	}

	std::cout << solu_rec(coeff,0,n, rhs) << "\n";
	return 0;
}
