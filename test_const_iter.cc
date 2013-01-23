#include <iostream>
#include <vector>
using namespace std;

int main()
{
  vector<int> v1(5);
  for (int i = 0; i < 5; i++)
  { 
    v1[i] = i;
    cout << v1[i] << " ";
  }
  cout << endl;
  const vector<int>::iterator iter = v1.begin();
  *iter = 10;
 // iter++;    //Should error

  vector<int>::const_iterator citer = v1.begin();
 // *citer = 10;  //Shoud error
   citer++;

  return 0;
}
