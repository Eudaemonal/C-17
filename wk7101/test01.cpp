#include <iostream>
#include <vector>


int max(int a, int b, int c){
	return std::max(a, std::max(b, c));
}

int ms(std::vector<int> v){
	std::vector<int> sum(v.size());

	sum[0] = v[0];
	sum[1] = v[0] + v[1];
	sum[2] = max(sum[1], v[1] + v[2], v[0] + v[2]);

	for(int i=3; i < v.size(); ++i){
		sum[i] = max(sum[i-1], sum[i-2] + v[i], v[i] + v[i-1] + sum[i-3]);
	}
	return sum.back();
}

int main(int argc, char *argv[]){
	int n;
	std::cin >> n;
	std::vector<int> v(n);
	for(int i=0; i < n; ++i){
		std::cin >> v[i];
	}
	std::cout << ms(v) << "\n";
	return 0;
}
