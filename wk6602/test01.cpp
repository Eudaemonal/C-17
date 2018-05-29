#include <iostream>

int count(int n){
	if(n==1 || n==2 || n==3)
		return 1;
	else if(n==4)
		return 2;
	else
		return count(n-1) + count(n-4);

}

int main(int argc, char *argv[]){

	std::cout << count(5) << "\n";
	return 0;
}
