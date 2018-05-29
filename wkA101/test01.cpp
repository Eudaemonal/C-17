#include <iostream>
#include <vector>

template <typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<std::vector<T>> &v){
	for(size_t i=0; i < v.size(); ++i){
		for(size_t j=0; j < v[0].size(); ++j){
			os << v[i][j] << " ";
		}
		os << "\n";
	}
	return os;
}

int f(int color, std::vector<std::vector<int>> v){
	int n = v.size();
	int m = v[0].size();
	for(int i=1; i <= color; ++i){
		
	}

	return 0;
}

int main(int argc, char *argv[]){
	int color, n, m;
	std::cin >> color;
	std::cin >> n >> m;
	std::vector<std::vector<int>> v(n, std::vector<int>(m));
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			std::cin >> v[i][j];
		}
	}
	
	std::cout << f(v) << "\n";
	return 0;
}
