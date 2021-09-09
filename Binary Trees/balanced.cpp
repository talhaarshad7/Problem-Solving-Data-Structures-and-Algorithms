#include <iostream>
#include "BinaryTree.h"
#include <queue>
#include<climits>
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
bool isBalanced(BinaryTreeNode<int> *root)
{
    if(root==NULL)
    return true;
    bool isLeftBalanced=isBalanced(root->left);
    bool isRightBalanced=isBalanced(root->right);
    if(isLeftBalanced&&isRightBalanced&&(abs(height(root->left)-height(root->right))<2))
    return true;
    else
    return false;
}
pair<bool,int> isBalanced2(BinaryTreeNode<int> *root)
{
    if(root==NULL)
    {
        pair<bool,int> p;
        p.first=true;
        p.second=0;
        return p;
    }
    pair<bool,int> leftAns=isBalanced2(root->left);
    pair<bool,int> rightAns=isBalanced2(root->right);
    pair<bool,int> ans;
    ans.second=1+max(leftAns.second,rightAns.second);
    if(leftAns.first&&leftAns.first&&(abs(leftAns.second-rightAns.second)<=1))
    ans.first=true;
    else
    ans.first=false;
    return ans;
}
int main()
{
    BinaryTreeNode<int> *root=takeInputLevelWise();
    cout<<boolalpha<<isBalanced2(root).first<<endl;
}
