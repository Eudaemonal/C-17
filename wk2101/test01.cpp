#include <iostream>
#include "list.h"


int main(){
	List l;
	l.add_node(1);
	l.add_node(2);
	l.add_node(3);
	l.add_node(4);
	l.add_node(5);
	l.add_node(6);

	int loop = 4;
	if(l.isNode(loop)){
		l.link(l.findNode(loop));
	}

	std::cout << l;
}
