#include <iostream>
#include <queue>
using namespace std;
// defining the structure of the node
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
void buildFromLevelOrder(Node *&root)
{
    int data;
    cout << "Enter the data for the root" << endl;
    cin >> data;
    root = new Node(data);
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *frontNode = q.front();
        q.pop();
        int leftData;
        cout << "Enter the left data for " << frontNode->data << endl;
        cin >> leftData;
        if (leftData != -1)
        {
            root->left = new Node(leftData);
            q.push(frontNode->left);
        }
        int rightData;
        cout << "Enter the right data for " << frontNode->data << endl;
        cin >> rightData;
        if (rightData != -1)
        {
            root->right = new Node(rightData);
            q.push(frontNode->right);
        }
    }
}

void levelOrderTraversal(Node *root)
{
    if (root == NULL)
        return;
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        Node *frontNode = q.front();
        q.pop();
        if (frontNode == NULL)
        {
            if (q.size() > 0)
                q.push(NULL);
            cout << endl;
        }
        else
        {
            cout << frontNode->data << " ";
            if (frontNode->left)
                q.push(frontNode->left);
            if (frontNode->right)
                q.push(frontNode->right);
        }
    }
}
int main()
{
    Node *root = NULL;
    buildFromLevelOrder(root);
    levelOrderTraversal(root);
}