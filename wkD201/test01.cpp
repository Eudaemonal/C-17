#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

std::ostream& operator<<(std::ostream& os, std::vector<std::pair<int, int>> v){
	for(auto it: v)
		os << it.first << ", "  << it.second << "\n";
	return os;
}


int main(int argc, char *argv[]){
	int n, a, b;
	std::cin >> n;
	std::vector<std::pair<int, int>> v(n);
	for(int i=0; i < n; ++i){
		std::cin >> a >> b;
		v[i] = std::make_pair(a ,b);
	}
	
	std::sort(v.begin(), v.end(), [](auto &a, auto &b){
		return a.second < b.second;		
	});

	std::cout << v;
	
	return 0;
}
