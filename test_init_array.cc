#include <iostream>

int main(int argc, char** argv)
{
    int array[3][4] = {1};

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
            std::cout << array[i][j] << ", ";

        std::cout << std::endl;
    }
    return 0;
}
