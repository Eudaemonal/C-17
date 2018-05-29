#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>

int main(int argc, char *argv[]){
	int n, a, b;
	std::cin >> n;
	std::vector<std::pair<int, int>> v(n);

	for(int i = 0; i < n; ++i){
		std::cin >> a >> b;
		v[i] = std::make_pair(a, b);
	}

	std::sort(v.begin(), v.end(), [&](auto x, auto y){
				return x.second < y.second;
		});

	for(auto it: v){
		std::cout << it.first << " "<< it.second << "\n";	
	}

	return 0;
}
