#include <iostream>
#include <cstdlib>
#include <vector>
#include <deque>

using namespace std;

int minPos(int pos1, int pos2)
{
    if (pos1 == -1)
        return pos2;
    if (pos2 == -1)
        return pos1;

    return (pos1 < pos2) ? pos1 : pos2;
}

// Return the kth magic number and store the k magic numbers in magicNumbers
int getKthMagicNumber(int k, vector<int>& magicNumbers)
{
    deque<int> q3, q5, q7;
    q3.push_back(3);
    q5.push_back(5);
    q7.push_back(7);

    for (int i = 0; i < k; ++i)
    {
        int q3Front = q3.empty() ? -1 : q3.front();
        int q5Front = q5.empty() ? -1 : q5.front();
        int q7Front = q7.empty() ? -1 : q7.front();
        
        int minFront = minPos(minPos(q3Front, q5Front), q7Front);
        
        if (minFront == -1)
            break;

        if (minFront == q3Front) {
            q3.pop_front();
            q3.push_back(minFront * 3);
            q5.push_back(minFront * 5);
            q7.push_back(minFront * 7);
        } else if (minFront == q5Front) {
            q5.pop_front();
            q5.push_back(minFront * 5);
            q7.push_back(minFront * 7);
        } else {
            q7.pop_front();
            q7.push_back(minFront * 7);
        }

        magicNumbers.push_back(minFront);

    }

    return magicNumbers.back();
}

int main(int argc, char** argv)
{
    if (argc < 2) {
        cout << "Usage: 7_7 k" << endl;        
        return 1;
    }

    int k = atoi(argv[1]);

    vector<int> nums;
    int kthNum = getKthMagicNumber(k, nums);

    cout << "List of magic numbers: ";
    for (int i = 0; i < nums.size(); ++i)
    {
        cout << nums.at(i) << ", ";
    }
    cout << endl;
    cout << "Kth magic number = " << kthNum << endl;

    return 0;
}
