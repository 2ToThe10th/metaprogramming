#include <iostream>
#include "SingletonHandler.hpp"

class A{
 public:
  ~A() {
    std::cout << "A destroyed[2]" << std::endl;
  }
};

class B{
 public:
  ~B() {
    std::cout << "B destroyed[5]" << std::endl;
  }
};

class C{
 public:
  ~C() {
    std::cout << "C destroyed[1]" << std::endl;
  }
};

class D{
 public:
  ~D() {
    std::cout << "D destroyed[4]" << std::endl;
  }
};

class E{
 public:
  ~E() {
    std::cout << "E destroyed[7]" << std::endl;
  }
};

class F{
 public:
  ~F() {
    std::cout << "F destroyed[6]" << std::endl;
  }
};

class G{
 public:
  ~G() {
    std::cout << "G destroyed[3]" << std::endl;
  }
};

class H{
 public:
  ~H() {
    std::cout << "H destroyed[never]" << std::endl;
  }
};

class I{
 public:
  ~I() {
    std::cout << "I destroyed[never]" << std::endl;
  }
};

int main() {
  SingletonHandler<G>::Instance();
  SingletonHandler<A>::Instance();
  SingletonHandler<D>::SetLongevity(1);
  SingletonHandler<B>::Instance();
  SingletonHandler<B>::SetLongevity(1);
  SingletonHandler<H>::SetLongevity(5);
  SingletonHandler<D>::Instance();
  SingletonHandler<E>::Instance();
  SingletonHandler<E>::SetLongevity(10);
  SingletonHandler<F>::Instance();
  SingletonHandler<F>::SetLongevity(5);
  SingletonHandler<C>::Instance();
  return 0;
}
