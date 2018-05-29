#include <iostream>
#include <cmath>

double colour(int n, int m){
	if(n==1){
		return m;
	}else if(n==2){
		if (m<2)
			return 0.0;
		return (double)m*(m-1);
	}
	
	if(m==2)
		return 2.0;
	return m*pow(double(m-1), double(n-1))-colour(n-1, m);
}


int main(){
	int N, M, ans = 0;
	std::cin >> N >> M;

	ans=(int)colour(N,M);
	std::cout << ans;
	return 0;
}
