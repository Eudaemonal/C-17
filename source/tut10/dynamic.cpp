#include <iostream>

class B {
public:
  virtual void f() { 
    std::cout << "B "; 
  }
};

class D : public B {
public:
  virtual void f() { 
    std::cout << "D "; 
  }
};

int main() {
  B b;
  D d;
  b = d;
  B &pb = b;
  b.f();
  pb.f();
}
