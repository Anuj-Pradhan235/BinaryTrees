#include <iostream>
#include <vector>
#include <queue>
#include<algorithm>
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
vector<int> reverseLevelOrder(Node *root)
{
    // code here
    vector<int> res;
    if (root == NULL)
        return res;
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *frontNode = q.front();
        q.pop();
        res.push_back(frontNode->data);
        if (frontNode->right)
            q.push(frontNode->right);
        if (frontNode->left)
            q.push(frontNode->left);
    }
    reverse(res.begin(), res.end());
    return res;
}