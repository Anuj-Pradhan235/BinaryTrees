#include <iostream>
#include <bits/stdc++.h>
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
vector<int> zigZagTraversal(Node *root)
{

    vector<int> res;
    if (root == NULL)
        return res;
    queue<Node *> q;
    q.push(root);
    bool leftToRight = 1;
    while (!q.empty())
    {
        int size = q.size();
        vector<int> temp(size);
        for (int i = 0; i < size; i++)
        {
            Node *frontNode = q.front();
            q.pop();
            int index = leftToRight ? i : size - i - 1;
            temp[index] = frontNode->data;
            if (frontNode->left)
                q.push(frontNode->left);
            if (frontNode->right)
                q.push(frontNode->right);
        }
        leftToRight = !leftToRight;
        for (auto i : temp)
            res.push_back(i);
    }
    return res;
}
vector<int> verticalOrder(Node *root)
{
    vector<int> res;
    if (root == NULL)
        return res;
    // hd->lvl->val
    map<int, map<int, vector<int>>> nodes;
    // Node->hr->lvl
    queue<pair<Node *, pair<int, int>>> q;
    q.push({root, {0, 0}});
    while (!q.empty())
    {
        pair<Node *, pair<int, int>> frontNode = q.front();
        q.pop();
        int hd = frontNode.second.first;
        int lvl = frontNode.second.second;
        Node *front = frontNode.first;
        nodes[hd][lvl].push_back(front->data);
        if (front->left)
            q.push({front->left, {hd - 1, lvl + 1}});
        if (front->right)
            q.push({front->right, {hd + 1, lvl + 1}});
    }
    for (auto i : nodes)
    {
        for (auto j : i.second)
        {
            for (auto k : j.second)
                res.push_back(k);
        }
    }

    return res;
}
vector<int> topView(Node *root)
{
    // hr->val
    vector<int> res;
    if (root == NULL)
        return res;
    map<int, int> nodes;
    queue<pair<Node *, int>> q;
    q.push({root, 0});
    while (!q.empty())
    {
        pair<Node *, int> frontNode = q.front();
        Node *front = frontNode.first;
        q.pop();
        int hr = frontNode.second;
        if (nodes.find(hr) == nodes.end())
            nodes[hr] = front->data;
        if (front->left)
            q.push({front->left, hr - 1});
        if (front->right)
            q.push({front->right, hr + 1});
    }
    for (auto i : nodes)
        res.push_back(i.second);
    return res;
}
vector<int> bottomView(Node *root)
{
    // hr->val
    vector<int> res;
    if (root == NULL)
        return res;
    map<int, int> nodes;
    queue<pair<Node *, int>> q;
    q.push({root, 0});
    while (!q.empty())
    {
        pair<Node *, int> frontNode = q.front();
        Node *front = frontNode.first;
        q.pop();
        int hr = frontNode.second;
        nodes[hr] = front->data;
        if (front->left)
            q.push({front->left, hr - 1});
        if (front->right)
            q.push({front->right, hr + 1});
    }
    for (auto i : nodes)
        res.push_back(i.second);
    return res;
}
void leftView(Node *root, vector<int> &ans, int lvl)
{
    if (root == NULL)
        return;
    if (ans.size() == lvl)
        ans.push_back(root->data);
    leftView(root->left, ans, lvl + 1);
    leftView(root->right, ans, lvl + 1);
}
void rightView(Node *root, vector<int> &ans, int lvl)
{
    if (root == NULL)
        return;
    if (ans.size() == lvl)
        ans.push_back(root->data);
    rightView(root->right, ans, lvl + 1);
    rightView(root->left, ans, lvl + 1);
}
vector<int> diagonal(Node *root)
{
    vector<int> res;
    if (root == NULL)
        return res;
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *frontNode = q.front();
        q.pop();
        while (frontNode)
        {
            res.push_back(frontNode->data);
            if (frontNode->left)
                q.push(frontNode->left);
            frontNode = frontNode->right;
        }
    }
    return res;
}

void leftNodes(Node *root, vector<int> &ans)
{
    if ((!root) || (!root->left && !root->right))
        return;
    ans.push_back(root->data);
    if (root->left)
        leftNodes(root->left, ans);
    else
        leftNodes(root->right, ans);
}
void rightNodes(Node *root, vector<int> &ans)
{
    if ((!root) || (!root->left && !root->right))
        return;
    if (root->right)
        rightNodes(root->right, ans);
    else
        rightNodes(root->left, ans);
    ans.push_back(root->data);
}
void leafNodes(Node *root, vector<int> &ans)
{
    if (!root)
        return;
    if (!root->left && !root->right)
    {
        ans.push_back(root->data);
        return;
    }
    leafNodes(root->left, ans);
    leafNodes(root->right, ans);
}

vector<int> boundary(Node *root)
{
    vector<int> ans;
    leftNodes(root->left, ans);
    leafNodes(root->left, ans);
    leafNodes(root->right, ans);
    rightNodes(root->right, ans);
    return ans;
}
