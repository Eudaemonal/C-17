#include <iostream>
#include <vector>

template <typename T>
std::ostream& operator<<(std::ostream& os, std::vector<T> v){
	for(auto it: v)
		os << it << " ";
	os << "\n";
	return os;
}


int partition(std::vector<int> &v, int start, int end){
	int p = v[end];
	int j = start;
	for(int i=start; i < end; ++i){
		if(v[i] <= p){
			std::swap(v[i], v[j++]);
		}
	}
	std::swap(v[end], v[j]);
	return j;
}



void quick_sort(std::vector<int> &v, int start, int end){
	if(start > end)
		return;
	int pivot = partition(v, start, end);
	quick_sort(v, start, pivot-1);
	quick_sort(v, pivot+1, end);
}


int main(int argc, char *argv[]){
	int n;
	std::cin >> n;
	std::vector<int> v(n);
	for(int i=0; i < n; ++i){
		std::cin >> v[i];
	}

	quick_sort(v, 0, v.size()-1);

	std::cout << v;

	return 0;
}
