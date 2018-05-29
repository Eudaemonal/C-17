#include <iostream>
#include <csignal>
#include <chrono>
#include <thread>

void signal_handler(int signum){
	std::cout << "Interrupt signal ("<< signum << ") received\n";
	exit(signum);
}

int main(int argc, char *argv[]){
	signal(SIGINT, signal_handler);

	while(1){
		std::cout << "go to sleep...\n";
		std::this_thread::sleep_for(std::chrono::milliseconds(1));
	}
	return 0;
}
