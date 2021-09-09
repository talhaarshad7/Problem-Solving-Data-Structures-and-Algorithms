#include <iostream>
#include "BinaryTree.h"
#include <stack>
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
void zigzagOrder(BinaryTreeNode<int> *root)
{
    stack<BinaryTreeNode<int> *> s1;
    stack<BinaryTreeNode<int> *> s2;
    s1.push(root);
    while (s1.size() != 0 || s2.size() != 0)
    {
        BinaryTreeNode<int> *t;
        while (s1.size() != 0)
        {
            t= s1.top();
            s1.pop();
            cout << t->data << " ";
            if (t->left)
                s2.push(t->left);
            if (t->right)
                s2.push(t->right);
        }
        cout<<endl;
        while (s2.size() != 0)
        {
            t = s2.top();
            s2.pop();
            cout << t->data << " ";
            if (t->right)
                s1.push(t->right);
            if (t->left)
                s1.push(t->left);
        }
        cout<<endl;
    }
}
int main()
{
    BinaryTreeNode<int> *root = takeInputLevelWise();
    zigzagOrder(root);
}
