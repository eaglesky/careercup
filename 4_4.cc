#include <iostream>
#include <vector>
#include <list>

typedef struct BinaryTreeNode {
    int data;
    struct BinaryTreeNode* left;
    struct BinaryTreeNode* right;
} BinaryTreeNode;

BinaryTreeNode* createBT(int* a, int start, int end)
{
    if (end < start)
        return NULL;

    BinaryTreeNode* root = new BinaryTreeNode;
    int mid = (start + end) / 2;
    root->data = a[mid];
    root->left = createBT(a, start, mid-1);
    root->right = createBT(a, mid+1, end);

    return root;
}

void destroyBT(BinaryTreeNode* bt)
{
    if (bt) {
        destroyBT(bt->left);
        delete bt;
        destroyBT(bt->right);
    }
}

void inOrderTraverse(BinaryTreeNode* bt)
{
    if (bt) {
        inOrderTraverse(bt->left);
        std::cout << bt->data << ", " ;
        inOrderTraverse(bt->right);
    }    
}

typedef struct LinkNode {
    int data;
    struct LinkNode* next;
} LinkNode;

std::vector<LinkNode*> findDepthLists(BinaryTreeNode* bt)
{
    std::vector<LinkNode*> ret;
    std::list<std::pair<BinaryTreeNode*, int> > queue;

    queue.push_back(std::pair<BinaryTreeNode*, int>(bt, 0));

    int curDepth = -1;
    while (!queue.empty())
    {
        BinaryTreeNode* cur = queue.front().first;
        int depth = queue.front().second;
        queue.pop_front();
        if (depth == curDepth) {
            LinkNode* secondLinkNode = ret[depth];
            ret[depth] = new LinkNode;
            ret[depth]->data = cur->data;
            ret[depth]->next = secondLinkNode;
            
        } else if (depth > curDepth) {
            curDepth = depth;
            LinkNode* newLinkNode = new LinkNode;
            newLinkNode->data = cur->data;
            newLinkNode->next = NULL;
            ret.push_back(newLinkNode);
        }
        if (cur->left)
            queue.push_back(std::pair<BinaryTreeNode*, int>(cur->left, depth+1));

        if (cur->right)
            queue.push_back(std::pair<BinaryTreeNode*, int>(cur->right, depth+1));
    }


    return ret;

}

int main(int argc, char** argv)
{
    int a[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    BinaryTreeNode* bt1 = createBT(a, 0, 9);
    std::vector<LinkNode*> lv = findDepthLists(bt1);
    for (int i = 0; i < lv.size(); i++)
    {
        std::cout << "Depth " << i << ": ";
        LinkNode* p = lv[i];
        while(p)
        {
            std::cout << p->data << ", ";
            p = p->next;
        }

        std::cout << std::endl;
    }

    for (int i = 0; i < lv.size(); i++)
    {
        LinkNode* p = lv[i];
        while(p)
        {
            q = p;
            p = p->next;
            delete q;
            
        }
    }

    destroyBT(bt1);
    return 0;
}
