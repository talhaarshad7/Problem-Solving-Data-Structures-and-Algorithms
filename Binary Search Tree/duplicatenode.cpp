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
BinaryTreeNode<int> *duplicate(BinaryTreeNode<int> *root)
{
    if(root==NULL)
    return NULL;
    BinaryTreeNode<int> *newNode=new BinaryTreeNode<int>(root->data);
    BinaryTreeNode<int> *leftTree=duplicate(root->left);
    BinaryTreeNode<int> *rightTree=duplicate(root->right);
    newNode->left=leftTree;
    root->left=newNode;
    root->right=rightTree;
    return root;
}
int main()
{
    BinaryTreeNode<int> *root = takeInputLevelWise();
    root=duplicate(root);
    levelOrder(root);
}