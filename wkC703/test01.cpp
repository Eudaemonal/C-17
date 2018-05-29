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


void merge(std::vector<int> &v, int start, int mid, int end){
	int n1 = mid - start + 1;
	int n2 = end - mid;
	std::vector<int> L(n1);
	std::vector<int> R(n2);

	for(int i=0; i < n1; ++i)
		L[i] = v[i+start];
	for(int i=0; i < n2; ++i)
		R[i] = v[i+mid+1];

	int i=0, j=0, k=start;
	while(i < n1 && j < n2){
		if(L[i] < R[j]){
			v[k++] = L[i++];
		}else{
			v[k++] = R[j++];
		}
	}
	while(i < n1){
		v[k++] = L[i++];
	}
	while(j < n2){
		v[k++] = R[j++];
	}
}


void merge_sort(std::vector<int> &v, int start, int end){
	if(start >= end)
		return;
	int mid = (end + start)/2;
	merge_sort(v, start, mid);
	merge_sort(v, mid+1, end);

	merge(v, start, mid, end);
	
}

int main(int argc, char *argv[]){
	int n;
	std::cin >> n;
	std::vector<int> v(n);
	for(int i = 0; i < n; ++i){
		std::cin >> v[i];
	}
	
	merge_sort(v,0, v.size()-1);
	
	std::cout << v;
	return 0;
}
