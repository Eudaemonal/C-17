#include <iostream>
#include <functional>
#include <string>

void print(const int &i, const std::string &s){
	std::cout << i << ' '<< s << '\n';
}

int main(){
	int i = 5;
	const auto f = std::bind(&print, std::ref(i), std::placeholders::_1);

	f("aaa");
	i = 6;
	f("bbb");

}

