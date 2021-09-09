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
bool search(BinaryTreeNode<int> *root, int x)
{
    if (root == NULL)
        return false;
    if (root->data == x)
        return true;
    if (x > root->data)
        return search(root->right, x);
    else
        return search(root->left, x);
}
int main()
{
    BinaryTreeNode<int> *root = takeInputLevelWise();
    int x;
    cin >> x;
    cout << boolalpha << search(root, x) << endl;
}