#include <iostream>

template <int i>
class loop{
public:
	static inline void exec(){
		std::cout << "A-"<< i << " ";
		loop<i-1>::exec();
		std::cout << "B-" << i << " ";
	}
};


template <>
class loop<0>{
public:
	static inline void exec(){
		std::cout << "A-" << 0 << " ";
		std::cout << "\n";
		std::cout << "B-" << 0 << " ";
	}
};

int main(){
	loop<8>::exec();
}
