#include <iostream>

template <int _case>
class Switch{
public:
	static inline void exec(){
		std::cout << "case - default\n";
	}
};

template <>
class Switch<1>{
public:
	static inline void exec(){
		std::cout << "case - 1\n";
	}
};

template <>
class Switch<2>{
public:
	static inline void exec(){
		std::cout << "case - 2\n"; 
	}
};

int main(){
	Switch<0>::exec();
	Switch<1>::exec();
	Switch<2>::exec();
}
