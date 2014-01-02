#include <iostream>
#include <cstring>

void reverse_str(char* str)
{
    char* end = str;
    char temp;

    if (str) {
        while (*end)
        {
            end++;
        }
        end--;

        while (str < end)
        {
            temp = *str;
            *str = *end;
            *end = temp;

            str++;
            end--;
        }  
    }

}

int main(int argc, char** argv)
{
    const char* str1 = "Allen Chin";
    char str2[20];
    strcpy(str2, str1);

    std::cout << "Length of str1 = " << strlen(str1) << ", sizeof str1 = " << sizeof(str1) << std::endl;
//    reverse_str(str1);
 //   std::cout << "Str1 reversed: " << str1 << std::endl;

    reverse_str(str2);
    std::cout << "Str2 reversed: " << str2 << std::endl;

    char str3[2];
    memset(str3, 0, sizeof(str3));
    reverse_str(str3);
    std::cout << "Str3 reversed: " << str3 << std::endl;

    char str4[] = "Ha ha I am a hero!";
    std::cout << "Before reversed, length of str4 = " << strlen(str4) << std::endl;
    reverse_str(str4);
    std::cout << "Str4 reversed: " << str4 << std::endl;
    std::cout << "After reversed, length of str4 = " << strlen(str4) << std::endl;
    std::cout << "Sizeof str4 = " << sizeof(str4) << std::endl;
    return 0;
}
