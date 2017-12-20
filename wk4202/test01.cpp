#include <iostream>

template <typename T>
void print_impl(const T &t){
	std::cout << t << "\n";
}

template <typename ... T>
void print(const T& ... t){
	(void)std::initializer_list<int>{ (print_impl(t), 0)... };
}


int f1(){
	std::cout << "f1\n";
	return 1;
}

int f2(){
	std::cout << "f2\n";
	return 2;
}

int main(){
	int i = (f1(), f2());
	(void)std::initializer_list<int>{f1(), f2()};
}
