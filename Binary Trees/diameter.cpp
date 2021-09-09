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
int height(BinaryTreeNode<int> *root)
{
    if(root==NULL)
    return 0;
    return 1+max(height(root->left),height(root->right));
}
int diameter1(BinaryTreeNode<int> *root)//O(n*height) Complexity
{
    if(root==NULL)
    return 0;
    int option1=height(root->left)+height(root->right);
    int option2=diameter(root->left);
    int option3=diameter(root->right);
    return max(option1,max(option2,option3));
}
pair<int,int> diameter2(BinaryTreeNode<int> *root)//O(n) Complexity
{
    if(root==NULL)
    {
        pair<int,int> p;
        p.first=0;
        p.second=0;
        return p;
    }
    pair<int,int> leftAns=diameter2(root->left);
    pair<int,int> rightAns=diameter2(root->right);
    int hl=leftAns.first;
    int dl=leftAns.second;
    int hr=rightAns.first;
    int dr=rightAns.second;
    int height=1+max(hl,hr);
    int diameter=max(hl+hr,max(dl,dr));
    pair<int,int> ans;
    ans.first=height;
    ans.second=diameter;
}
int main()
{
    
}
