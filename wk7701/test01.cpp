#include <iostream>
#include <vector>


int median(std::vector<int> v1, std::vector<int> v2){
	if(v1.size() > v2.size())
		std::swap(v1, v2);

	

	for(auto it: v1)
		std::cout << it << " ";
	std::cout << "\n";
	for(auto it: v2)
		std::cout << it << " ";
	std::cout << "\n";

	return 0;
}

int main(int argc, char *argv[]){
	int n, m;
	std::cin >> n;
	std::vector<int> v1(n);
	for(int i=0; i < n; ++i){
		std::cin >> v1[i];
	}
	std::cin >> m;
	std::vector<int> v2(m);
	for(int i=0; i < m; ++i){
		std::cin >> v2[i];
	}
	std::cout << median(v1, v2) << "\n";
	return 0;
}
