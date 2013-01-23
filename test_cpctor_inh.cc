#include <iostream>

class B {
 public:
  B() { std::cout << "B default ctor called" << std::endl; }
  B( const B& ) {
              std::cout << "B copy ctor called" << std::endl;
  }
};

class A : public B {
  public:
    A() { std::cout << "A default ctor called" << std::endl; }
    A( const A& ) {
              std::cout << "A copy ctor called" << std::endl;
                }
};

void Foo( A ) {
      std::cout << "Hello world" << std::endl;
}

int main() {
   A a1;
   Foo( a1 );
}
