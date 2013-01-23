#include "MyStacks.h"

using namespace std;

int main()
{
  ArrayStack<int> stack1(15);
  cout << "Test stack1: " << endl;
  for (int i = 0; i < 12; i++)
    stack1.Push(i);
  stack1.Show();
  for (int i = 0; i < 4; i++)
  {
    int cur_data;
    if (stack1.Pop(cur_data))
      cout << cur_data << endl;
  }
  cout << "Left:" << endl;
  stack1.Show();
  
  for (int i = 0; i < 20; i++)
  {
    int cur_data;
    if (stack1.Pop(cur_data))
      cout << cur_data << endl;
     
  }
  cout << "Last Left:" << endl;
  stack1.Show();

  ListStack<int> stack2;
  cout << "Test stack2: " << endl;
 for (int i = 0; i < 12; i++)
    stack2.Push(i);
  stack2.Show();
  for (int i = 0; i < 4; i++)
  {
    int cur_data;
    if (stack2.Pop(&cur_data))
      cout << cur_data << endl;
  }
  cout << "Left:" << endl;
  stack2.Show();
  
  for (int i = 0; i < 20; i++)
  {
    int cur_data;
    if (stack2.Pop(&cur_data))
      cout << cur_data << endl;
     
  }
  cout << "Last Left:" << endl;
  stack2.Show();

}
