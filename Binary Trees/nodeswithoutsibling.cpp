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
void withoutSibling(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return;
    if (root->left == NULL && root->right != NULL)
    {
        cout << root->right->data << " ";
        withoutSibling(root->left);
    }
    else if (root->right == NULL && root->left != NULL)
    {
        cout << root->left->data << " ";
        withoutSibling(root->left);
    }
    else
    {
        withoutSibling(root->left);
        withoutSibling(root->right);
    }
}
int main()
{
    BinaryTreeNode<int> *root = takeInputLevelWise();
    withoutSibling(root);
}
