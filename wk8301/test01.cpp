#include <iostream>
#include <thread>

void work(std::atomic<int>& a){
	for(int i=0; i < 10000; ++i)
		a++;
}

int main(int argc, char *argv[]){
	std::atomic<int> a = 0;
	std::atomic<int> b = 0;
	std::atomic<int> c = 0;
	std::atomic<int> d = 0;

	std::thread t1([&]() {work(a); });
	std::thread t2([&]() {work(b); });
	std::thread t3([&]() {work(c); });
	std::thread t4([&]() {work(d); });

	std::cout << a << "\n";
	std::cout << b << "\n";
	std::cout << c << "\n";
	std::cout << d << "\n";

	t1.join();
	t2.join();
	t3.join();
	t4.join();
	
	return 0;
}
