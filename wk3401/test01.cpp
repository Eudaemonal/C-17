#include <iostream>

class semaphore{
public:
	semaphore(int n): n_(n)
	{}

	void wait(){
		--n_;
	}

	void signal(){
		++n_;
	}
private:
	std::atomic<int> n_;
	
};
