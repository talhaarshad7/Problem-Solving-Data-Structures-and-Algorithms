#include<iostream>
using namespace std;
#include<queue>
#include"treenodeclass.h"
TreeNode<int>* takeInputLevelWise()
{
    int rootData;
    cin>>rootData;
    TreeNode<int> *root=new TreeNode<int>(rootData);
    queue<TreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while(pendingNodes.size()!=0)
    {
        TreeNode<int> *front=pendingNodes.front();
        pendingNodes.pop();
        int numChild;
        cin>>numChild;
        for(int i=0;i<numChild;i++)
        {
            int childData;
            cin>>childData;
            TreeNode<int> *child=new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }
    return root;
}
int sum(TreeNode<int> *root)
{
    int s=root->data;
    for(int i=0;i<root->children.size();i++)
    s+=sum(root->children[i]);
    return s;

}
int main()
{
    TreeNode<int> *root=takeInputLevelWise();
    cout<<sum(root)<<endl;
}