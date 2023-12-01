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
int height(Node*root){
        if(root==NULL)return 0;
        int left=height(root->left);
        int right=height(root->right);
        return max(left,right)+1;
    }
    bool solve1(Node*root){
        if(root==NULL)return 1;
        bool leftAns=solve1(root->left);
        bool rightAns=solve1(root->right);
        bool diff=abs(height(root->left)-height(root->right))<=1;
        return leftAns&&rightAns&&diff;
    }
    pair<int,bool>solve2(Node*root){
        if(root==NULL)return {0,1};
        pair<int,bool>leftAns=solve2(root->left);
        pair<int,bool>rightAns=solve2(root->right);
        bool left=leftAns.second;
        bool right=rightAns.second;
        bool diff=abs(leftAns.first-rightAns.first)<=1;
        pair<int,bool>ans;
        ans.first=max(leftAns.first,rightAns.first)+1;
        ans.second=left&&right&&diff;
        return ans;
    }