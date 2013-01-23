#include <iostream>
using namespace std;

class ptr {
 public:
  ptr(int num):data(num){}
  int *prev;
  int *next;

  int data;

};

int main()
{
  ptr *pptr = new ptr(3);
  int *a = new int [10];
  int *b = new int [10];
  for (int i = 0; i < 10; i++)
  {
    a[i] = i;
    b[i] = i*5;
  }
  pptr->prev = a;
  pptr->next = b;

  cout << "Data = " << pptr->data << endl;
  for (int i = 0; i < 10; i++)
  {
    cout << *(pptr->prev+i) << ' '<< *(pptr->next+i) << endl;
  }
  delete pptr; 
  pptr->next = a;   
  
  return 0;
}
