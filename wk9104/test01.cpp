#include <iostream>
#include <string>
#include <cmath>


int decimals_float(float n){
	std::string s = std::to_string(n);
	s.erase(s.find_last_not_of('0') + 1, std::string::npos);
	std::string t = s.substr(s.find(".")+1);
	return t.length();
}



int main(int argc, char *argv[]){
	std::cout << decimals_float(9) << "\n";
	std::cout << decimals_float(1.2) << "\n";

	std::cout << std::pow(0.1, 0) << "\n";
	std::cout << std::pow(0.1, 1) << "\n";
	std::cout << std::pow(0.1, 2) << "\n";

	return 0;
}
