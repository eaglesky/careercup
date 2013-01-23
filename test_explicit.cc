#include <iostream>
using namespace std;

class Foo
{
  public:
   // single parameter constructor, can be used as an implicit conversion
   /*explicit*/ Foo (int foo,int tm2 = 44) : m_foo (foo), m2(tm2) 
   {
   }
   int GetFoo () { return m_foo; }
   int Getm2() { return m2; }
  
  private:
   int m_foo;
   int m2;
};

void DoBar(Foo foo)
{
    int i = foo.GetFoo ();
    cout << i << " ";
    int j = foo.Getm2();
    cout << j << endl;
}

int main()
{
  DoBar(1);
  return 0;
}
