#include <iostream>


struct Foo{
	char c;
	short s;
	int i;
	double d;
}__attribute__((packed));


// unaligned memory, may spend more time to access

int main(int argc, char *argv[]){
	Foo f;
	
	return 0;
}
