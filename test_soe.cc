#include <iostream>
#include <cmath>

using namespace std;

// Return a bool array indicating which integers(no greater than max) are
// primes and which are not
// The time complexity of this algorithm is O(nloglogn)
bool* sieveOfEratosthenes(int max)
{
    // Initialize flag array
    bool* ret = new bool[max + 1];
    for (int i = 0; i < max+1; ++i)
    {
        if ((i % 2 == 0 && i != 2) || (i == 1))
            ret[i] = false;
        else
            ret[i] = true;
    }

    int nextPrime = 3;
    while (nextPrime <= sqrt(max))
    {
        for (int i = nextPrime * nextPrime; i < max + 1; i += nextPrime)
        {
            ret[i] = false;
        }

        do {
            ++nextPrime;
        } while (!ret[nextPrime]);
    }
       
    return ret;

}

void printBoolArray(bool* arr, int len)
{
    
    for (int i = 0; i < len; i++)
    {
        if (arr[i])
            cout << i << endl;
    }
}

int main(int argc, char** argv)
{
    int max = 10;
    bool* arr = sieveOfEratosthenes(max);
    printBoolArray(arr, max+1);

    delete[] arr;
    return 0;
}
