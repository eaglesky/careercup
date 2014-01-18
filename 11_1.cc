#include <iostream>

//Assume A is large enough to hold all the elements in A and B
//Solve it in linear time, in place
void merge(int* A, int* B, int nA, int nB)
{
    int ia = nA - 1;
    int ib = nB - 1;
    int iMerge = nA + nB - 1;

    while ((ia >= 0)||(ib >= 0)) {

        if ((ia >= 0)&&(ib >= 0)) {
            if (A[ia] > B[ib]) {
                 A[iMerge] = A[ia];
                 ia--;
            } else {
                A[iMerge] = B[ib];
                ib--;
            }

        } else if (ib >= 0){
            A[iMerge] = B[ib];
            ib--;
        } else
            break;
       
        iMerge--;
    }
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
    int A1[] = {1, 2, 9, 33, 0, 0, 0, 0, 0, 0, 0};
    int B1[] = {-4, 3, 8, 9, 44};
    int B2[] = {-10, -1, -2};
    int B3[] = {44};
    int A2[] = {44, 0, 0, 0, 0, 0, 0, 0};

    std::cout << "Test1: " << std::endl;
    std::cout << "A1: ";
    printArray(A1, 4);
    std::cout << std::endl;
    std::cout << "B1: ";
    printArray(B2, 3);
    std::cout << std::endl;
    merge(A1, B2, 4, 3);
    printArray(A1, 7);
    std::cout << std::endl;

    std::cout << "Test2: " << std::endl;
    std::cout << "A2: ";
    printArray(A2, 1);
    std::cout << std::endl;
    std::cout << "B2: ";
    printArray(B2, 3);
    std::cout << std::endl;
    merge(A2, B2, 1, 3);
    printArray(A2, 4);
    std::cout << std::endl;
    return 0;
}
