#include <iostream>
#include "LRUCache.h"

LRUCache::LRUCache(int size)
{
    cacheSize = size;
    stack = NULL;
    tail = NULL;
    curSize = 0;

}

LRUCache::~LRUCache()
{
    DoubleListNode* p = stack;
    for (int i = 0; i < cacheSize; i++)
    {
        DoubleListNode* q = p;

        if (q) {
            
            p = p->next;
            delete q;
        } else
            break;
    }
}

void LRUCache::insert(int pgNum)
{
    if (curSize < cacheSize) {
        DoubleListNode* newNode = new DoubleListNode;
        newNode->data = pgNum;
        newNode->next = NULL;
        if (curSize == 0) {
            stack = newNode;
            stack->prev = NULL;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
        }
        tail = newNode;
        curSize++;
        map[pgNum] = newNode;
    } else {
        std::unordered_map<int, DoubleListNode*>::iterator iter = map.find(pgNum);
        if (iter == map.end()) {
            DoubleListNode* newNode = new DoubleListNode;
            newNode->data = pgNum;
            newNode->next = NULL;
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
            map[pgNum] = newNode;

            DoubleListNode* p = stack;
            stack = stack->next;
            stack->prev = NULL;

            int deletedPgNum = p->data;
            map.erase(deletedPgNum);

            delete p;


        } else {
            DoubleListNode* node = iter->second;
            DoubleListNode* prevNode = node->prev;
            DoubleListNode* nextNode = node->next;

            if (nextNode) {
                 if (prevNode) {
                     prevNode->next = node->next;
                 } else {
                     stack = node->next;
                 }
            
                nextNode->prev = node->prev;
                
                tail->next = node;
                node->prev = tail;
                node->next = NULL;
                tail = node;

            }
            
         }
    }
   
}

void LRUCache::printCache()
{
    DoubleListNode* p = stack;
    while(p) {
        std::cout << p->data << ", ";
        p = p->next;
    }

    std::cout << std::endl;
    std::cout << "Number of elements: " << curSize;
    std::cout << ", front: " << (stack?stack->data:NULL);
    std::cout << ", back: " << (tail?tail->data:NULL) << std::endl;
}
