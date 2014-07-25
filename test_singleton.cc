#include "Singleton.h"
#include <iostream>
using namespace std;

int main(int argc, char** argv)
{
    Singleton* sgn = Singleton::Instance();
    Singleton* sgn2 = Singleton::Instance();

    cout << "Test_static = " << sgn->test_static << endl;
    sgn->test_static++;
    cout << "Test_static2 = " << sgn2->test_static << endl;
    return 0;
}
