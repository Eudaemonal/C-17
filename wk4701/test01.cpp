#include <iostream>
#include <algorithm>
#include <vector>
#include <list>


int main(){
	std::vector<int> v1 {1,2,3,4,5,6,7};
	std::cout << std::is_sorted(std::begin(v1), std::end(v1)) << "\n";

	std::list<int> v2{1,2,3,4,5,6,7};
	std::cout << std::is_sorted(std::next(std::begin(v2)), std::end(v2)) << "\n";

	

}
