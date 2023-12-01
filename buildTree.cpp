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
Node *buildTree(Node *root)
{
    int data;
    cout<<"Enter: ";
    cin >> data;
    root = new Node(data);
    if (data == -1)
        return NULL;
    cout << "Enter the data to be inserted at the left of " << data << endl;
    root->left = buildTree(root->left);
    cout << "Enter the data to be inserted at the right of " << data << endl;
    root->right = buildTree(root->right);
    return root;
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
    Node*root;
    root=buildTree(root);
    levelOrderTraversal(root);
}