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

int maze(std::vector<std::vector<int>> v){
	int n = v.size();
	int m = v[0].size();
	for(int i=0; i < n; ++i){
		if(v[i][0]==0)
			v[i][0] = 1;
		else 
			break;
	}
	for(int j=1; j < m; ++j){
		if(v[0][j]==0)
			v[0][j] = 1;
		else
			break;
	}

	for(int i=1; i < n; ++i){
		for(int j=1; j < m; ++j){

			if(v[i][j]==-1)
				continue;
			if(v[i-1][j] > 0)
				v[i][j] = v[i][j] + v[i-1][j];
			if(v[i][j-1] > 0)
				v[i][j] = v[i][j] + v[i][j-1];
		}
	}

	std::cout << v;
	return (v[n-1][m-1]>0)?v[n-1][m-1]:0;

	return 0;
}


int main(int argc, char *argv[]){
	int n, m;
	std::cin >> n >> m;
	std::vector<std::vector<int>> v(n, std::vector<int>(m));
	for(int i=0; i < n; ++i){
		for(int j=0; j < m; ++j){
			std::cin >> v[i][j];
		}
	}
	std::cout << maze(v) << "\n";

	return 0;
}
