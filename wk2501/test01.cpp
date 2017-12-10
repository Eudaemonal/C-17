#include <iostream>
#include <map>


bool fncomp(char lhs, char rhs) {return lhs < rhs;}

struct classcomp{
	bool operator() (const char& lhs, const char& rhs) const{
		return lhs < rhs;
	}
};


std::ostream& operator<<(std::ostream& os, std::map<char, int> m){
	for(auto it = m.begin(); it!= m.end(); ++it){
		os << it->first << ' '<< it->second << ", ";
	}
	std::cout << "\n";
	return os;
}



int main(){
	std::map<char, int> first;

	first['a']=10;
	first['b']=30;
	first['c']=50;
	first['d']=70;

	std::cout << first;



	std::map<char, int> second(first.begin(), first.end());

	std::map<char, int> third(second);

	std::map<char, int, classcomp> fourth;

	bool(*fn_pt)(char, char) = fncomp;
	
	std::map<char, int, bool(*)(char, char)> fifth(fn_pt);


	return 0;
	
}
