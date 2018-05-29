#include <iostream>
#include <thread>
#include <mutex>


std::mutex mtx;

void counter(int numIterations) {
  for (int i = 0; i < numIterations; ++i) {
    mtx.lock();
    std::cout << "Thread id: " << std::this_thread::get_id();
    std::cout << " value = " << i << std::endl;
    mtx.unlock();

  }
}


int main(int argc, char *argv[]){
	std::thread t1{counter, 10};
	std::thread t2{counter, 5};
	t1.join();
	t2.join();

	return 0;
}
