#include <iostream>
#include <thread>
#include <mutex>

static const int total = 5000000;
static int counter;
std::mutex mtx;

void count(){
	mtx.lock();
	while(counter < total){
		counter++;
		std::cout << "Thread id:" << std::this_thread::get_id()<< " Counter: " << counter << "\n";

	}
	mtx.unlock();
}

int main(int argc, char *argv[]){

	std::thread t1{count};
	std::thread t2{count};

	t1.join();
	t2.join();

	std::cout << counter << "\n";
	return 0;
}
