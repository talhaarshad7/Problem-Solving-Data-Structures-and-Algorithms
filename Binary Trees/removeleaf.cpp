#include <iostream>
#include "BinaryTree.h"
#include <queue>
#include <climits>
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
void levelOrder(BinaryTreeNode<int> *root)
{
    queue<BinaryTreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    pendingNodes.push(NULL);
    while (pendingNodes.size() != 0)
    {
        BinaryTreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        if (front != NULL)
        {
            cout << front->data << " ";
            if (front->left != NULL)
                pendingNodes.push(front->left);
            if (front->right != NULL)
                pendingNodes.push(front->right);
        }
        else
        {
            cout<<endl;
            if(pendingNodes.size()!=0)
            pendingNodes.push(NULL);
            else
            break;
        }
    }
}
BinaryTreeNode<int> *removeLeaf(BinaryTreeNode<int> *root)
{
    if(root->left==NULL&&root->right==NULL)
    return NULL;
    if(root->left)
    root->left=removeLeaf(root->left);
    if(root->right)
    root->right=removeLeaf(root->right);
    return root;
}
int main()
{
    BinaryTreeNode<int> *root = takeInputLevelWise();
    root=removeLeaf(root);
    levelOrder(root);
}
