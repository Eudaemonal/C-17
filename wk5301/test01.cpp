#include <iostream>

class Base{
public:
	virtual void show() {
		std::cout << "In Base\n";
	}
};


class Derived: public Base{
public:
	void show(){
		std::cout << "In Derived\n";
	}
};

int main(int argc, char *argv[]){
	Base *bp = new Derived;
	bp->show();
	return 0;
}
