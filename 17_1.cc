#include <cstdlib>
#include <iostream>
using namespace std;

void swapInPlace(int* a, int* b)
{
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}

int main(int argc, char** argv)
{
    if (argc < 3) {
        cout << "Usage: 17_1 a b" << endl;
        return -1;
    }

    int a = atoi(argv[1]);
    int b = atoi(argv[2]);
    cout << "Before swapping: a = " << a << ", b = " << b << endl;
    swapInPlace(&a, &b);
    cout << "After swapping: a = " << a << ", b = " << b << endl;
}
