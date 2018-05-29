#include <iostream>

template <typename T>
T adder(T v){
	return v;
}

template <typename T, typename... Args>
T adder(T first, Args... args){
	return first + adder(args...);
}

int main(int argc, char *argv[]){
	int sum = adder(1,2,3,4,5,6,7,8);

	std::cout << sum << "\n";
	return 0;
}
