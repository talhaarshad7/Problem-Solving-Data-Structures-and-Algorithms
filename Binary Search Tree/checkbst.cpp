#include <iostream>
using namespace std;
#include "BinaryTree.h"
#include <queue>
#include<climits>
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
int minimum(BinaryTreeNode<int> *root)
{
    if(root==NULL)
    return INT_MAX;
    return min(root->data,min(minimum(root->left),minimum(root->right)));
}
int maximum(BinaryTreeNode<int> *root)
{
    if(root==NULL)
    return INT_MIN;
    return max(root->data,max(maximum(root->left),maximum(root->right)));
}
bool isBST1(BinaryTreeNode<int> *root)//O(n*height)
{
    if(root==NULL)
    return true;
    bool leftAns=isBST1(root->left);
    bool rightAns=isBST1(root->right);
    return (root->data > maximum(root->left))&&(root->data < minimum(root->right))&&isBST1(root->left)&&isBST1(root->right);
}
class isBSTReturn
{
    public:
    int minimum;
    int maximum;
    bool isBST;
};
isBSTReturn isBST2(BinaryTreeNode<int> *root)//O(N)
{
    if(root==NULL)
    {
        isBSTReturn ans;
        ans.minimum=INT_MAX;
        ans.maximum=INT_MIN;
        ans.isBST=true;
        return ans;
    }
    isBSTReturn leftChild=isBST2(root->left);
    isBSTReturn rightChild=isBST2(root->right);
    int minimum=min(root->data,min(leftChild.minimum,rightChild.minimum));
    int maximum=max(root->data,max(leftChild.maximum,rightChild.maximum));
    bool isBSTFinal=(root->data>leftChild.maximum)&&(root->data<=rightChild.minimum)&&leftChild.isBST&&rightChild.isBST;
    isBSTReturn final;
    final.minimum=minimum;
    final.maximum=maximum;
    final.isBST=isBSTFinal;
    return final;
}
bool isBST3(BinaryTreeNode<int> *root,int min=INT_MIN,int max=INT_MAX)//O(n)
{
    if(root==NULL)
    return true;
    if(root->data<min || root->data>max)
    return false;
    int leftAns=isBST3(root->left,min,root->data-1);
    int rightAns=isBST3(root->right,root->data,max);
    return leftAns && rightAns;
}
int main()
{
    BinaryTreeNode<int> *root = takeInputLevelWise();
    bool ans=isBST3(root);
    cout<<boolalpha<<ans;
}