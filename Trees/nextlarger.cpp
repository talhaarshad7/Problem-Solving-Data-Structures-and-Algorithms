#include <iostream>
using namespace std;
#include "treenodeclass.h"
#include <queue>
TreeNode<int> *takeInputLevelWise()
{
    int rootData;
    cin >> rootData;
    TreeNode<int> *root = new TreeNode<int>(rootData);
    queue<TreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    while (pendingNodes.size() != 0)
    {
        TreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        int numChild;
        cin >> numChild;
        for (int i = 0; i < numChild; i++)
        {
            int childData;
            cin >> childData;
            TreeNode<int> *child = new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }
    return root;
}
TreeNode<int> *nextLargest(TreeNode<int> *root, int n)
{
    TreeNode<int> *ans;
    if (root->data > n)
        ans = new TreeNode<int>(root->data);
    else
        ans = NULL;
    for (int i = 0; i < root->children.size(); i++)
    {
        TreeNode<int> *smallOutput = nextLargest(root->children[i], n);
        if (smallOutput == NULL)
            continue;
        else
        {
            if (ans == NULL)
                ans = smallOutput;
            else if (smallOutput->data < ans->data)
                ans = smallOutput;
        }
    }
    return ans;
}
int main()
{
    int n;
    cin >> n;
    TreeNode<int> *root = takeInputLevelWise();
    TreeNode<int> *l = nextLargest(root, n);
    cout << l->data << endl;
}