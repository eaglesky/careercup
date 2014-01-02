#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>

bool is_anagram(const std::string s1, const std::string s2)
{
    std::string str1 = s1;
    std::string str2 = s2;
   
    std::sort(str1.begin(), str1.end());
    std::sort(str2.begin(), str2.end());

    return (str1 == str2);
}

bool is_anagram2(const std::string s1, const std::string s2)
{
    int flags[256];
    memset(flags, 0, sizeof(flags));

    if (s1.size() != s2.size())
        return false;

    for(std::string::const_iterator it = s1.begin(); it != s1.end(); it++)
    {
        flags[*it]++;    
    }

    for (std::string::const_iterator it = s2.begin(); it != s2.end(); it++)
    {
        if (flags[*it] == 0)
            return false;
        else
            flags[*it]--;
    }

    return true;

}
int main(int argc, char** argv)
{
    std::string test_str1("abcde");
    std::string test_str2("bcdea");
    std::string test_str3("ccdea");

    std::cout << "(" << test_str1 << ", " << test_str2 << "): " << is_anagram(test_str1, test_str2) << std::endl;

    std::cout << "(" << test_str1 << ", " << test_str2 << ")2: " << is_anagram2(test_str1, test_str2) << std::endl;

    std::cout << "(" << test_str3 << ", " << test_str2 << "): " << is_anagram(test_str3, test_str2) << std::endl;
    
    std::cout << "(" << test_str3 << ", " << test_str2 << ")2: " << is_anagram2(test_str3, test_str2) << std::endl;
    
    return 0;
}
