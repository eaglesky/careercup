#include "MyStacks.h"
#include <cstdlib>
using namespace std;

template <class T>
class MyQueue {
 public:
   explicit MyQueue(int size = 10):OutStack(size - size / 2), InStack(size / 2)
                ,front(-1),rear(-1){}
   bool EnQueue(const T &data);
   bool DeQueue(T *data);
   bool IsEmpty();
   bool IsFull();
   void Show();
 private:
  void transfer();
  ArrayStack<T> InStack, OutStack;
  int front;
  int rear;
};

template <class T>
bool MyQueue<T>::EnQueue(const T &data)
{
  if (IsFull())
    return false;

  if (InStack.IsFull() && OutStack.IsEmpty())
    transfer();
  
  return InStack.Push(data);
  rear++;
  
}

template <class T>
bool MyQueue<T>::DeQueue(T *data)
{
  if (IsEmpty())
    return false;

  if (OutStack.IsEmpty())
    transfer();
  front--;
  return OutStack.Pop(data);
}

template <class T>
bool MyQueue<T>::IsEmpty()
{
  return (InStack.IsEmpty() && OutStack.IsEmpty());
}

template <class T>
bool MyQueue<T>::IsFull()
{
  return (InStack.IsFull() && !OutStack.IsEmpty()); 
}

template <class T>
void MyQueue<T>::Show()
{
  cout << "OutStack:" << endl;
  OutStack.Show();
  cout << endl;
  cout << "InStack: " << endl;
  InStack.Show();
}

template <class T>
void MyQueue<T>::transfer()
{
  int data;
  while (!InStack.IsEmpty())
  {
    InStack.Pop(&data);
    OutStack.Push(data);
  }
}

int main(int argc, char *argv[])
{
  int qsize = 10;
  if (argc > 1)
    qsize = atoi(argv[1]);

  cout << "Queue size: " << qsize << endl;
  cout << endl;

  MyQueue<int> q1(qsize);
  for (int i = 0; i < 4; i++)
    q1.EnQueue(i);

  q1.Show();
  int cur_data;
  for (int i = 0; i < 2; i++)
  {
    if (q1.DeQueue(&cur_data))
        cout << cur_data << " ";
    
  }
  cout << endl;
  q1.Show();

  for (int i = 0; i < 6; i++)
    q1.EnQueue(i);
  return 0; 
}
