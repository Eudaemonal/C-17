#include <iostream>
#include <string>

int divide(int x, int y){
	if(y==0){
		throw std::string("Divide by zero");
	}
	return x/y;
}

int main(int argc, char *argv[]){
	try{
		std::cout << "4/2 " << divide(4,2) << "\n";
		std::cout << "3/0 " << divide(3,0) << "\n";
	}catch(std::string e){
		std::cout << e << "\n";
	}

	return 0;
}
