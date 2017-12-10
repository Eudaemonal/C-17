#include <iostream>


class Foo{
public:
	static int getValue(){return s_value; }
private:
	static int s_value;


};


int Foo::s_value = 1;

int main(){
	std::cout << Foo::getValue() << "\n";

}
