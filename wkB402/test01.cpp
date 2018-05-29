#include <iostream>
#include <vector>

template <typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T> &v){
	for(int i=0; i < v.size(); ++i){
		os << v[i] << " ";
	}
	os << "\n";
	return os;
}

int partition(std::vector<int> &v, int m, int n){
	int i, j, pindex, pivot;
	pindex = m;
	pivot = v[n];
	for(i = m; i < n; ++i){
		if(v[i] <= pivot){
			std::swap(v[pindex], v[i]);
			pindex++;
		}
	}
	std::swap(v[pindex], v[n]);
	return pindex;
}

void quicksort(std::vector<int> &v, int m, int n){
	int index;
	if(m>=n)
		return;
	index = partition(v, m, n);
	quicksort(v, m, index-1);
	quicksort(v, index+1, n);
}

int main(int argc, char *argv[]){
	int n;
	std::cin >> n;
	std::vector<int> v(n);

	for(int i=0;i < n; ++i){
		std::cin >> v[i];
	}
	quicksort(v, 0, v.size()-1);
	std::cout << v;
	
	return 0;
}
