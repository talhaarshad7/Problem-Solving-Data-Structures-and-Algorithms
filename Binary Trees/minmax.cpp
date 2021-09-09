#include <iostream>
#include "BinaryTree.h"
#include <queue>
#include<climits>
using namespace std;
BinaryTreeNode<int> *takeInputLevelWise()
{
    int rootData;
    cin >> rootData;
    if (rootData == -1)
        return NULL;
    queue<BinaryTreeNode<int> *> pendingNodes;
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    pendingNodes.push(root);
    while (pendingNodes.size() != 0)
    {
        BinaryTreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        int leftChildData;
        cin >> leftChildData;
        if (leftChildData != -1)
        {
            BinaryTreeNode<int> *child = new BinaryTreeNode<int>(leftChildData);
            front->left = child;
            pendingNodes.push(child);
        }
        int rightChildData;
        cin >> rightChildData;
        if (rightChildData != -1)
        {
            BinaryTreeNode<int> *child = new BinaryTreeNode<int>(rightChildData);
            front->right = child;
            pendingNodes.push(child);
        }
    }
    return root;
}
void printTreeLevelWise(BinaryTreeNode<int> *root)
{
    queue<BinaryTreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    while (pendingNodes.size() != 0)
    {
        BinaryTreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        cout << front->data << ":L:";
        if (front->left == NULL)
            cout << "-1";
        else
        {
            cout << front->left->data;
            pendingNodes.push(front->left);
        }
        cout<<",R:";
        if (front->right == NULL)
            cout << "-1";
        else
        {
            cout << front->right->data;
            pendingNodes.push(front->right);
        }
        cout<<endl;
    }
}
pair<int,int> minmax(BinaryTreeNode<int> *root)
{
    if(root==NULL)
    {
        pair<int,int> p;
        p.first=INT_MAX;
        p.second=INT_MIN;
        return p;
    }
    pair<int,int> leftAns=minmax(root->left);
    pair<int,int> rightAns=minmax(root->right);
    pair<int,int> ans;
    ans.first=min(root->data,min(leftAns.first,rightAns.first));
    ans.second=max(root->data,max(leftAns.second,rightAns.second));
    return ans;
}
int main()
{
    BinaryTreeNode<int> *root=takeInputLevelWise();
    pair<int,int> p=minmax(root);
    cout<<p.first<<" "<<p.second<<endl;
}
