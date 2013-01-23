#include "MyQueues.h"
using namespace std;

int main()
{
  cout << "Test q1: " << endl;
  ArrayQueue<int> q1(5);
  for (int i = 0; i < 10; i++)
  {
    q1.EnQueue(i);
  }
  q1.Show();  // queue: 0 1 2 3

  int cur_pop = 0;
  for (int i = 0; i < 10; i++)
  {
    if (q1.DeQueue(&cur_pop))
      cout << cur_pop << " ";
  }
  cout << endl;    //0 1 2 3
  q1.Show(); // queue:   
  if(q1.IsEmpty())
    cout << "Empty!" << endl;

  for (int i = 0; i < 10; i++)
  {
    q1.EnQueue(i);
  }

  q1.Show();  // queue: 1 2 3  0
  cout << "front: " << q1.get_front() << endl; // front: 0
  cout << "rear: " << q1.get_rear() << endl;  // rear: 3
  if (q1.IsFull())
    cout << "Full" << endl;

  for (int i = 0; i < 3; i++)
  {
    if (q1.DeQueue(&cur_pop))
      cout << cur_pop << " ";

  }                                  // 0 1 2
  cout << endl;
  cout << "Last: ";
  q1.Show();  //queue: 3


}
