#include <iostream>
#include <boost/array.hpp>


int main(int argc, char *argv[]){
	boost::array<int, 4> arr = {{1,2,3,4}};
	std::cout << arr[0]<< "\n";
	return 0;
}
