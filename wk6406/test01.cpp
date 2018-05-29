#include <iostream>
#include <vector>


bool subset(int sum, int start, std::vector<int> svec){
	bool ret = false;
	for(int i = start; i<svec.size(); ++i){
		if(svec[i] < sum){
			ret |= subset(sum-svec[i], i+1, svec);
		}else if(svec[i] == sum){
			return true;
		}
	}
	return ret;
}

int main(int argc, char *argv[]){
	int sum, n;
	std::cin >> sum >> n;
	std::vector<int> set(n);
	for(int i=0; i <n; ++i){
		std::cin >> set[i];
	}
	std::cout << subset(sum,0, set) << "\n";
	

	return 0;
}
