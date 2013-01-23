#include <iostream>
using namespace std;

class test
{
 public:
  test(int i=0):data(i){}
 // ~test();
 
  int data;
 // test *next;
};

int main()
{
  test *ptest = new test(1);
 // test *ptestn = new test(2);
 // ptest->next = ptestn;

  cout << ptest->data << endl;
 // cout << ptest->next->data << endl;

  test *ptest2 = ptest;
  delete ptest;
  delete ptest2; 

}
