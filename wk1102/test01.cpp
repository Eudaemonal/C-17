#include <iostream>

#include "list.h"

int main(){
	List l;
	l.add_node(1);
	l.add_node(2);
	l.add_node(3);

	std::cout << l;
	
}
