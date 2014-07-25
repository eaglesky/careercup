#include <iostream>
#include <vector>
using namespace std;

typedef struct {
    int s, e;
} Point;

int findMagicDupRec(int* A, int s, int e)
{
    if (s > e)
        return -1;

    int mid = (s + e) / 2;
    if (A[mid] == mid)
        return mid;

    int eLeft = (A[mid] < (mid - 1))? A[mid] : mid-1;
    int leftRes = findMagicDupRec(A, s, eLeft);
    if (leftRes == -1) {
        int sRight = (A[mid] > (mid + 1))? A[mid] : mid+1;
        return findMagicDupRec(A, sRight, e);
    } else 
        return leftRes;
}

int findMagicDupIter(int* A, int n)
{
    vector<Point> stack;
    Point iniPoint = {0, n-1};
    stack.push_back(iniPoint);
    
    while(!stack.empty()) {
        Point cur = stack.back();
        stack.pop_back();
        int s = cur.s;
        int e = cur.e;
        if (s > e) continue;
        int mid = (s+e)/2;
        if (A[mid] == mid)
            return mid;

        int eLeft = (A[mid] < (mid - 1))? A[mid] : mid-1;
        Point leftSeg = {s, eLeft};
        
        int sRight = (A[mid] > (mid + 1))? A[mid] : mid+1;
        Point rightSeg = {sRight, e};
        stack.push_back(rightSeg);
        stack.push_back(leftSeg);
    }
    return -1;
}

int main(int argc, char** argv)
{
    int A[] = {-10, 2, 3, 4, 5, 6, 7, 8, 8};
    int n = 9;
    cout << "Recursive: " << findMagicDupRec(A, 0, n-1) << endl;
    cout << "Iterative: " << findMagicDupIter(A, n) << endl;
    return 0;
}
