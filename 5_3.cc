#include <iostream>
typedef unsigned int UINT;

UINT getNext(UINT n)
{
    UINT iter = 1;
    int nbits = sizeof(int)*8;

    int p = 0;
    int c0 = 0;
    int c1 = 0;


    if (n == 0)
        return 0;

    int i;
    for (i = 0; i < nbits; i++)
    {
        if (i > 0)
            iter = iter << 1;

        if (n & iter) {
            c1++;
        } else {

            if (c1 > 0)
                break;

            c0++;
        }
    }

    if (i == nbits)
        return n;


    return (n + (1 << c0) + ((1 << (c1-1)) - 1));
}

UINT getPrev(UINT n)
{
    UINT iter = 1;
    int nbits = sizeof(int)*8;

    int p = 0;
    int c0 = 0;
    int c1 = 0;


    if (n == 0)
        return 0;


    int i;
    for (i = 0; i < nbits; i++)
    {
        if (i > 0)
            iter = iter << 1;

        if (n & iter) {
            if (c0 > 0)
                break;

            c1++;
        } else {
            c0++;
        }
    }

    if (i == nbits)
        return n;

//    std::cout << "c0 = " << c0 << ", c1 = " << c1 << std::endl;
    return (n - (1 << c1) - ((1 << (c0-1)) - 1));

     
}

void printBinary(int n)
{
    int nbits = sizeof(n)*8;

    int mask = (1 << (nbits - 1));

    for (int i = 0; i < nbits; i++)
    {
        if (n & mask)
            std::cout << 1;
        else
            std::cout << 0;

        n = n << 1;
    }

    std::cout << std::endl;
}

int main(int argc, char** argv)
{

    UINT tests[] = {0b1011100, 0b10111, 0b11111111111100000000000000000000, 
                    0b10000000000000000000000000000001, 0, ~0, 0b01111111111111111111111111111111};

    for (int i = 0; i < 7; i++)
    {
        std::cout << "Test: ";
        printBinary(tests[i]);
        std::cout << "Next: ";
        printBinary(getNext(tests[i]));
        std::cout << "Prev: ";
        printBinary(getPrev(tests[i]));
        std::cout << std::endl;
    }
    
    return 0;
}
