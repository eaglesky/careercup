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

    if ((s == e) && (key == a[s])) {
        return s;
    } else if (s < e) {
       int mid = s + (e - s) / 2;

       if (key <= a[mid])
          return binSearch(a, key, s, mid);
        else
          return binSearch(a, key, mid+1, e);
    } else
        return -1;
} 


int binSearchIter(int* a, int n, int key)
{
   int s = 0;
   int e = n-1;
   int mid;
   while (s < e) {
       mid = s + (e - s) / 2;

       if (a[mid] >= key)
           e = mid;
       else
           s = mid + 1;
   }
   
   if ((s==e)&&(key==a[s]))
       return s;
   else
       return -1;
}

int main(int argc, char** argv)
{
    int test1[] = {2, 4, 5, 6, 44};
    int test2[] = {1, 2, 3, 55};
    int test3[] = {-4};
    int test4[] = {1, 2, 3, 6, 6, 12, 23, 34};
    int test5[] = {1, 2, 3, 6, 6, 12, 23, 34, 56};

    std::cout << "Test1: ";
    printArray(test1, 5);
    std::cout << std::endl;
  //  int id = binSearchIter(test1, 5, 4);
    int id = binSearch(test1, 4, 0, 4);
    std::cout << "4: " << id << std::endl;
//    id = binSearchIter(test1, 5, 44);
    id = binSearch(test1, 44, 0, 4);
    std::cout << "44: " << id << std::endl;
//    id = binSearchIter(test1, 5, 7);
    id = binSearch(test1, 7, 0, 4);
    std::cout << "7: " << id << std::endl;

    std::cout << "Test2: ";
    printArray(test2, 4);
    std::cout << std::endl;
    id = binSearchIter(test2, 4, 2);
    std::cout << "2: " << id << std::endl;
    id = binSearchIter(test2, 4, 55);
    std::cout << "55: " << id << std::endl;
    id = binSearchIter(test2, 4, -3);
    std::cout << "-3: " << id << std::endl;

    std::cout << "Test3: ";
    printArray(test3, 1);
    std::cout << std::endl;
    id = binSearchIter(test3, 1, -4);
    std::cout << "-4: " << id << std::endl;
    id = binSearchIter(test3, 1, -6);
    std::cout << "-6: " << id << std::endl;

    std::cout << "Test4: ";
    printArray(test4, 8);
    std::cout << std::endl;
 //   id = binSearchIter(test4, 8, 6);
    id = binSearch(test4, 6, 0, 7);
    std::cout << "6: " << id << std::endl;

    std::cout << "Test5: ";
    printArray(test5, 9);
    std::cout << std::endl;
//    id = binSearchIter(test5, 9, 6);
    id = binSearch(test5, 6, 0, 8);
    std::cout << "6: " << id << std::endl;
    return 0;
}
