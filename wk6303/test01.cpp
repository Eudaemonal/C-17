#include <iostream>
#include <vector>

int coin_change(int n, int i, std::vector<int> coins){
	if(n==0)
		return 1;
	if(n < 0)
		return 0;
	if(i<=0 && n>=1)
		return 0;

	return coin_change(n, i-1, coins) + coin_change(n-coins[i-1], i, coins);

}

int main(int argc, char *argv[]){
	int m;
	int n;
	std::cin >> m >> n;
	std::vector<int> coins(n);
	for(int i = 0; i < n; ++i){
		std::cin >> coins[i];
	}
	
	std::cout << coin_change(m,coins.size(), coins) << "\n";
	return 0;
}
