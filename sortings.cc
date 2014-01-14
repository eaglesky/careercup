#include <iostream>

void printArray(int* a, int n)
{
    for (int i = 0; i < n; i++)
    {
        std::cout << a[i] << ", ";
    }
}

void insertionSort(int *a, int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = a[i];
        int j;
        for (j = i-1; j >= 0; j--)
        {
            if (a[j] > key) {
                a[j+1] = a[j];
            } else
                break;
        }
        a[j+1] = key;
    }
}

void bubbleSort(int* a, int n)
{
    bool isChanged = true;
    for (int i = 0; i < n; i++)
    {
        if (!isChanged)
            break;
        isChanged = false;

        for (int j = 0; j < n-i-1; j++)
        {
            if (a[j] > a[j+1]) {
                int tmp = a[j+1];
                a[j+1] = a[j];
                a[j] = tmp;
                isChanged = true;
            }
        }
    }
}

void selectionSort(int* a, int n)
{
    for (int i = 0; i < n-1; i++)
    {
        int minId = i;
        for (int j = i+1; j < n; j++)
        {
            if (a[j] < a[minId])
                minId = j;
        }
        if (minId != i) {
            int tmp = a[i];
            a[i] = a[minId];
            a[minId] = tmp;
        }
    }
}

void merge(int* a, int s, int e)
{
    int mid = (e - s)/2 + s;
    int len1 = mid - s + 1;
    int len2 = e - mid;
    int* L = new int[len1];
    int* R = new int[len2];
    
    int i = 0;
    int j = 0;
    int t = s;

    for (int u = 0; u < len1; u++)
        L[u] = a[s+u];
    for (int u = 0; u < len2; u++)
        R[u] = a[mid+1+u];

    for (; t <= e; t++)
    {
        if ((i < len1) && (j < len2)) {
          if (L[i] < R[j]) {
              a[t] = L[i];
              i++;
          } else {
              a[t] = R[j];
              j++;
          }
 
        } else if (i < len1) {
            a[t] = L[i];
            i++;
        }
        else {
            a[t] = R[j];
            j++;
        }
    }
   /* while((i < len1)&&(j < len2))
    {
        if (L[i] < R[j]) {
            a[t] = L[i];
            i++;
        } else {
            a[t] = R[j];
            j++;
        }
        t++;
    }
    if (i < len1) {
        for (; i < len1; i++)
        {
            a[t] = L[i];
            t++;
        }
    }

    if (j < len2) {
        for (; j < len2; j++)
        {
            a[t] = R[j];
            t++;
        }
    }*/

    delete L;
    delete R;
}

void mergeSort(int* a, int s, int e)
{
    if (e > s) {
        int mid = (e - s)/2 + s;
        mergeSort(a, s, mid);
        mergeSort(a, mid+1, e);
        merge(a, s, e);
    }
}
int main(int argc, char** argv)
{
    int test1[] = {5, 3, 1, 6, 2};
    int test2[] = {4, 2, -1};
    int test3[] = {1, 2, 3, 4};
    int test4[] = {4};

    std::cout << "Test1: ";
    printArray(test1, 5);
    std::cout << std::endl;
//    insertionSort(test1, 5);
//    std::cout << "Insertion Sort: ";
 //   bubbleSort(test1, 5);
//    std::cout << "Bubble Sort: ";
//    selectionSort(test1, 5);
//    std::cout << "Selection Sort: ";
    mergeSort(test1, 0, 4);
    std::cout << "Merge Sort: ";
    printArray(test1, 5);
    std::cout << std::endl;

    std::cout << "Test2: ";
    printArray(test2, 3);
    std::cout << std::endl;
 //   insertionSort(test2, 3);
 //   std::cout << "Insertion Sort: ";
//    bubbleSort(test2, 3);
//    std::cout << "Bubble Sort: ";
//    selectionSort(test2, 3);
//    std::cout << "Selection Sort: ";
    mergeSort(test2, 0, 2);
    std::cout << "Merge Sort: ";
    printArray(test2, 3);
    std::cout << std::endl;
   
    std::cout << "Test3: ";
    printArray(test3, 4);
    std::cout << std::endl;
//    insertionSort(test3, 4);
//    std::cout << "Insertion Sort: ";
//    bubbleSort(test3, 4);
//    std::cout << "Bubble Sort: ";
//    selectionSort(test3, 4);
//    std::cout << "Selection Sort: ";
    mergeSort(test3, 0, 3);
    std::cout << "Merge Sort: ";
    printArray(test3, 4);
    std::cout << std::endl;
  
    std::cout << "Test4: ";
    printArray(test4, 1);
    std::cout << std::endl;
//    insertionSort(test4, 1);
//    std::cout << "Insertion Sort: ";
//    bubbleSort(test4, 1);
//    std::cout << "Bubble Sort: ";
//    selectionSort(test4, 1);
//    std::cout << "Selection Sort: ";
    mergeSort(test4, 0, 0);
    std::cout << "Merge Sort: ";
    printArray(test4, 1);
    std::cout << std::endl;
    
    return 0;
}
