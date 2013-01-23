#include "MyStacksMin.h"
#include <cstdlib>
#include <ctime>
using namespace std;

int main(int argc, char *argv[])
{
  int stacksize = 10;
  
  if (argc > 1)
    stacksize = atoi(argv[1]);

  ArrayStackMin<int> s1(stacksize);

  int cur_num;
  srand(time(0));

  for (int i = 0; i < stacksize; i++)
  {
    cur_num = rand() % 20;
    s1.Push(cur_num);
  }
  int cur_min;
  s1.GetMin(&cur_min);
  s1.Show();
  cout << "min: " << cur_min << endl;
  s1.ShowMin();

  cout << endl;
  cout << "Begin Popping:" << endl;
  for (int i = 0; i < stacksize/2; i++)
    s1.Pop(cur_num);
  s1.Show();
  s1.GetMin(&cur_num);
  cout << "min: " << cur_num << endl;
  s1.ShowMin();

  for (int i = 0; i < stacksize; i++)
    s1.Pop(cur_num);
  s1.Show();
  s1.ShowMin();
  return 0;
}
