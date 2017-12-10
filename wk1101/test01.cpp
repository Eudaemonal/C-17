#include <iostream>


template <int i, int j>
struct Multiply{
	static const int value = i * j;
};


template <int i> 
struct Factorial{
	static const int value = i * Factorial<i-1>::value;
};

template <>
struct Factorial<0>{
	static const int value = 1;
};




int main(){
	std::cout << Multiply<3,4>::value << "\n";
	std::cout << Factorial<3>::value << "\n";
}



