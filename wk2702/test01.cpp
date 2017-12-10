#include <iostream>
#include <sstream>
#include <vector>


template <typename ... Param>
std::vector<std::string> to_string(const Param ... param){
	const auto to_string_imp1 = [](const auto &t){
		std::stringstream ss;
		ss << t;
		return ss.str();
	};
	return {to_string_imp1(param)...};
}

int main(){
	const auto vec = to_string("hello", 1, 5.3, 1.3f, "bob", 10);
	for(const auto &o : vec){
		std::cout << o << " ";
	}
}

