#include <iostream>
#include <vector>

template <typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T> &v){
	for(size_t i=0; i < v.size(); ++i){
			os << v[i] << " ";
	}
	os << "\n";
	return os;
}

void heapify(std::vector<int> &v,int n, int i){
	int largest = i;
	int l = 2*i + 1;
	int r = 2*i + 2;
	if(l < n && v[l] > v[largest])
		largest = l;
	if(r < n && v[r] > v[largest])
		largest = r;
	if(largest!=i){
		std::swap(v[i], v[largest]);
		heapify(v, n, largest);
	}
}

void heap_sort(std::vector<int> &v){
	int n = v.size();
	for(int i= n/2-1; i>=0; --i)
		heapify(v, n, i);
	for(int i=n-1; i >=0; --i){
		std::swap(v[0], v[i]);
		heapify(v, i, 0);
	}
}


int main(int argc, char *argv[]){
	int n;
	std::cin >> n;
	std::vector<int> v(n);
	for(int i = 0; i < n; ++i){
		std::cin >> v[i];
	}
	heap_sort(v);
	
	std::cout << v;
	return 0;
}
