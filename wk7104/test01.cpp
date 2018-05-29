#include <iostream>
#include <experimental/any>
#include <vector>


int main(int argc, char *argv[]){
	std::vector<std::experimental::fundamentals_v1::any> v{5, 6, 'a', std::string("test")};
	std::cout << v.size() << '\n';
	for(int i=0; i < v.size(); ++i)
		std::cout << v[i].type().name() << '\n';
	

	return 0;
}
