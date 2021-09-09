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
void pathSumK(BinaryTreeNode<int> *root,int k,string s)
{
    if(!root->left&&!root->right)
    {
        if(k==root->data)
        {
        cout<<s<<root->data<<endl;
        return;
        }
        else
        return;
    }
    string c=to_string(root->data);
    c+=" ";
    s+=c;
    pathSumK(root->left,k-root->data,s);
    pathSumK(root->right,k-root->data,s);
}
int main()
{
    BinaryTreeNode<int> *root = takeInputLevelWise();
    int k;
    cin>>k;
    string s="";
    pathSumK(root,k,s);
}
