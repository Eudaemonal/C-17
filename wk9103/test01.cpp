#include <iostream>
#include <string>
#include <set>
#include <queue>


bool isParenthesis(char c){
	return (c=='(' || c==')');
}

bool isValidString(std::string s){
	int cnt = 0;
	for(int i= 0 ; i< s.length(); ++i){
		if(s[i]=='(')
			cnt++;
		else if(s[i]==')')
			cnt--;
		if(cnt < 0)
			return false;
	}
	return (cnt==0);
}

void rip(std::string s){
	if(s.empty())
		return;
	std::set<std::string> visit;

	std::queue<std::string> q;
	std::string temp;
	bool level;

	q.push(s);
	visit.insert(s);
	while(!q.empty()){
		s = q.front();
		q.pop();
		if(isValidString(s)){
			std::cout << s << "\n";
			level = true;
		}
		if(level)
			continue;
		for(int i=0; i < s.length(); ++i){
			if(!isParenthesis(s[i]))
				continue;
			temp = s.substr(0, i) + s.substr(i+1);
			if(visit.find(temp)==visit.end()){
				q.push(temp);
				visit.insert(temp);
			}
		}
	}
}


int main(int argc, char *argv[]){
	std::string s;
	std::cin >> s;

	rip(s);
	
	return 0;
}
