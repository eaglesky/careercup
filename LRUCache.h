#include <unordered_map>

typedef struct DoubleListNode {
    int data;
    struct DoubleListNode* prev;
    struct DoubleListNode* next;
} DoubleListNode;

class LRUCache {
public:
    LRUCache(int size);
    ~LRUCache();

    void insert(int pgNum);
    void printCache();

private:
    DoubleListNode* stack;
    DoubleListNode* tail;
    int cacheSize;
    int curSize;

    std::unordered_map<int, DoubleListNode*> map;
};


