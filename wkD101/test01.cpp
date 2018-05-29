#include <iostream>
#include <vector>
#include <algorithm>

template <typename T>
std::ostream& operator<<(std::ostream& os, std::vector<T> v){
	for(auto it: v)
		os << it << " ";
	os << "\n";
	return os;
}

template <typename T>
std::ostream& operator<<(std::ostream& os, std::vector<std::vector<T>> v){
	for(auto it1: v){
		for(auto it2 : it1)
			os << it2 << " ";
		os << "\n";
	}
	return os;
}



std::vector<std::vector<int>> threesum(std::vector<int> &v){
	int n = v.size();

	std::sort(v.begin(), v.end());

	std::vector<std::vector<int>> res;


	for(int i=0; i < n; ++i){
		int target = v[i];
		int lo = i+1;
		int hi = n-1;
		while(lo < hi){
			if(v[lo] + v[hi] + target > 0){
				hi--;
			}else if(v[lo] + v[hi] + target < 0){
				lo++;
			}else{
				std::vector<int> temp = {target, v[lo], v[hi]};
				res.push_back(temp);

				while(lo < hi && v[lo]==temp[1]) lo++;
				while(lo < hi && v[hi]==temp[2]) hi--;
			}
		}
		while(i+1 < n && v[i+1]==v[i]) i++; //remove duplicates
	}
	
	return res;
}



int main(int argc, char *argv[]){
	int n;
	std::cin >> n;
	std::vector<int> v(n);
	for(int i = 0; i < n; ++i){
		std::cin >> v[i];
	}

	std::cout << threesum(v);
	return 0;
}
