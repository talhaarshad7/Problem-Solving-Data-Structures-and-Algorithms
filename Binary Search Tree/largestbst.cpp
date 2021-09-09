#include <iostream>
#include <queue>
#include <climits>
#include <algorithm>
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
bool checkBST(BinaryTreeNode<int> *root, int min = INT_MIN, int max = INT_MAX)
{
    if (root == NULL)
        return true;
    if (root->data < min || root->data > max)
        return false;
    bool leftAns = checkBST(root->left, min, root->data - 1);
    bool rightAns = checkBST(root->right, root->data, max);
    return leftAns && rightAns;
}
class pairs
{
public:
    int height;
    bool isBST;
    int min;
    int max;
};
pairs largest(BinaryTreeNode<int> *root)
{
    if (root==NULL)
    {
        pairs p;
        p.height = 0;
        p.isBST = true;
        p.min = INT_MAX;
        p.max = INT_MIN;
        return p;
    }
    pairs left = largest(root->left);
    pairs right = largest(root->right);
    pairs ans;
    ans.isBST=root->data>left.max&&root->data<right.min&&left.isBST&&right.isBST;
    ans.max=max(root->data,max(left.max,right.max));
    ans.min=min(root->data,min(left.min,right.min));
    if(ans.isBST)
    ans.height=1+max(left.height,right.height);
    else
    ans.height=max(left.height,right.height);
    return ans;
}
int main()
{
    BinaryTreeNode<int> *root = takeInputLevelWise();
    pairs p=largest(root);
    cout<<p.height<<endl;
}