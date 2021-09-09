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
int count(TreeNode<int> *root,int x)
{
    if(root==NULL)
    return -1;
    int ans=0;
    for(int i=0;i<root->children.size();i++)
    {
        int so=count(root->children[i],x);
        ans+=so;
    }
    if(root->data>x)
        ans++;
    
    return ans;

    
}
int main()
{
    TreeNode<int> *root = takeInputLevelWise();
    int x;
    cin>>x;
    cout<<count(root,x)<<endl;
}