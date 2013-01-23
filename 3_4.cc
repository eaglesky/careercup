#include "MyStacks.h"
#include <cstdlib> //Hanoi problem extension: Better solution? More rods?
using namespace std;

class Hanoi {
 public:
  explicit Hanoi(int num);
  ~Hanoi();
  void Move(int start, int end, int num);
  void ShowSizes() const;
  void ShowCount() const { cout << "Total count: " << count << endl; }
 private:
  ArrayStack<int> *rods;
 
  int disk_num;
  int count;
};

Hanoi::Hanoi(int num):disk_num(num),count(0) {
  rods = new ArrayStack<int>[3];
  for (int i = 0; i < 3; i++)
  {
    rods[i] = ArrayStack<int>(num);  //Is it OK?
  }
  for(int i = 0; i < num; i++)
    rods[0].Push(i+1);
}

Hanoi::~Hanoi()
{
  delete []rods;
}

void Hanoi::ShowSizes() const
{
  cout << "stack sizes: " << endl;
  for(int i = 0; i < 3; i++)
    cout << rods[i].get_size() <<" ";
  cout << endl;
}

void Hanoi::Move(int start, int end, int num)
{
  int middle = 3 - start - end;
  if (num > 1) {
    Move(start, middle, num - 1);
    Move(start, end, 1);
    Move(middle, end, num - 1);
  } else {
    int disk = 0;
    rods[start].Pop(disk);
    rods[end].Push(disk);
    cout << "Disk " << disk << " moved from " << start << " to " << end << endl;
    count++;
  }

}

int main(int argc, char *argv[])
{
  int disk_num = 10;

  if (argc > 1)
    disk_num = atoi(argv[1]);

  cout << "Disk Number is " << disk_num << endl;

  Hanoi han(disk_num);
  han.ShowSizes();
  cout << endl;

  han.Move(0, 2, disk_num);
  cout << endl;
  han.ShowCount();
}
