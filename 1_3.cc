/**
 * @file            1_3.cpp
 * @author          Yalun Qin
 * @date            Sat, 05 Jan 2013 13:43:07 +0800
 * @version         1.0
 * @brief           Removing the duplicate characters in a string without using 
 *                  any additional buffer.
 * @Test Case:      1. Empty string;                                 ""
 *                  2. String with different characters;             "abcde"
 *                  3. String with continuous duplicate characters;  "bcaadee"
 *                  4. String with discrete duplicate characters.    "abcdab"
 */
#include <iostream>
#include <string>
using namespace std;

/**
 *  Removing duplicate characters from an input string
 *  O(n^2) in time, O(1) in space
 *
 *  @param[in] str   Tested string
 */
void rm_dup(string &str)
{
  int len = str.size();
  int rm_num = 0;
  for (int i = 0; i < len - 1; i++)
    for (int j = i + 1; j < len; j++)
      {
        if (str[i] == str[j]){
          str[i] = '\0';
          rm_num++;
          break;
        }
      } 

  int null_num = rm_num; 
  while (null_num > 0)
  {
    for (int i = 0; i < len -1; i++)
      {
	if ((!str[i]) && (str[i+1]))
	  {
	    int temp = str[i];
	    str[i] = str[i+1];
	    str[i+1] = temp;
	  }
      }
    null_num--;
  }
  str.resize(len - rm_num);
}

/*Assuming that the input string contains only visible characters*/
int main(int argc, char *argv[])
{
  if (argc == 1){
    cout << "Missing the string argument!" << endl;
    return -1;
  }
  string test_string(argv[1]);
  cout << "Original string is:" << endl;
  cout << test_string << endl;
  cout << test_string.size() << endl;

  cout << endl;
  rm_dup(test_string);
  cout << "After removing the duplicate characters:" << endl;
  cout << test_string << endl;
  cout << test_string.size() << endl;
}


