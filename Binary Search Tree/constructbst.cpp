#include<iostream>
using namespace std;
#include "BinaryTree.h"
BinaryTreeNode<int> *construct(int a[],int s,int e)
{
    if(s>e)
    return NULL;
    int mid=(s+e)/2;
    BinaryTreeNode<int> *root=new BinaryTreeNode<int>(a[mid]);
    BinaryTreeNode<int> *leftTree=construct(a,s,mid-1);
    BinaryTreeNode<int> *rightTree=construct(a,mid+1,e);
    root->left=leftTree;
    root->right=rightTree;
    return root;
}
void preorder(BinaryTreeNode<int> *root)
{
    if(root==NULL)
    return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    cin>>a[i];
    BinaryTreeNode<int> *root=construct(a,0,n-1);
    preorder(root);
}