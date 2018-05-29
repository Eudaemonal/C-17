#include <iostream>


long factorial(int x){
	long fac = 1;
	for(int i = 1; i <=x; ++i){
        	fac *= i;
	}
	return fac;
}

int f(int x){
	int count = 0;
	std::string s;
	s = std::to_string(factorial(x));
	for (char & c : s){
		if(c=='0')
			count++;
	}
	return count;
}


int g(int x){
	for(int i=0; i< INT_MAX; ++i){
		if(f(i)==x)
			return i;
	}
	return -1;
}

int main(int argc, char *argv[]){
	int n;
	std::cin >> n;
	std::cout << g(n);
	
	return 0;
}
