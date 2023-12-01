#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <stack>
using namespace std;
class Node
{
public:
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
void solve1(Node *root, vector<int> &ans)
{
    if (root == NULL)
        return;
    solve1(root->left, ans);
    ans.push_back(root->data);
    solve1(root->right, ans);
}
vector<int> solve2(Node *root)
{
    vector<int> res;
    if (root == NULL)
        return res;
    stack<Node *> st;
    Node *node = root;
    while (1)
    {
        if (node)
        {
            st.push(node);
            node = node->left;
        }
        else
        {
            if (st.empty())
                break;
            node = st.top();
            st.pop();
            res.push_back(node->data);
            node = node->right;
        }
    }
    return res;
}