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
pair<bool, int> solve(Node *root)
{
    if (root == NULL)
        return {1, 0};
    if (root->left == NULL && root->right == NULL)
        return {1, root->data};
    pair<bool, int> leftAns = solve(root->left);
    pair<bool, int> rightAns = solve(root->right);
    bool left = leftAns.first;
    bool right = rightAns.first;
    bool val = leftAns.second + rightAns.second == root->data;
    pair<bool, int> ans;
    ans.first = left && right && val;
    ans.second = leftAns.second + rightAns.second + root->data;
    return ans;
}