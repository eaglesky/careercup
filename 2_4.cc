#include "MySinglyLinkedList.h"
#include <cstdlib>
#include <ctime>

using namespace std;

int main(int argc, char *argv[])
{
  int list_len1 = 5;
  int list_len2 = 5;
  srand(time(0));
  if (argc > 1) {
    list_len1 = atoi(argv[1]);
    if (argc >2)
      list_len2 = atoi(argv[2]);
  }

//  LinkedList<int> list1, list2, sum;
  LinkedList<int> list1;
  LinkedList<int> list2;
  LinkedList<int> sum;
  for (int i = 0; i < list_len1; i++)
  {
    int cur_data1 = rand() % 10;
    list1.PushNode(cur_data1);
  }

  for (int i = 0; i < list_len2; i++)
  {
    int cur_data2 = rand() % 10;
    list2.PushNode(cur_data2);
  }
  try {
    cout << "List1: " << endl;
    list1.Show();
    cout << endl;

    cout << "List2: " << endl;
    list2.Show();
    cout << endl;

    sum = list1+list2;
    cout << "Sum: " << endl;
    sum.Show();
  } catch (const char *err) {
    cout << err << endl;
  }
  return 0;
}

