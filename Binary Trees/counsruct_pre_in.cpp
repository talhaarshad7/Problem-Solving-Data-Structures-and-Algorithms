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
BinaryTreeNode<int> *prein(int in[],int pre[],int ins,int ine,int pres,int pree)
{
    if(ins>ine)
    return NULL;
    int x=-1;
    for(int i=ins;i<=ine;i++)
    {
        if(in[i]==pre[pres])
        {
            x=i;
            break;
        }
    }
    BinaryTreeNode<int> *root=new BinaryTreeNode<int>(pre[pres]);
    root->left=prein(in,pre,ins,x-1,pres+1,x-ins+pres);
    root->right=prein(in,pre,x+1,ine,x-ins+pres+1,pree);
    return root;
}
int main()
{
    int n;
    cin>>n;
    int pre[n],in[n];
    for(int i=0;i<n;i++)
    cin>>pre[i];
    for(int i=0;i<n;i++)
    cin>>in[i];
    BinaryTreeNode<int> *root=prein(in,pre,0,n-1,0,n-1);   
    printTreeLevelWise(root);
}
