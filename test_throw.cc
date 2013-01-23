#include <iostream>
#include <string>
using namespace std;

class test {
 public:
  bool test_throw();

};

bool test::test_throw()
{
  int a = 4;
  int b = 3;
  if (a == b) {
    return false;
  } else {
    for (int i = 0; i < 10; i++)
    {
      if (a == i)
        throw("Error!");
    }
    return true;
  }
}

int main()
{
  try {
    test mytest;
    if(mytest.test_throw()){
      cout << "In if!" << endl;
    } else {
      cout << "In else!" << endl;
    }
  } catch (char const *err) {
    cout << err << endl;
  }
  
  return 0;
} 
