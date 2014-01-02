#include <iostream>

bool replace_blks(char* str, int len)
{
    int blk_num = 0;
    if (!str)
        return true;

    int i;
    for (i = 0; str[i] != 0; i++)
        if (str[i] == ' ')
            blk_num++;

    if (i + 2*blk_num >= len)
        return false;

    for (; i >= 0; i--)
    {
        int new_id;
        if (str[i] == ' ') {
            blk_num--;
            new_id = i + 2*blk_num;
            str[new_id] = '%';
            str[new_id+1] = '2';
            str[new_id+2] = '0';
        } else {
            new_id = i + 2*blk_num;
            str[new_id] = str[i];
        }
    }

    return true;

}


int main(int argc, char** argv)
{
    char str1[50] = "Allen Chin is a hero!";

    if (replace_blks(str1, 50))
        std::cout << "After replacing1(len=50): " << str1 << std::endl;

    char str2[50] = " Allen Chin  is a hero!   ";
    if (replace_blks(str2, 50))
        std::cout << "After replacing2(len=50): " << str2 << std::endl;

    char str3[50] = "Allen";
    if (replace_blks(str3, 50))
        std::cout << "After replacing3(len=50): " << str3 << std::endl;

    char str4[50] = "Allen Chin";
    if (replace_blks(str4, 12))
        std::cout << "After replacing4(len=12): " << str4 << std::endl;

    char str5[50] = " Allen Chin  is a hero!   ";
    if (replace_blks(str5, 45))
        std::cout << "After replacing5(len=45): " << str5 << std::endl;

    char str6[50] = "";
    if (replace_blks(str6, 2))
        std::cout << "After replacing6(len=2): " << str6 << std::endl;

    return 0;
}
