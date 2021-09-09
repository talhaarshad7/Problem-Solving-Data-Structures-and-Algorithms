#include<iostream>
#include<queue>
#include<algorithm>
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
BinaryTreeNode<int> *lca(BinaryTreeNode<int> *root,int n1,int n2)
{
    if(root==NULL)
    return NULL;
    if(root->data==n1||root->data==n2)
    return root;
    BinaryTreeNode<int> *left=lca(root->left,n1,n2);
    BinaryTreeNode<int> *right=lca(root->right,n1,n2);
    if(left==NULL&&right==NULL)
    return NULL;
    else if(left!=NULL&&right!=NULL)
    return root;
    else if(left!=NULL)
    return left;
    else
    return right;
}
int main()
{
    BinaryTreeNode<int> *root=takeInputLevelWise();
    int n1,n2;
    cin>>n1>>n2;
    BinaryTreeNode<int> *l=lca(root,n1,n2);
    if(l==NULL)
    cout<<-1<<endl;
    else
    cout<<l->data<<endl;
}