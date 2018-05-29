#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
#include <numeric>

int main(int argc, char *argv[]){
	std::vector<int> from_vector(10);
	std::iota(from_vector.begin(), from_vector.end(), 0);

	std::vector<int> to_vector;
	std::copy(from_vector.begin(), from_vector.end(), std::back_inserter(to_vector));

	std::cout << "to_vector contains: ";
	std::copy(to_vector.begin(), to_vector.end(), std::ostream_iterator<int>(std::cout , " "));
	std::cout << "\n";

	
	return 0;
}
