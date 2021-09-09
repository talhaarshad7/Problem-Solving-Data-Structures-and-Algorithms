#include <iostream>
using namespace std;
#include <queue>
#include <climits>
#include "treenodeclass.h"
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
TreeNode<int> *max(TreeNode<int> *root)
{
    TreeNode<int> *m= new TreeNode<int>(root->data);
    for (int i = 0; i < root->children.size(); i++)
    {
        TreeNode<int> *child = max(root->children[i]);
        if (child->data > m->data)
            m = child;
    }
    return m;
}
TreeNode<int> *maxLevelWiese(TreeNode<int> *root)
{
    queue<TreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    TreeNode<int> *max = new TreeNode<int>(INT_MIN);
    while (pendingNodes.size() > 0)
    {
        TreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        if (front->data > max->data)
            max = front;
        for (int i = 0; i < front->children.size(); i++)
            pendingNodes.push(front->children[i]);
    }
    return max;
}
int main()
{
    TreeNode<int> *root = takeInputLevelWise();
    TreeNode<int> *m = max(root);
    TreeNode<int> *mx = maxLevelWiese(root);
    cout << "Normal : " << m->data << endl;
    cout << "Level Wise : " << mx->data << endl;
}