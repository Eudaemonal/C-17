#include <iostream>
#include <vector>

int fib(int n){
	if(n==1||n==2)
		return 1;
	std::vector<int> v;
	v.push_back(1);
	v.push_back(1);
	for(int i =2; i < n;++i){
		v.push_back(v[i-1] + v[i-2]);
	}
	return v[n-1];

}


int main(){
	std::cout << fib(9) << "\n";
}
