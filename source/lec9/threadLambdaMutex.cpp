#include <exception>
#include <iostream>
#include <mutex>
#include <thread>

int main() {
  int i = 0;
  const long numIterations = 1000000;
  std::mutex iMutex;
  std::thread t1([&] {
    for (int j = 0; j < numIterations; ++j) {
      iMutex.lock();
      i++;
      iMutex.unlock();
    }
  });
  std::thread t2([&] {
    try {
      for (int j = 0; j < numIterations; ++j) {
        iMutex.lock();
        i--;
        // throw std::runtime_error("Hello");
        iMutex.unlock();
      }
    } catch (...) {
      std::cout << "Caught exception";
    }
  });
  t1.join();
  t2.join();
  std::cout << i << std::endl;
}
