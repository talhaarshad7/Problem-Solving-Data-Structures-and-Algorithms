#include<iostream>
using namespace std;
#include<queue>
#include"treenodeclass.h"
TreeNode<int>* takeInputLevelWise()
{
    int rootData;
    cout<<"Enter data of root node:";
    cin>>rootData;
    TreeNode<int> *root=new TreeNode<int>(rootData);
    queue<TreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while(pendingNodes.size()!=0)
    {
        TreeNode<int> *front=pendingNodes.front();
        pendingNodes.pop();
        int numChild;
        cout<<"Enter number of children nodes of "<<front->data<<endl;
        cin>>numChild;
        for(int i=0;i<numChild;i++)
        {
            int childData;
            cout<<"Enter "<<i<<"th data of "<<front->data<<endl;
            cin>>childData;
            TreeNode<int> *child=new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }
    return root;
}
int countNodes(TreeNode<int> *root)
{
    int ans=1;
    for(int i=0;i<root->children.size();i++)
    ans=ans+countNodes(root->children[i]);
    return ans;
}
int main()
{
    TreeNode<int> *root=takeInputLevelWise();
    cout<<countNodes(root)<<endl;
}