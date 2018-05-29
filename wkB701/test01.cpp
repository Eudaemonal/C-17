#include <iostream>


class overload{
private:
	int a, b;
public:
	int load(int x){
		a = x;
		return a;
	}
	int load(int x, int y){
		a = x;
		b = y;
		return a*b;
	}
};

int main(int argc, char *argv[]){
	overload O1;
	std::cout << O1.load(20) << "\n";
	std::cout << O1.load(20, 40) << "\n";
	
	return 0;
}
