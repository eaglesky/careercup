#include <iostream>

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

void inOrderTraverse(BinaryTreeNode* bt)
{
    if (bt) {
        inOrderTraverse(bt->left);
        std::cout << bt->data << ", " ;
        inOrderTraverse(bt->right);
    }    
}

int main(int argc, char** argv)
{
    int test1[3] = {4, 8, 12};
    int test2[8] = {1, 3, 5, 7, 9, 11, 13, 17};

    BinaryTreeNode* bt1 = createBT(test1, 0, 2);
    BinaryTreeNode* bt2 = createBT(test2, 0, 7);

    std::cout << "bt1: ";
    inOrderTraverse(bt1);
    std::cout << std::endl;

    std::cout << "bt2: ";
    inOrderTraverse(bt2);
    std::cout << std::endl;
    return 0;
}
