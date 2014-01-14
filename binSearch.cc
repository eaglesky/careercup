#include <iostream>
void printArray(int* a, int n)
{
    for (int i = 0; i < n; i++)
    {
        std::cout << a[i] << ", ";
    }
}


int binSearch(int* a, int key, int s, int e)
{
    if (!a)
        return -1;

    int mid = (s+e)/2;
    if (key == a[mid])
        return mid;
    if (s < e) {
       if (key < a[mid])
          return binSearch(a, key, s, mid-1);
        else
          return binSearch(a, key, mid+1, e);
    } else
        return -1;
} 

int binSearch(int* a, int n, int key)
{
   int s = 0;
   int e = n-1;
   int mid;
   while (s < e) {
       mid = (s+e)/2;
       if (a[mid] == key)
           break;
       if (a[mid] > key)
           e = mid - 1;
       else
           s = mid + 1;
   }
   if (s < e)
       return mid;
   else if ((s==e)&&(key==a[s]))
       return s;
   else
       return -1;
}

int main(int argc, char** argv)
{
    int test1[] = {2, 4, 5, 6, 44};
    int test2[] = {1, 2, 3, 55};
    int test3[] = {-4};

    std::cout << "Test1: ";
    printArray(test1, 5);
    std::cout << std::endl;
   // int id = binSearch(test1, 4, 0, 4);
    int id = binSearch(test1, 5, 4);
    std::cout << "4: " << id << std::endl;
//    id = binSearch(test1, 44, 0, 4);
    id = binSearch(test1, 5, 44);
    std::cout << "44: " << id << std::endl;
    id = binSearch(test1, 5, 7);
    std::cout << "7: " << id << std::endl;

    std::cout << "Test2: ";
    printArray(test2, 4);
    std::cout << std::endl;
    id = binSearch(test2, 4, 2);
    std::cout << "2: " << id << std::endl;
    id = binSearch(test2, 4, 55);
    std::cout << "55: " << id << std::endl;
    id = binSearch(test2, 4, -3);
    std::cout << "-3: " << id << std::endl;

    std::cout << "Test3: ";
    printArray(test3, 1);
    std::cout << std::endl;
    id = binSearch(test3, 1, -4);
    std::cout << "-4: " << id << std::endl;
    id = binSearch(test3, 1, -6);
    std::cout << "-6: " << id << std::endl;
    return 0;
}
