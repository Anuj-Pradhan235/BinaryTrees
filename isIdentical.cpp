#include <iostream>
using namespace std;

class Node
{
    int data;
    Node *left;
    Node *right;
    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};
bool isIdentical(Node *r1, Node *r2)
{
    if ((!r1) && (!r2))
        return 1;
    if ((r1) && (!r2))
        return 0;
    if ((!r1) && (r2))
        return 0;
    bool leftAns = isIdentical(r1->left, r2->left);
    bool rightAns = isIdentical(r1->right, r2->right);
    bool val = r1->data == r2->data;
    return leftAns && rightAns && val;
}