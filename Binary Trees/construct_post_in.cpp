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
void printTreeLevelWise(BinaryTreeNode<int> *root)
{
    queue<BinaryTreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    while (pendingNodes.size() != 0)
    {
        BinaryTreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        cout << front->data << ":L:";
        if (front->left == NULL)
            cout << "-1";
        else
        {
            cout << front->left->data;
            pendingNodes.push(front->left);
        }
        cout<<",R:";
        if (front->right == NULL)
            cout << "-1";
        else
        {
            cout << front->right->data;
            pendingNodes.push(front->right);
        }
        cout<<endl;
    }
}
BinaryTreeNode<int> *postin(int in[],int po[],int ins,int ine,int pos,int poe)
{
    if(ins>ine)
    return NULL;
    int x=-1;
    for(int i=ins;i<=ine;i++)
    {
        if(in[i]==po[poe])
        {
            x=i;
            break;
        }
    }
    BinaryTreeNode<int> *root=new BinaryTreeNode<int>(po[poe]);
    root->left=postin(in,po,ins,x-1,pos,x-ins+pos-1);
    root->right=postin(in,po,x+1,ine,x-ins+pos-1+1,poe-1);
    return root;
}
int main()
{
    int n;
    cin>>n;
    int po[n],in[n];
    for(int i=0;i<n;i++)
    cin>>po[i];
    for(int i=0;i<n;i++)
    cin>>in[i];
    BinaryTreeNode<int> *root=postin(in,po,0,n-1,0,n-1);   
    printTreeLevelWise(root);
}
