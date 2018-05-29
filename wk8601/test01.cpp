#include <iostream>
#include <cmath>
#include <string>

long power(int x){
	return pow(2, x);
}

int f(char a, char b){
	char first, last;
	std::string s;
	if(b==1||b==3||b==5||b==7||b==9)
		return -1;

	for(int i= 0; i < 5000; ++i){
		s = std::to_string(power(i));
		first = s.at(0);
		last = s.at(s.length()-1);
		if(a==first && b==last){
			return i;
		}
	}
	return -1;
}


int main(int argc, char *argv[]){
	char a, b;
	std::cin >> a;
	std::cin >> b;
	
	std::cout << f(a, b);
	
	return 0;
}
