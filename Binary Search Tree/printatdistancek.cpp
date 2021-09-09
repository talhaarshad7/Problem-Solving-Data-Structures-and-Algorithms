#include <iostream>
#include <queue>
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

void printkdistanceNodeDown(BinaryTreeNode<int>*root, int k) 
{ 
    // Base Case 
    if (root == NULL || k < 0)  return; 
  
    // If we reach a k distant node, print it 
    if (k==0) 
    { 
        cout << root->data << endl; 
        return; 
    } 
  
    // Recur for left and right subtrees 
    printkdistanceNodeDown(root->left, k-1); 
    printkdistanceNodeDown(root->right, k-1); 
} 
// Prints all nodes at distance k from a given target node. 
// The k distant nodes may be upward or downward.  This function 
// Returns distance of root from target node, it returns -1 if target 
// node is not present in tree rooted with root. 

    // Write your code here
int printkdistanceNode(BinaryTreeNode<int>* root, int target , int k) 
{ 
    // Base Case 1: If tree is empty, return -1 
    if (root == NULL) return -1; 
  
    // If target is same as root.  Use the downward function 
    // to print all nodes at distance k in subtree rooted with 
    // target or root 
    if (root->data == target) 
    { 
        printkdistanceNodeDown(root, k); 
        return 0; 
    } 
  
    // Recur for left subtree 
    int dl = printkdistanceNode(root->left, target, k); 
  
    // Check if target node was found in left subtree 
    if (dl != -1) 
    { 
         // If root is at distance k from target, print root 
         // Note that dl is Distance of root's left child from target 
         if (dl + 1 == k) 
            cout << root->data << endl; 
  
         // Else go to right subtree and print all k-dl-2 distant nodes 
         // Note that the right child is 2 edges away from left child 
         else
            printkdistanceNodeDown(root->right, k-dl-2); 
  
         // Add 1 to the distance and return value for parent calls 
         return 1 + dl; 
    } 
  
    // MIRROR OF ABOVE CODE FOR RIGHT SUBTREE 
    // Note that we reach here only when node was not found in left subtree 
    int dr = printkdistanceNode(root->right, target, k); 
    if (dr != -1) 
    { 
         if (dr + 1 == k) 
            cout << root->data << endl; 
         else
            printkdistanceNodeDown(root->left, k-dr-2); 
         return 1 + dr; 
    } 
  
    // If target was neither present in left nor in right subtree 
    return -1; 
} 
int main()
{
    BinaryTreeNode<int> *root = takeInputLevelWise();
    int x, d;
    cin >> x >> d;
    printkdistanceNode(root, x, d);
}