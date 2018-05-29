#include <iostream>
#include <cmath>

class Random{
public:
	// random number with LGM method, with period 2^31
	Random(unsigned int seed)
		:__x(seed)
	{
		__m = 0x7fffffff;
		__a = 0x41a7;
		__b = 0;
	}

	// generate persudo random int sequence
	unsigned int random(){
		__x = (__a * __x + __b) % __m;
		return __x;
	}
	
	// generate random float within [0, 1]
	float randomfloat(){
		__x = (__a * __x + __b) % __m;
		return (float)__x/__m;
	}
	
	// generate exponential distribution
	float exponential(float lambda){
		return -lambda * log(1 - randomfloat());
	}
private:
	unsigned int __m;
	unsigned int __a;
	unsigned int __b;
	unsigned int __x;
	
};



int main(int argc, char *argv[]){
	Random rd(1);
	std::cout << rd.exponential(1) << "\n";
	std::cout << rd.exponential(1)<< "\n";
	std::cout << rd.exponential(1)<< "\n";
	std::cout << rd.exponential(1)<< "\n";
	
	return 0;
}
