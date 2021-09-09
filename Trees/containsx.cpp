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
bool contain(TreeNode<int> *root,int x)
{
    if(root==NULL)
    return false;
    if(root->data==x)
    return true;
    bool ans=false;
    for(int i=0;i<root->children.size();i++)
    {
        bool so=contain(root->children[i],x);
        ans|=so;
    }
    return ans;
}
bool containXLevelWise(TreeNode<int> *root,int x)
{
    queue<TreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while(pendingNodes.size()!=0)
    {
        TreeNode<int> *front=pendingNodes.front();
        pendingNodes.pop();
        if(front->data==x)
        return true;
        for(int i=0;i<front->children.size();i++)
        pendingNodes.push(front->children[i]);
    }
    return false;
}
int main()
{
    TreeNode<int> *root = takeInputLevelWise();
    int x;
    cin>>x;
    cout<<boolalpha<<containXLevelWise(root,x)<<endl;
}