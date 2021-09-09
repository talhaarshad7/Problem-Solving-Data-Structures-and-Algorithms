#include <iostream>
using namespace std;
#include "BinaryTree.h"
#include <queue>
BinaryTreeNode<int> *takeInputLevelWise()
{
    int rootData;
    cin >> rootData;
    if (rootData == -1)
        return NULL;
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    while (pendingNodes.size() != 0)
    {
        BinaryTreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        int leftData;
        cin >> leftData;
        if (leftData != -1)
        {
            BinaryTreeNode<int> *leftChild = new BinaryTreeNode<int>(leftData);
            front->left = leftChild;
            pendingNodes.push(leftChild);
        }
        int rightData;
        cin >> rightData;
        if (rightData != -1)
        {
            BinaryTreeNode<int> *rightChild = new BinaryTreeNode<int>(rightData);
            front->right = rightChild;
            pendingNodes.push(rightChild);
        }
    }
    return root;
}
void printRange(BinaryTreeNode<int> *root,int x,int y)
{
    if(root==NULL)
    return;
    if(root->data > x)
    printRange(root->left,x,y);
    if(root->data>=x &&root->data<=y)
    cout<<root->data<<" ";
    if(root->data < y)
    printRange(root->right,x,y);
}
int main()
{
    BinaryTreeNode<int> *root = takeInputLevelWise();
    int x;
    cin >> x;
    int y;
    cin>>y;
    printRange(root,x,y);
}