#include "sortings.h"
#include <cstring>
#include <vector>

typedef struct StrNode {
    std::string str;
    struct StrNode* next;
    struct StrNode* tail;
} StrNode;

void sortStringsMSD(std::string* strs, int s, int e, int d)
{
    if (s < e) {
        StrNode* buckets[256];
        std::vector<int> counts;

        memset(buckets, 0, 256*sizeof(StrNode*));

        for (int i = s; i <= e; i++)
        {
            int bId = (d >= strs[i].size())?0:strs[i].at(d);
            StrNode* newNode = new StrNode;
            newNode->str = strs[i];
            newNode->next = NULL;

            if (!buckets[bId]) 
                buckets[bId] = newNode;
            else {
                buckets[bId]->tail->next = newNode;
            }      
            buckets[bId]->tail = newNode;
        }
        int strId = s;
        int shift = 0;
        for (int i = 0; i < 256; i++)
        {
            if (buckets[i]) {
                StrNode* p = buckets[i];
                while(p) {
                    StrNode* q = p;
                    p = p->next;
                    strs[strId] = q->str;
                    std::cout << d << ": " << strs[strId] << std::endl;
                    delete q;
                    strId++;
                    shift++;
                }
                counts.push_back(shift);
            }
        }

        int start = 0;
        for (int i = 0; i < counts.size(); i++)
        {
            if (strs[s+start].size() > d)
                 sortStringsMSD(strs, s+start, s+counts[i]-1, d+1);
            start = counts[i];
        }
    }
}

int main(int argc, char** argv)
{
    std::string test1[8];
    test1[0] = std::string("Chin");
    test1[1] = std::string("Rii");
    test1[2] = std::string("Pizza");
    test1[3] = std::string("Allen");
    test1[4] = std::string("China");
    test1[5] = std::string("Al");
    test1[6] = std::string("Rii");
    test1[7] = std::string("Allen");

    sortStringsMSD(test1, 0, 7, 0);
    for (int i = 0; i < 8; i++)
    {
        std::cout << test1[i] << std::endl;
    }
    return 0;
}
