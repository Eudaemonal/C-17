#include <iostream>
#include <cstdint>
#include <string>
#include <limits>
#include <algorithm>

/*
g++ -std=c++14 test02.cpp -o test02

/usr/bin/time valgrind --tool=callgrind ./test02
 * */
struct C{
	static const std::string &magic_static(){
		static const std::string s = "bob";
		return s;
	}

	const std::string &s = magic_static();

	const std::string &magic_static_ref(){
		return s;
	}
};


auto main()->int{
	C::magic_static().size();
	C::magic_static().size();
	C::magic_static().size();
	return C::magic_static().size();
}
