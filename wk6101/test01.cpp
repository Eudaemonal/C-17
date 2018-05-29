#include <iostream>
#include <queue>



int main(int argc, char *argv[]){
	std::priority_queue<int> pq;
	pq.emplace(2);
	pq.emplace(1);
	pq.emplace(3);
	pq.emplace(4);

	while(!pq.empty()){
		std::cout << ' ' << pq.top();
		pq.pop();
	}
	std::cout << "\n";

	return 0;
}
