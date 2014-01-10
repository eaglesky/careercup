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

BinaryTreeNode* getNode(BinaryTreeNode* root, int data)
{
    if (root) {
        BinaryTreeNode* leftNode = getNode(root->left, data);
        BinaryTreeNode* rightNode;

        if(leftNode)
            return leftNode;
        
        if (root->data == data)
            return root;

        rightNode = getNode(root->right, data);
        return rightNode;
           
    } else 
        return NULL;
}

//Return the potential common ancestor(p, q may be included), and isAncestor
//indicates whether or not it is a common ancestor
BinaryTreeNode* getCommonAncestor(BinaryTreeNode* root, BinaryTreeNode* p, BinaryTreeNode* q, bool& isAncestor)
{
    bool flag_left = true;
    bool flag_right = true;

    BinaryTreeNode* leftAncestor ;
    BinaryTreeNode* rightAncestor;

    if (root) {
        leftAncestor = getCommonAncestor(root->left, p, q, flag_left);
        rightAncestor = getCommonAncestor(root->right, p, q, flag_right);
    } else {
        isAncestor = false; 
        return root;
    }

    if ((root == p)||(root == q)) {
        if (leftAncestor || rightAncestor)
            isAncestor = true;
        else
            isAncestor = false;

        return root;
    }


    if ((leftAncestor)&&(leftAncestor!=p)&&(leftAncestor!=q)) {
        isAncestor = true;
        return leftAncestor;
    }

    if ((rightAncestor)&&(rightAncestor!=p)&&(rightAncestor!=q)) {
        isAncestor = true; 
        return rightAncestor;
    }

    if ((!leftAncestor)&&(!rightAncestor)) {
        isAncestor = false;
        return NULL;
    } else if (leftAncestor && rightAncestor) {
        isAncestor = true;
        return root;
    } else if (leftAncestor) {
            
        isAncestor = flag_left;
        return leftAncestor; 
    } else {
        isAncestor = flag_right;
        return rightAncestor;
    }

    return NULL;
}

int main(int argc, char** argv)
{
    int a[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    BinaryTreeNode* bt1 = createBT(a, 0, 9);

    int b[4] = {1, 3, 5, 8};
    BinaryTreeNode* bt2 = createBT(b, 0, 3);

    std::cout << "BT1: ";
    inOrderTraverse(bt1);

    std::cout << "BT2: ";
    inOrderTraverse(bt2);

    std::cout << std::endl;
    BinaryTreeNode* p = getNode(bt2, 5);
    BinaryTreeNode* q = getNode(bt2, 8);

    std::cout << "p on bt2: " << p->data << std::endl;
    std::cout << "q on bt2: " << q->data << std::endl;

    bool flag;
    BinaryTreeNode* commonAncestor = getCommonAncestor(bt2, p, q, flag);
    if (flag)
        std::cout << "Common Ancestor: " << commonAncestor->data << std::endl;

    p = getNode(bt2, 1);
    q = getNode(bt2, 8);

    std::cout << "p on bt2: " << p->data << std::endl;
    std::cout << "q on bt2: " << q->data << std::endl;

    commonAncestor = getCommonAncestor(bt2, p, q, flag);

    if (flag)
        std::cout << "Common Ancestor: " << commonAncestor->data << std::endl;

    p = getNode(bt1, 1);
    q = getNode(bt1, 9);

    std::cout << "p on bt1: " << p->data << std::endl;
    std::cout << "q on bt1: " << q->data << std::endl;

    commonAncestor = getCommonAncestor(bt1, p, q, flag);

    if (flag)
        std::cout << "Common Ancestor: " << commonAncestor->data << std::endl;


    p = getNode(bt1, 1);
    q = getNode(bt1, -1);

    std::cout << "p on bt1: " << p->data << std::endl;
    std::cout << "q on bt1: " << -1 << std::endl;

    commonAncestor = getCommonAncestor(bt1, p, q, flag);

    if (flag)
        std::cout << "Common Ancestor: " << commonAncestor->data << std::endl;
    else
        std::cout << "Nothing" << std::endl;

    p = getNode(bt1, 4);
    q = getNode(bt1, 2);

    std::cout << "p on bt1: " << p->data << std::endl;
    std::cout << "q on bt1: " << q->data << std::endl;

    commonAncestor = getCommonAncestor(bt1, p, q, flag);

    if (flag)
        std::cout << "Common Ancestor: " << commonAncestor->data << std::endl;
    else
        std::cout << "Nothing" << std::endl;

    p = getNode(bt1, 7);
    q = getNode(bt1, 6);

    std::cout << "p on bt1: " << p->data << std::endl;
    std::cout << "q on bt1: " << q->data << std::endl;

    commonAncestor = getCommonAncestor(bt1, p, q, flag);

    if (flag)
        std::cout << "Common Ancestor: " << commonAncestor->data << std::endl;
    else
        std::cout << "Nothing" << std::endl;


    destroyBT(bt1);
    destroyBT(bt2);
    return 0;
}
