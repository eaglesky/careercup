#include <iostream>
using namespace std;

int searchString(string* strs, int s, int e, string key)
{
    if (s <= e) {
        int mid = (s+e)/2;
        int left = mid;
        int right = mid;
        while((left >= s)||(right <= e)) {
            if ((left >= s)&&(!strs[left].empty())) {
                mid = left;
                break;
            } else if ((right <= e)&&(!strs[right].empty())) {
                mid = right;
                break;
            }

            if ((left >= s)&&(key == strs[left]))
                return left;
            else if ((right <= e)&&(key == strs[right]))
                return right;
            else {
                if (left >= s)
                    left--;

                if (right <= e)
                    right++;
            }
                   
        }

        if ((left < s) && (right > e))
            return -1;

        if (key.empty()) {
            int ret = searchString(strs, s, mid-1, key) ; 
            if (ret != -1)
                return ret;
            else
                return searchString(strs, mid+1, e, key);
        }

        if (key < strs[mid])
            return searchString(strs, s, mid-1, key);
        else if (key > strs[mid])
            return searchString(strs, mid+1, e, key);
        else
            return mid;
    }
    return -1;
}

void printStrs(string* strs, int n)
{
    for (int i = 0; i < n; i++)
        cout << strs[i] << ", ";
}

int main(int argc, char** argv)
{
    string test1[3];
    test1[0] = "";
    test1[1] = "";
    test1[2] = "";
    
    string test2[8];
    test2[0] = "Allen";
    test2[1] = "Chin";
    test2[2] = "";
    test2[3] = "Hero";
    test2[4] = "";
    test2[5] = "";
    test2[6] = "Is";
    test2[7] = "";

    cout << "Test1: ";
    printStrs(test1, 3);
    cout << endl;
    cout << "Empty: " << searchString(test1, 0, 2, string("")) << endl;
    cout << "Allen: " << searchString(test1, 0, 2, string("Allen")) << endl;

    cout << "Test2: ";
    printStrs(test2, 8);
    cout << endl;
    cout << "Empty: " << searchString(test2, 0, 7, string("")) << endl;
    cout << "Allen: " << searchString(test2, 0, 7, string("Allen")) << endl;
    cout << "Hero: " << searchString(test2, 0, 7, string("Hero")) << endl;
    cout << "Bitch: " << searchString(test2, 0, 7, string("Bitch")) << endl;
    cout << "Gay: " << searchString(test2, 0, 7, string("Gay")) << endl;
    cout << "Zero: " << searchString(test2, 0, 7, string("Zero")) << endl;
   
    
    return 0;
}
