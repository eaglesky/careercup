#include "MySinglyLinkedList.h"
#include <cstdlib>
#include <ctime>

using namespace std;

int main(int argc, char *argv[])
{
  int list_len = 5;
  srand(time(0));
  if (argc > 1)
    list_len = atoi(argv[1]);

  LinkedList<int> test_list;

  for (int i = 0; i < list_len; i++)
  {
    int cur_data = rand()%list_len;      
    test_list.PushNode(cur_data);
  }
  test_list.Show();
  if (test_list.CopyDeleteMiddle()) {
    cout << "After Deletion:" << endl;
    test_list.Show();
  } else {
    cout << "Copy Deletion Failed!" << endl;
  }
}

