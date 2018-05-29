#include <iostream>

template <typename T>
T max(T a, T b){
	return std::max(a, b);
}

template <typename T, typename... Args>
T max(T a, Args... args){
	return std::max(a, max(args...));
}

int main(int argc, char *argv[]){
	std::cout << max(20,3,4,5) << "\n";

	return 0;
}
