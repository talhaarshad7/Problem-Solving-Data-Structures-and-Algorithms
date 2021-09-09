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
int k=0;
void convert(int *arr,BinaryTreeNode<int> *root)
{
    if(root==NULL)
    return;
    convert(arr,root->left);
    arr[k++]=root->data;
    convert(arr,root->right);
}
void nodesum(BinaryTreeNode<int> *root,int s)
{
    int arr[1000];
    convert(arr,root);
    sort(arr,arr+k);
    int i=0,j=k-1;
    while(i<j)
    {
        int sum=arr[i]+arr[j];
        if(sum==s)
        {
            cout<<arr[i]<<" "<<arr[j]<<endl;
            i++;
            j--;
        }
        else if(sum<s)
        {
            i++;
        }
        else
        {
            j--;
        }
    }
}
int main()
{
    BinaryTreeNode<int> *root=takeInputLevelWise();
    int s;
    cin>>s;
    nodesum(root,s);
}