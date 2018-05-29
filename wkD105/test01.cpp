#include <iostream>
#include <vector>
#include <deque>
#include <utility>

template <typename T>
std::ostream& operator<<(std::ostream& os, std::vector<std::vector<T>> v){
	for(int i=0 ; i < v.size(); ++i){
		for(int j=0; j < v[0].size(); ++j){
			os << v[i][j] << " ";
		}
		os << "\n";
	}
	return os;
}


bool valid(int i, int j, int n, int m){
	if(0<=i && i<n && 0<=j && j<m)
		return true;
	return false;
}

void bfs(std::vector<std::vector<int>> v, int si, int sj){
	int n = v.size();
	int m = v[0].size();

	std::vector<std::vector<bool>> visited(n, std::vector<bool>(m));
	std::deque<std::pair<int, int>> queue;

	queue.push_back(std::make_pair(si, sj));
	visited[si][sj] = true;

	std::vector<std::pair<int, int>> adj = {{-1,0}, {1,0}, {0,1}, {0,-1}};
	while(!queue.empty()){
		std::pair<int, int> s = queue.front();
		std::cout << s.first <<" " << s.second << "\n";
		queue.pop_front();
		for(int i=0; i < adj.size(); ++i){
			int di = s.first + adj[i].first;
			int dj = s.second + adj[i].second;
			if(valid(di,dj , n, m) && !visited[di][dj]){
				queue.push_back(std::make_pair(di, dj));
				visited[di][dj]= true;
			}
		}
	}
}


int main(int argc, char *argv[]){
	int n, m;
	std::cin >> n >> m;

	std::vector<std::vector<int>> v(n, std::vector<int>(m));

	for(int i=0 ; i < n; ++i){
		for(int j=0; j < m; ++j){
			std::cin >> v[i][j];
		}
	}

	bfs(v, 0, 0);
	return 0;
}
