#include "MyCircleLinkedList.h"
#include <cstdlib>
#include <ctime>

using namespace std;

int main(int argc, char *argv[])
{
  CLinkedList<int> list;
  int s_len = 3;//Length before loop
  int l_len = 3;//Length of the loop

  if (argc > 1) {
    s_len = atoi(argv[1]);
    if (argc >2)
      l_len = atoi(argv[2]);
  } 
 
  list.CreateCList(s_len,l_len);
  list.Show();

  cout << "Loop Start: " << list.get_data(list.GetLoopStart()) << endl;
  return 0;
}
