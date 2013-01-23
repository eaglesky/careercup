#include <cstdlib>
#include <ctime>
#include <iostream>
#include <list>
using namespace std;

void rm_dup(list<int> &lst)
{
  for (list<int>::iterator iter = lst.begin(); iter != lst.end();)
  {
    list<int>::iterator iter2 = iter;
    iter2++;
    while (iter2 != lst.end())
    {
      if (*iter2 == *iter) {
        list<int>::iterator iter_temp = iter;
        iter++;
        lst.erase(iter_temp);
  //        lst.erase(iter);
        break;
      }
      iter2++;
    }
    if (iter2 == lst.end())
      iter++;
  }    
}

int main(int argc, char *argv[])
{
  int list_len = 5;  //Default list length is 5
  if (argc > 1)
    list_len = atoi(argv[1]);

  srand(time(0)); 
  list<int> test_list(list_len);

  list<int>::iterator iter;
  cout << "Random list:" << endl;
  for (iter = test_list.begin(); iter !=  test_list.end(); iter++)
  { 
    *iter = rand() % list_len;
    cout << *iter << "  ";
  }
  cout << endl;
  
  rm_dup(test_list);
  cout << "After removing:" << endl;  
  for (iter = test_list.begin(); iter !=  test_list.end(); iter++)
    cout << *iter << "  ";
  cout << endl;
  return 0;
}
