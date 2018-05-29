#include <iostream>
#include <vector>
#include <list>
#include <utility>


bool checkbound(int elem, int lower, int upper){
	if(elem >= lower && elem < upper)
		return true;
	else 
		return false;
}


// use bfs to get the max area that one can get
int maxArea(std::vector<std::vector<int>> v, int i_idx, int j_idx){
	int n = v.size();
	int m = v[0].size();

	bool visited[n][m];
	int dp[n][m];
	dp[i_idx][j_idx] = 1;
	for(int i=0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			visited[i][j] = false;
		}
	}
	
	std::pair<int, int> adjs[4] = {{1,0},{-1,0}, {0,1}, {0,-1} };
	std::list<std::pair<int, int>> queue;
	visited[i_idx][j_idx] = true;
	queue.push_back(std::make_pair(i_idx, j_idx));

	while(!queue.empty()){
		auto s = queue.front();
		queue.pop_front();


		int min = INT_MAX;
		int n_i, n_j, p_i, p_j;
		for(int i = 0; i< 4 ; ++i ){
			if(checkbound(s.first + adjs[i].first, 0, n)  
				&& checkbound(s.second + adjs[i].second, 0, m)  
				&& !visited[s.first + adjs[i].first][s.second + adjs[i].second]
				&& v[s.first + adjs[i].first][s.second + adjs[i].second] < min){
					min = v[s.first + adjs[i].first][s.second + adjs[i].second];
					n_i = s.first + adjs[i].first;
					n_j = s.second + adjs[i].second;
				}
			}

		visited[n_i][n_j] = true;
		queue.push_back(std::make_pair(n_i, n_j));
		dp[n_i][n_j] = dp[s.first][s.second] + 1;
	}

	for(int i=0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			std::cout << dp[i][j] << " ";	
		}
		std::cout << "\n";
	}
	

	return 0;
}



int path(std::vector<std::vector<int>> v){
	int n = v.size();
	int m = v[0].size();
	int min = INT_MAX;
	int s_i, s_j;

	for(int i=0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			if(v[i][j] < min){
				min = v[i][j];
				s_i = i;
				s_j = j;
			}
		}
	}
	
	maxArea(v, s_i, s_j);

	return 0;
}

int main(int argc, char *argv[]){
	int n,m;
	std::cin >> n >> m;
	std::vector<std::vector<int>> v(n, std::vector<int>(m));

	for(int i=0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			std::cin >> v[i][j];
		}
	}

	std::cout << path(v); 
	return 0;
}
