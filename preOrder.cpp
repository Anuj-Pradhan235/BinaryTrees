#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
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
    ans.push_back(root->data);
    solve1(root->left, ans);
    solve1(root->right, ans);
}
vector<int> solve2(Node *root)
{
    vector<int> res;
    if (root == NULL)
        return res;
    stack<Node *> st;
    st.push(root);
    while (!st.empty())
    {
        Node *top = st.top();
        st.pop();
        res.push_back(top->data);
        if (top->right)
            st.push(top->right);
        if (top->left)
            st.push(top->left);
    }
    return res;
}