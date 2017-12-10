#include <iostream>

template <bool Condition>
class If{
public:
	static inline void exec(){
		std::cout << "statement is true\n";
	}
};


template <>
class If<false>{
public:
	static inline void exec(){
		std::cout << "statement is false\n";
	}
};

int main(){
	If<true>::exec();
	If<false>::exec();

}
