#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
#include "BinaryTree.h"
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
int replace(BinaryTreeNode<int> *root,int sum)
{
    if (root == NULL)
        return sum;
    int rightAns = replace(root->right,sum);
    root->data += rightAns;
    int leftAns = replace(root->left,root->data);
    return root->data;
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
        if (front == NULL)
        {
            cout << endl;
            if (pendingNodes.size() == 0)
                break;
            pendingNodes.push(NULL);
        }
        else
        {
            cout << front->data <<" ";
            if (front->left)
                pendingNodes.push(front->left);
            if (front->right)
                pendingNodes.push(front->right);
        }
    }
}

int main()
{
    BinaryTreeNode<int> *root = takeInputLevelWise();
    int x=replace(root,0);
    levelOrder(root);
}