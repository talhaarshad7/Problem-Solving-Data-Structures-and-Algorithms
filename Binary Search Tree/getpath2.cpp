#include <iostream>
using namespace std;
#include "BinaryTree.h"
#include <queue>
#include<vector>
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
vector<int>* findPath(BinaryTreeNode<int> *root , int k){
    if(root==NULL)
    {
       return NULL;
    }
    
    if(root->data == k )
    {
        vector<int> *v = new vector <int> ();
        v->push_back(k);
        return v;
    }
    
    vector<int> *left=findPath(root->left,k);
     if(left)
    {
        left->push_back(root->data);
        return left;
    }
    else
    {
        vector<int> *right=findPath(root->right,k);

        if(right)
        {
            right->push_back(root->data);
            return right;
        }
    }
     
        return NULL;    
}

int main()
{
    BinaryTreeNode<int> *root = takeInputLevelWise();
    int k;
    cin>>k;
    vector<int> *p=findPath(root,k);
    for(int i=0;i<p->size();i++)
    cout<<p->at(i)<<" ";
}