#include "Singleton.h"
#include <iostream>

int Singleton::test_static = 4;
Singleton* Singleton::_instance = NULL;

Singleton::Singleton()
{
    std::cout << "Singleton constructed! " << std::endl;
}

Singleton* Singleton::Instance()
{
    if (_instance == NULL) {
        _instance = new Singleton();
    }

    return _instance;
}
