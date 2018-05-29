#include <iostream>
#include <vector>
#include <stack>

void reverse(std::vector<int> &v){
	std::stack<int> s;
	for(int i=0; i < v.size(); ++i){
		s.push(v[i]);
	}
	for(int i=0; i < v.size(); ++i){
		v[i] = s.top();
		s.pop();
	}
}


int main(int argc, char *argv[]){
	int n;
	std::cin >> n;
	std::vector<int> v(n);
	for(int i=0; i < n; ++i){
		std::cin >> v[i];
	}
	reverse(v);
	for(auto it: v)
		std::cout << it << " ";
	std::cout << "\n";

	return 0;
}
