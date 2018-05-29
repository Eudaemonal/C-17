#include <iostream>


int main(){
	int i = 11;
	int const *p = &i;
	p++;
	std::cout << *p << "\n";
	return 0;
}
