#include <iostream>
#include <functional>

void f(int a, int b, int c){
	std::cout << a <<" " << b << " " << c << "\n";
}

int main(){
	auto g1 = std::bind(f, std::placeholders::_1, std::placeholders::_2, 100);
	g1(1,2);
	
}
