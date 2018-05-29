#include <iostream>
#include <thread>
#include <atomic>
#include <mutex>


class Semaphore{
public:
	Semaphore(int n)
		:size(n){
		count.store(0);	
	}

	void sem_post(){
		mtx.lock();
		if(!wait_queue.empty()){
			p = wait_queue.dequeue();
			mtx.unlock();
			wake_thread(p);
		}
		else{
			counter++;
			mtx.unlock();
		}
	}

	void sem_wait(){
		mtx.lock();
		if(counter > 0 && counter < size){
			counter--;
			mtx.unlock();
		}else{
			wait_queue.enqueue(current_thread);
			mtx.unlock();
			block_thread();
		}
	}


private:
	int size;
	std::atomic<int> counter;
	std::mutex mtx;
	thread_queue wait_queue;

};

int main(int argc, char *argv[]){

	return 0;
}
