// possible questions
// 1) Write move and copy constructors / assignment implementing value semantics, where a moved from vector contains no elements
// alternative) Write move and copy constructors / assignment implementing reference semantics using reference counting
//  Remember: STL is not cheating --> use shared pointers
// 2) Fix this code so that it executes moves, not copies when reallocating
// 3) This code is not exception-safe
//     Remember: STL is not cheating --> Replace data with unique pointer to array
//  a) Write a test case where what it should output differs from what it does output
//  b) Fix the bug
// 4) Ensure that a vector<T> can only be instantiated if the T is copy-assignable and default-constructible. Hint: static_assert + type traits

#include <algorithm>
#include <iostream>
#include <memory>

template <typename T>
class Vector {
public:
  Vector(): data{} {}

  ~Vector () {
    delete[] data;
  }

  void push_back(const T& item) {
    if (sz == capacity) {
      auto new_capacity = (capacity == 0) ? 1 : (capacity * 2);

      auto next = new T[new_capacity];
      std::copy(data, data + capacity, next);

      delete[] data;
      data = next;
      capacity = new_capacity;
    }
    data[sz++] = item;
  }

  unsigned size() const {
    return sz;
  }

  T& operator[](unsigned n) {
    return data[n];
  }

  const T& operator[](unsigned n) const {
    return data[n];
  }

private:
  T* data = nullptr;
  unsigned sz = 0;
  unsigned capacity = 0;
};


int main() {
  Vector<int> vec;
  for (auto i = 0; i < 20; ++i) {
    vec.push_back(i);
  }
  for (auto i = 0; i < 20; ++i) {
    std::cout << vec[i] << '\n';
  }

  // this compiles, but when I call push_back it fails
  Vector<std::unique_ptr<int>> upvec;
  // upvec.push_back(std::unique_ptr<int>{});

  // this fails at runtime. Why?
  // auto v2 = vec;
}
