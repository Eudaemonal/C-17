#include <iostream>
#include <random>

int main(int argc, char *argv[]){
	std::random_device rd;
	std::mt19937 gen(rd());

	float lambda = 3.5;
 
	std::exponential_distribution<float> d(lambda);

	float num = d(gen);

	std::cout << num << "\n";
	
	return 0;
}
