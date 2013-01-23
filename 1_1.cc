/**
 * @file            1_1.cc
 * @author          Yalun Qin
 * @version         1.0
 * @date            Tue, 01 Jan 2013 13:27:00 +0800
 * @brief           This program can test if the input string has all unique characters  
 */
#include <iostream>
#include <string>
using namespace std;

/**
 * Test if the input string has all unique characters
 *
 * @param[in] str  The input string
 * @return         If unique, return true
 */
bool string_is_unique(string str)  //str 和 test_string数据域地址为何一样？ 
{
  bool hash_table[128];
  int hash_idx;
  
  for (int i = 0; i < 128; i++)
  {
    hash_table[i] = false;
  }

  for (int i = 0; i < str.size(); i++)
  {
    hash_idx = str.at(i);                //Address changes here! Why? Copy on write??? 
    if (hash_table[hash_idx])
      return false;
    else
      hash_table[hash_idx] = true;
    
  }  

  //Just for test
/*  str = "HaHa";
  cout << str << endl;*/

  return true;
}

/*All the arguments are counted as one input string */
int main(int argc, char *argv[])
{
  string test_string;
  
  if (argc == 1) {
    cout << "Missing the string argument!" <<endl;
    return -1;
  } else {
    for (int i = 1; i < argc; i++)
    {
      string cur_string(argv[i]);
      if (i > 1)
        cur_string = " " + cur_string;

      test_string = test_string + cur_string;
    }
    cout << "Tested String is:" << endl;
    cout << test_string << endl;
  }
  
  if (string_is_unique(test_string)) {
    cout << "Unique!" << endl;
  } else {
    cout << "Not Unique!" << endl;
  }

//cin.get(); //If you want to hold the window open, just uncomment this sentense!  
  return 0;
} 
