#include <random>
#include <set>
#include <iostream>
#include <algorithm>
#include <thread>
#include <future>

/*
Basic Compile: 
g++ -std=c++14 test01.cpp -o test01

Optimized Compile: 
g++ -std=c++14 -O3 test01.cpp -o test01

Run time: 
/usr/bin/time ./test01

A difference of running time between basic and optimized 


 * */

std::set<int> make_sorted_random(const size_t num_elems){
	std::set<int> retval;
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(0, num_elems -1);

	std::generate_n(std::inserter(retval, retval.end()), num_elems, [&](){return dis(gen); });

	return retval;
}

int main(){
	auto f1 = std::async(std::launch::async, make_sorted_random, 1000000);
	auto f2 = std::async(std::launch::async, make_sorted_random, 1000000);
	
	std::cout << f1.get().size() << ' ' << f2.get().size() << '\n';
	
}

