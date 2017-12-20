#include <iostream>

template <int i>
class factor{
public:
	enum {result = i*factor<i-1>::result};
};


template <>
class factor<1>{
public:
	enum {result = 1};
};

int main(){
	std::cout << factor<4>::result << "\n"; 
}
