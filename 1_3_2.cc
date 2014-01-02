#include <iostream>
#include <cstring>

//Time comlexity = O(n); Space complexity = O(1)
void remove_dup1(char* str)
{
    int flags[256];
    memset(flags, 0, sizeof(flags));

    if (str) {
        int len = strlen(str);
        if (len > 0) {
            char* p = str + 1;
            char* tail = p;
            flags[*str] = 1;

            while(*p)
            {
                if (flags[*p] == 0) {
                    flags[*p] = 1;
                    *tail = *p;
                    tail++;
                       
                }

                p++;
            }

            *tail = 0;
        }    
    }
}

//Time complexity = O(n^2); Space complexity = O(1);
void remove_dup2(char* str)
{
    if (str) {
        int len = strlen(str);
        if (len > 0) {
            int tail = 1;
            for (int i = 1; i < len; i++)
            {
                int j;
                for (j = 0; j < tail; j++)
                    if (str[j] == str[i])
                        break;

                if (j == tail) {
                    str[tail] = str[i];
                    tail++;
                }
            }
            str[tail] = 0;
        }
    }
}

int main(int argc, char** argv)
{
   /* char* str1 = NULL;
    char str2[] = "";
    char str3[] = "abcdef";
    char str4[] = "bacdadb";
    char str5[] = "aabbcdd";
    char str6[] = "cccc";*/

    char test_strs[][20] = {"", "abcdef", "bacdadb", "aabbcdd", "cccc"};

    for (int i = 0; i < 5; i++)
    {
        std::cout << "Test" << i << ": " << std::endl;
        remove_dup2(test_strs[i]);
        std::cout << test_strs[i] << std::endl;
        std::cout << std::endl;
    }

    std::cout << "Test5: " << std::endl;
    remove_dup2(NULL);
  
    return 0;
}
