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
void printAtDepthK(TreeNode<int> *root,int d)
{
    if(root==NULL)
    return;
    if(d==0)
    {
        cout<<root->data;
        return;
    }
    for(int i=0;i<root->children.size();i++)
    printAtDepthK(root->children[i],d-1);
}
int main()
{
    TreeNode<int> *root = takeInputLevelWise();
    int n;
    cin>>n;
    cout << depth(root,n) << endl;
}