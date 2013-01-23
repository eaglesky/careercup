#include <cstdlib>    //Including this lib in order to use exit()
#include <iostream>
#include <string>
using namespace std;

class Anagram {
 public:
  Anagram();
  void GetStrings();
  bool IsAnagrams();

 private:
  string str1;
  string str2; 
  int str1_len;
  int str2_len;
  int char_count1[26];
  int char_count2[26]; 
};

Anagram::Anagram()
{
  for (int i = 0; i < 26; i++)
    {
      char_count1[i] = char_count2[i] = 0;
    }
}

void Anagram::GetStrings()
{
  bool err = true;
    
  cout << "Input String 1: ";
  cin >> str1;
  str1_len = str1.size();   
   
  cout << "Input String 2: ";
  cin >> str2;
  str2_len = str2.size();
}

bool Anagram::IsAnagrams()
{
  if (str1_len != str2_len){
    return false;
  } else {
    for (int i = 0; i < str1_len; i++)
    {
      if (!isalpha(str1[i])||!isalpha(str2[i])) {
        throw("Invalid string!");
      }

      str1[i] = tolower(str1[i]);
      str2[i] = tolower(str2[i]);
      char_count1[str1[i] - 97]++;
      char_count2[str2[i] - 97]++;  
    }
    for (int i = 0; i < 26; i++)
    {
      if (char_count1[i] != char_count2[i])
        return false;
    }
    return true;
  }
}

int main()                         //At first the error throwed was not catched due to unknow reasons,
{                                  //but this problem was solved by creating similar and simpler debugging program ! :)
  try {
    Anagram ana;
    ana.GetStrings();
    if (ana.IsAnagrams())
      cout << "The two strings are anagrams!" << endl;
    else
      cout << "The two strings are not anagrams!" << endl;
  } catch (char const *err) {
    cout << err << endl;
  }
  return 0; 
}
