#include <iostream>
#include <string>
#include <vector>

std::vector<int> get_lps(std::string pat){
	int len = 0;
	std::vector<int> lps(pat.length());
	lps[0] = 0;
	int i=1;
	while(i < pat.length()){
		if(pat.at(i)==pat.at(len)){
			len++;
			lps[i] = len;
			i++;
		}else{
			if(len!=0){
				len = lps[len-1];
			}else{
				lps[i] = 0;
				i++;
			}
		}
	}
	return lps;
}

std::vector<int> kmp(std::string pat, std::string txt){
	std::vector<int> lps = get_lps(pat);
	std::vector<int> result;
	int i=0, j=0;
	while(i < txt.length()){
		if(txt[i]==pat[j]){
			i++;
			j++;
		}
		if(j==pat.length()){
			result.push_back(i-j);
			j = lps[j-1];
		}else if(i < txt.length() && pat[j]!=txt[i]){
			if(j!=0)
				j = lps[j-1];
			else
				i = i + 1;
		}
	}
	return result;
}

int main(int argc, char *argv[]){
	std::string txt, pat;
	
	std::cin >> pat;
	std::cin >> txt;

	std::vector<int> idxs;
	idxs = kmp(pat, txt);
	for(auto it: idxs){
		std::cout << it << " ";
	}
	std::cout << "\n";

	return 0;
}
