#include <iostream>
#include <vector>
#include <queue>



/* Graph
 * undirected unweighted

2d array     bfs, dfs
adj matrix   
adj list    


 * undirected weighted

 * directed unweighted

adj list    dijkstra

 * directed weighted


 * */


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

bool valid(int i, int j, int n, int m, std::vector<std::vector<bool>> &visited){
	if(i>=0 && i<n && j >=0 && j < m){
		return !visited[i][j];
	}
	return false;
}

int bfs(int s_i, int s_j, std::vector<std::vector<int>> v){
	int n = v.size();
	int m = v[0].size();

	std::vector<std::vector<bool>> visited(n, std::vector<bool>(m));
	std::vector<std::vector<int>> level(n, std::vector<int>(m));

	std::vector<std::pair<int, int>> adj = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

	std::queue<std::pair<int, int>> q;
	q.push(std::make_pair(s_i, s_j));
	visited[s_i][s_j] = true;
	level[s_i][s_j] = 1;
	

	while(!q.empty()){
		std::pair<int, int> s = q.front();
		q.pop();
		std::cout << s.first << " " << s.second << "\n";

		for(int i= 0; i < adj.size(); ++i){
			if(valid(adj[i].first + s.first, adj[i].second+ s.second, n, m, visited)){
				q.push(std::make_pair(adj[i].first + s.first, adj[i].second+ s.second));
				visited[adj[i].first + s.first][adj[i].second+ s.second] = true;
				level[adj[i].first + s.first][adj[i].second+ s.second] = level[s.first][s.second] + 1;
			}	
		}
	}

	std::cout << "level\n";
	std::cout << level;

	return 0;
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
	
	std::cout << bfs(0, 0, v) << "\n";
	return 0;
}
