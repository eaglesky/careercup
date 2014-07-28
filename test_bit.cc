#include <iostream>
using namespace std;

void printBin(int n)
{
    unsigned int i = 1;
    int bitsNum = sizeof(int) * 8;
    for (i = 1 << (bitsNum-1); i > 0 ; i = i >> 1)
    {
        int d = (n & i) ? 1 : 0;
        cout << d;
    }
    cout << endl;
}

int main(int argc, char** argv)
{
    int a = -3;
    printBin(a);

    a = a << 3;
    printBin(a);
    return 0;
}
