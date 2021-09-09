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
int countLeaf(TreeNode<int> *root)
{
    int result=0;
    if(root==NULL)
    return -1;
    if(root->children.size()==0)
    return 1;
    for(int i=0;i<root->children.size();i++)
    {
        int so=countLeaf(root->children[i]);
        result=result+so;
    }
    return result;
}
int main()
{
    TreeNode<int> *root = takeInputLevelWise();
    cout << countLeaf(root) << endl;
}