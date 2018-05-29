#include <iostream>
#include <string>
#include <vector>

int lsubstr(std::string s){
	std::vector<bool> visited(256);
	int n = s.length();
	std::vector<int> len(n);

	visited[s.at(0)] = true;
	len[0] = 1;
	for(int i= 1; i < n; ++i){
		if(!visited[s.at(i)]){
			visited[s.at(i)] = true;
			len[i] = len[i-1] + 1;
		}
		else{
			for(int j=0; j<i; ++j)
				visited[s.at(j)] = false;
			visited[s.at(i)] = true;
			len[i] = 1;
		}
	}

	for(int i=0; i < n; ++i){
		std::cout << len[i] << ", ";
	}
	std::cout << "\n";

	return *std::max_element(len.begin(), len.end());
}

int main(int argc, char *argv[]){
	std::string s;
	std::cin >> s;
	std::cout << lsubstr(s) << "\n";

	return 0;
}
