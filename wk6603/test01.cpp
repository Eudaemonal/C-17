#include <iostream>
#include <string>

int lcstr(std::string x, std::string y){
	int lcs[x.length()+1][y.length()+1];
	int result = 0;
	for(int i=0; i <= x.length(); ++i){
		for(int j = 0; j <= y.length();++j){
			if(i==0 || j==0)
				lcs[i][j] = 0;
			else if(x.at(i-1)==y.at(j-1)){
				lcs[i][j] = lcs[i-1][j-1] + 1;
				result = std::max(result, lcs[i][j]);
			}
			else 
				lcs[i][j] = 0;
		}
	}
	return result;
}

int main(int argc, char *argv[]){
	std::string a, b;
	std::cin >> a;
	std::cin >> b;
	std::cout << lcstr(a, b) << "\n";
	return 0;
}
