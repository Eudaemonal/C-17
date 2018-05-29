#include <iostream>
#include <optional>

std::optional<std::string> create(bool b){
	if(b)
		return "test";
	return {};
}


int main(int argc, char *argv[]){
	auto str1  = create(true);
	std::cout << *str1 << "\n";
	
	auto str2  = create(false);
	std::cout << *str2 << "\n";

	return 0;
}
