#include <iostream>

int count_path(int n, int m){
	if(n==1 || m==1)
	       return 1;
	return count_path(n-1, m) + count_path(n, m-1);	
}

int main(int argc, char *argv[]){
	int n, m;
	std::cin >> n >> m;
	std::cout << count_path(n,m) << "\n";

	return 0;
}
