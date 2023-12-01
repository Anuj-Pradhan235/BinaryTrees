#include <iostream>
#include <algorithm>
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
int height(Node *root)
{
    if (root == NULL)
        return 0;
    int left = height(root->left);
    int right = height(root->right);
    return max(left, right) + 1;
}
int solve1(Node *root)
{
    if (root == NULL)
        return 0;
    int op1 = solve1(root->left);
    int op2 = solve1(root->right);
    int op3 = height(root->left) + height(root->right) + 1;
    return max(op1, max(op2, op3));
}
pair<int, int> solve2(Node *root)
{
    if (root == NULL)
        return {0, 0};
    pair<int, int> leftAns = solve2(root->left);
    pair<int, int> rightAns = solve2(root->right);
    //{height,diameter}
    int op1 = leftAns.second;
    int op2 = rightAns.second;
    int op3 = leftAns.first + rightAns.first + 1;
    pair<int, int> ans;
    ans.first = max(leftAns.first, rightAns.first) + 1;
    ans.second = max(op1, max(op2, op3));
    return ans;
}