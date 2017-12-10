#include <iostream>


int get(){
	static int val = 0;
	val+=1;
	return val;
}


int main(){
	std::cout << get() <<"\n";
	std::cout << get() <<"\n";
	std::cout << get() <<"\n";
}


