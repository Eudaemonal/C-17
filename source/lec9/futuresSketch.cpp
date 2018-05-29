#include <iostream>
#include <future>
#include <thread>
#include <chrono>

int calculate() {
	return 123;
}

int main() {
	std::future<int> fut = std::async(calculate);
	// note can force to launch a new thread using:
	// std::future<int> fut = std::async(std::launch::async,calculate);
	
	bool doOtherWork = true;
	while (doOtherWork) {
		// check if the result is available. 
		if (fut.wait_for(std::chrono::seconds(0)) == std::future_status::timeout) {
			// do other work.. e.g. go to a different factory.
		} else {
			// either the result is available or the launch has been deferred
			doOtherWork = false;
		}
	}
	
	int res = fut.get(); // get the result from the future
	std::cout << res << std::endl;
}
