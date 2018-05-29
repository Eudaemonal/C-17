#include <iostream>
#include <string>
#include <map>

int main(){
    std::string s;
    char c;
    int counter = 0;
    std::map<char, int> m;
    std::cin >> s;
    for(int i=0; i < s.length(); ++i){
        c = s.at(i);
        auto got = m.find(c);
        if( got == m.end())// not found
            m.emplace(c, 1);
        else{
            got->second++;
	    if(got->second > counter)
		    counter = got->second;
	}
    }
    while (counter){
	for(auto it = m.begin();it!=m.end(); ++it){
	    if(it->second>0){
            	std::cout << it->first;
		it->second--;
	    }
	}
	 counter--;

    }
}
