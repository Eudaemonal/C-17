#include <iostream>
#include <string>
#include <stack>


bool isLeft(char a){
	return (a=='('||a=='['||a=='{');
} 

bool isRight(char a){
	return (a==')'||a==']'||a=='}');
} 


bool isMatch(char a, char b){
	if(a=='(' && b==')')
		return true;
	else if(a=='[' && b==']')
		return true;
	else if(a=='{' && b=='}')
		return true;
	else
		return false;
} 


bool balance_brucket(std::string str){
	
	char c;
	int i = 0;
	std::stack<char> s;
	while(i < str.length()){
		c = str.at(i);
		if(isLeft(c)){
			s.push(c);
		}else if(isRight(c)){
			if(s.empty()){
				return false;
			}else{
				if(isMatch(s.top(), c)){
					s.pop();
				}else{
					return false;
				}	
			}
		}
		i++;
	}
	if(!s.empty())
		return false;
	return true;

}


int main(int argc, char *argv[]){
	std::string s;
	std::cin >> s;
	
	if(balance_brucket(s)){
		std::cout << "balanced\n";
	}else{
		std::cout << "unbalanced\n";
	}

	return 0;
}
