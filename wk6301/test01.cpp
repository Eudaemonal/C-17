#include <iostream>

class Foo{
public:
	static const int bar = 5;
};



int main(int argc, char *argv[]){

	static_assert(Foo::bar > 4, "Foo::bar too small\n");
	std::cout << Foo::bar<<"\n";
}
