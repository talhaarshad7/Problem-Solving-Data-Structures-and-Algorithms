#include <iostream>
#include "BinaryTree.h"
#include <queue>
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
bool isPresent(BinaryTreeNode<int> *root,int x)
{
    if(root==NULL)
    return 0;
    if(root->data==x)
    return 1;
    bool so1=isPresent(root->left,x);
    if(so1)
    return 1;
    bool so2=isPresent(root->right,x);
    if(so2)
    return 1;
    return 0;
}
int main()
{
    BinaryTreeNode<int> *root = takeInputLevelWise();
    int x;
    cin>>x;
    cout<<boolalpha<<isPresent(root,x)<<endl;
}
