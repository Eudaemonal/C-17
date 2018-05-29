#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

template <typename T>
std::ostream& operator<<(std::ostream& os, std::vector<T> v){
	for(auto it: v)
		os << it << " ";
	os << "\n";
	return os;
}

bool isNotVisited(int x, std::vector<int>& path){
	for(int i = 0; i < path.size(); ++i){
		if(path[i]==x)
			return false;
	}
	return true;
}

void findpaths(std::vector<std::vector<int>> &g, int src, int dst, int v){
	std::queue<std::vector<int>> q;

	std::vector<int> path;
	path.push_back(src);
	q.push(path);
	while(!q.empty()){
		path = q.front();
		q.pop();
		int last = path[path.size() -1];
		if(last==dst)
			std::cout << path;
		for(int i = 0; i < g[last].size(); ++i){
			if(isNotVisited(g[last][i], path)){
				std::vector<int> newpath(path);
				newpath.push_back(g[last][i]);
				q.push(newpath);
			}
		}
	}
}

int main(int argc, char *argv[]){
	int v = 4;
	std::vector<std::vector<int>> g(v);

	g[0].push_back(3);
	g[0].push_back(1);
	g[0].push_back(2);
	g[1].push_back(3);
	g[2].push_back(0);
	g[2].push_back(1);
 
	int src = 2, dst = 3;
	std::cout << "path from src " << src
         << " to dst " << dst << " are \n";

	
	// function for finding the paths
	findpaths(g, src, dst, v);
    
	return 0;
}
