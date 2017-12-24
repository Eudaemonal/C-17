#include <iostream>
#include <string>
#include <unordered_map>

int main(){
	std::unordered_map<std::string, double> m = {
		{"mon", 5.4}, 
		{"dad", 6.1}, 
		{"bro", 5.9}
	};

	std::string input;
	std::cout << "who? ";
	getline(std::cin, input);

	std::unordered_map<std::string, double>::const_iterator got = m.find(input);

	if(got == m.end())
		std::cout << "not found";
	else
		std::cout << got->first << " is " << got->second;
	std::cout << "\n";
	
}
