#include <iostream>

int searchRotate(int* a, int s, int e, int key)
{
    if (s <= e) {
        int mid = (s + e) / 2;
        if (((a[s] < a[e])&&(key >= a[s])&&(key <= a[e]))||
                ((a[s] >= a[e])&&((key >= a[s])||(key <= a[e])))) {
            if (a[mid] == key)
                return mid;
            else if (key < a[mid])
                return searchRotate(a, s, mid-1, key);
            else
                return searchRotate(a, mid+1, e, key);
        }
    }
    return -1;
}

void printArray(int* a, int n)
{
    for (int i = 0; i < n; i++)
    {
        std::cout << a[i] << ", ";
    }
}

int main(int argc, char** argv)
{
    int tests[][6] = {{0, 1, 2, 3, 4, 5}, {1, 2, 3, 4, 5, 0}, {2, 3, 4, 5, 0, 1}, 
                      {3, 4, 5, 0, 1, 2}, {4, 5, 0, 1, 2, 3}, {5, 0, 1, 2, 3, 4}};

    int tests2[][3] = {{-3, 44, 55}, {44, 55, -3}, {55, -3, 44}};
    int tests3[][9] = {{33, 55, 55, 77, 77, 77, 88, 99, 99}, {55, 55, 77, 77, 77, 88, 99, 99, 33}, 
                       {77, 77, 77, 88, 99, 99, 33, 55, 55}};
    int tests4[][4] = {-4, -4, -4, -4};

    for (int i = 0; i < 6; i++)
    {
        std::cout << "Tests: ";
        printArray(tests[i], 6);
        std::cout << std::endl;
        std::cout << " Index of 3: " << searchRotate(tests[i], 0, 5, 3) << std::endl;
        std::cout << " Index of 6: " << searchRotate(tests[i], 0, 5, 6) << std::endl;
        std::cout << " Index of -4: " << searchRotate(tests[i], 0, 5, -4) << std::endl;
    }

    std::cout << std::endl;
    for (int i = 0; i < 3; i++)
    {
        std::cout << "Tests2: ";
        printArray(tests2[i], 3);
        std::cout << std::endl;
        std::cout << " Index of 44: " << searchRotate(tests2[i], 0, 2, 44) << std::endl;
        std::cout << " Index of 45: " << searchRotate(tests2[i], 0, 2, 45) << std::endl;
    }

    std::cout << std::endl;
    for (int i = 0; i < 3; i++)
    {
        std::cout << "Tests3: ";
        printArray(tests3[i], 9);
        std::cout << std::endl;
        std::cout << " Index of 77: " << searchRotate(tests3[i], 0, 8, 77) << std::endl;
        std::cout << " Index of 56: " << searchRotate(tests3[i], 0, 8, 56) << std::endl;
    }

    std::cout << std::endl;
    std::cout << "Tests4: ";
    printArray(tests4[0], 4);
    std::cout << std::endl;
    std::cout << " Index of -4: " << searchRotate(tests4[0], 0, 3, -4) << std::endl;
    std::cout << " Index of 10: " << searchRotate(tests4[0], 0, 3, 10) << std::endl;


    return 0;
}
