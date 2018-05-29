#include <iostream>
#include <string>
#include <regex>

template <typename T>
std::ostream& operator<<(std::ostream& os, std::vector<T> v){
	for(auto it: v)
		os << it << " ";
	os << "\n";
	return os;
}


std::vector<std::string> split(std::string re, std::string str){
	std::regex e(re);
	std::vector<std::string> res;
	std::regex_token_iterator<std::string::iterator> it(str.begin(), str.end(), e, -1);
	std::regex_token_iterator<std::string::iterator> end;
	while (it != end){
		res.push_back(*it++);
	}
	return res;
}

int main(int argc, char *argv[]){
	int n;
	std::cin >> n;

	std::string str;


	for(int i=0; i < n; ++i){
		std::cin >> str;
		auto v = split("\\|", str);

		if(v.size()==4)
			std::cout << v;
	}
	return 0;
}
