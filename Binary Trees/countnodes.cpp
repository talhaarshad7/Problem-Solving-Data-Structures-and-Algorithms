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
int countNodes(BinaryTreeNode<int> *root)
{
    if(root==NULL)
    return 0;
    int numLeft=countNodes(root->left);
    int numRight=countNodes(root->right);
    int total=numLeft+numRight+1;
    return total;
}
int countNodes1(BinaryTreeNode<int> *root)
{
    if(root==NULL)
    return 0;
    return countNodes1(root->left)+countNodes1(root->right)+1;
}
int main()
{
    BinaryTreeNode<int> *root = takeInputLevelWise();
    cout<<countNodes1(root)<<endl;
}
