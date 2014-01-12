#include <iostream>
#include "LRUCache.h"
int main(int argc, char** argv)
{
    int test1[] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2, 1, 2, 0, 1, 7, 0, 1};
    
    LRUCache lru(3);

    for (int i = 0; i < 20; i++)
    {
        std::cout << test1[i] << ": ";
        lru.insert(test1[i]);
        lru.printCache();
        std::cout << std::endl;
    }

    int test2[] = {1, 2, 3, 1, 4, 5};
    LRUCache lru2(4);
    for (int i = 0; i < 6; i++)
    {
        std::cout << test2[i] << ": ";
        lru2.insert(test2[i]);
        lru2.printCache();
        std::cout << std::endl;
    }
    return 0;
}
