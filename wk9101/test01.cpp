#include <iostream>

int partition(int n, int k){
	if(n==0 || k==0 || k>n)
		return 0;
	if(k==1 || k==n)
		return 1;
	return k*partition(n-1, k) + partition(n-1, k-1);
}

int main(int argc, char *argv[]){
	int n, k;
	std::cin >> n >> k;

	std::cout << partition(n, k) << "\n";
	return 0;
}
