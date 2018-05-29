#include <iostream>
#include <thread>
#include <deque>
#include <mutex>
#include <chrono>
#include <condition_variable>

std::mutex mu, cout_mu;
std::condition_variable cond;

class Buffer{
public:
	Buffer()=default;
	
	void add(int num){
		while(true){
			std::unique_lock<std::mutex> locker(mu);
			cond.wait(locker, [this](){return buffer_.size() < size_;});
			buffer_.push_back(num);
			locker.unlock();
			cond.notify_all();
			return;
		}
	}

	int remove(){
		while(true){
			std::unique_lock<std::mutex> locker(mu);
			cond.wait(locker, [this](){return buffer_.size() > 0; });
			int back = buffer_.back();
			buffer_.pop_back();
			locker.unlock();
			cond.notify_all();
			return back;
		}
	}

private:
	std::deque<int> buffer_;
	const unsigned int size_ = 10;
};

class Producer{
public:
	Producer(Buffer& buffer)
		: buffer_(buffer)
	{}

	void run(){
		while(true){
			int num = std::rand() %100;
			buffer_.add(num);
			cout_mu.lock();
			std::cout << "Produced: " << num <<"\n";
			std::this_thread::sleep_for(std::chrono::milliseconds(50));
			cout_mu.unlock();
		}
	}

private:
	Buffer& buffer_;
};


class Consumer{
public:
	Consumer(Buffer& buffer)
		:buffer_(buffer)
	{}

	void run(){
		while(true){
			int num = buffer_.remove();
			cout_mu.lock();
			std::cout << "Consumed: " << num << "\n";
			std::this_thread::sleep_for(std::chrono::milliseconds(50));
			cout_mu.unlock();

		}
	}

private:
	Buffer& buffer_;
};

int main(int argc, char *argv[]){
	Buffer b;
	Producer p(b);
	Consumer c(b);
	std::thread producer_thread(&Producer::run, &p);
	std::thread consumer_thread(&Consumer::run, &c);

	producer_thread.join();
	consumer_thread.join();

	
	return 0;
}
