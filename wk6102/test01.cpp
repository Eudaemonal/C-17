#include <iostream>

template <class T> 
typename std::remove_reference<T>::type&&
move(T&& a){
	return a;
}


class type{
public:
	type(int n): t(n){}
	void print(){
		std::cout << t << "\n";
	}
private:
	int t;
};



int main(int argc, char *argv[]){
	type a(2);
	type b(3);



	return 0;
}
