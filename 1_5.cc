#include <iostream>
#include <string>
using namespace std;

void replace(string &str, string &new_str)
{
  int str_len = str.size();
  for (int i = 0; i < str_len; i++)
  {
    if (str[i] == ' '){
      new_str = new_str + "%20";
    } else {
      new_str = new_str + str[i];
    }
  }
}

int main()
{
  string test_string;
  string replaced_string;
  cout << "Input the string: " << endl;
  getline(cin, test_string);
  cout << endl;
  cout << "The string is: " << endl;
  cout << test_string << endl;
  cout << endl;
  replace(test_string, replaced_string);
  cout << "After replacing:" << endl;
  cout << replaced_string << endl;
  return 0;
}
