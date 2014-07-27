#include <cstdlib>
#include <iostream>
#include <fstream>
using namespace std;

// Print the string array for debugging
void printKStrs(string* kstrs, int k)
{
    for (int i = 0; i < k; ++i)
        cout << kstrs[i] << "; ";
    cout << endl;
}

void printLastKLines(char* fileName, int k)
{
    ifstream fin(fileName);
    if (!fin) {
        cout << "Error: unable to open input file:" << fin << endl;
        return;
    }


    int arraySize = k+1;
    // Note that the EOF symbol is stored too!
    string* kstrs = new string[arraySize];
    int end = -1;
   
    bool isFull = false;
    while(!fin.eof()) {
        end = (end + 1) % arraySize;
        getline(fin, kstrs[end]);
        
        if (end == arraySize - 1)
            isFull = true;

        //printKStrs(kstrs, arraySize);
    }

    int start = (end + 1) % arraySize;
    int newEnd = start + k;
    if (!isFull) {
        start = 0;
        newEnd = end;     
    }

    for (int i = start; i < newEnd; ++i)
    {
        cout << kstrs[i % arraySize] << endl;
    }

    fin.close();
    delete[] kstrs;
}

int main(int argc, char** argv)
{
    if (argc < 3) {
        cout << "Usage: 13_1 file_name k" << endl;
        return -1;
    }

    int k = atoi(argv[2]);
    if (k < 0) {
        cout << "k must not be negative!" << endl;
        return -1;
    }
    printLastKLines(argv[1], k);

    return 0;
}
