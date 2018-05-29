#include <iostream>

class Base{
public:
	virtual void f(){
		std::cout << "Base::f()\n";
	}
};

class Derived: public Base{
public:
	void f() final{
		std::cout << "Derived::f()\n";
	}
};



int main(){
	Base *b = new Derived;
	b->f();
	return 0;
}

