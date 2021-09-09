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
int height(BinaryTreeNode<int> *root)
{
    if(root==NULL)
    return 0;
    int leftHeight=1+height(root->left);
    int rightHeight=1+height(root->right);
    return max(leftHeight,rightHeight);
}
int main()
{
    BinaryTreeNode<int> *root = takeInputLevelWise();
    cout<<height(root)<<endl;
}
