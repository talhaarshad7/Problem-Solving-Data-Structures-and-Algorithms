#include <iostream>
using namespace std;
#include "BinaryTree.h"
#include <queue>
class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};
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
pair<Node *, Node *> bstll(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        pair<Node *, Node *> ans;
        ans.first = NULL;
        ans.second = NULL;
        return ans;
    }
    Node *newNode = new Node(root->data);
    pair<Node *, Node *> leftAns = bstll(root->left);
    pair<Node *, Node *> rightAns = bstll(root->right);
    pair<Node *, Node *> ans;
    if (leftAns.first == NULL && rightAns.first == NULL)
    {
        ans.first = newNode;
        ans.second = newNode;
    }
    else if (rightAns.first == NULL && leftAns.first != NULL)
    {
        ans.first = leftAns.first;
        leftAns.second->next = newNode;
        ans.second = newNode;
    }
    else if (rightAns.first != NULL && leftAns.first == NULL)
    {
        ans.first = newNode;
        newNode->next = rightAns.first;
        ans.second = rightAns.second;
    }
    else
    {
        ans.first = leftAns.first;
        leftAns.second->next = newNode;
        newNode->next = rightAns.first;
        ans.second = rightAns.second;
    }
    return ans;
}
void printLL(Node *head)
{
    while (head)
    {
        cout << head->data << " ";
        head = head->next;
    }
}
int main()
{
    BinaryTreeNode<int> *root = takeInputLevelWise();
    pair<Node*,Node*> p=bstll(root);
    printLL(p.first);
}