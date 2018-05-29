#include <iostream>
#include <vector>

int rod(std::vector<int> v, int n){
	std::cout << "call rod\n";
	int max_val = 0;
	for(int i = 0; i < n; ++i){
		max_val = std::max(max_val, v[i] + rod(v,n - i - 1));
	}
	return max_val;
}

int main(int argc, char *argv[]){
	int n;
	std::cin >> n;
	std::vector<int> v(n);
	for(int i = 0; i < n; ++i){
		std::cin >> v[i];
	}
	std::cout << rod(v, n) << "\n";
	return 0;
}
