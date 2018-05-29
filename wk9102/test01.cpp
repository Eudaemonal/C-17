#include <iostream>
#include <vector>

template <typename T>
std::ostream& operator<<(std::ostream& os, std::vector<std::vector<T>> v){
	for(int i=0; i < v.size(); ++i){
		for(int j=0; j < v[0].size(); ++j){
			os << v[i][j] << " ";
		}
		os << "\n";
	}
	return os;
}

void f(std::vector<std::vector<int>> v, int idx, int jdx, std::vector<int> path){
	int n = v.size();
	int m = v[0].size();
	path.push_back(v[idx][jdx]);
	
	if(idx < n-1 && jdx < m-1){
		f(v, idx+1, jdx, path);
		f(v, idx, jdx+1, path);
	}else if(idx < n-1 && jdx == m-1){
		f(v, idx+1, jdx, path);
	}else if(idx == n-1 && jdx < m-1){
		f(v, idx, jdx+1, path);
	}else if(idx == n-1 && jdx == m-1){
		for(auto it: path)
			std::cout << it << ", ";
		std::cout << "\n";
	}
	
}

int main(int argc, char *argv[]){
	int n, m;
	std::cin >> n >> m;
	std::vector<std::vector<int>> v(n, std::vector<int>(m));
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			std::cin >> v[i][j];
		}
	}
	std::vector<int> path;
	
	f(v, 0, 0, path);
	return 0;
}
