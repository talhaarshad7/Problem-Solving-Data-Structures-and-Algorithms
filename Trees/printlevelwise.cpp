#include<iostream>
using namespace std;
#include"treenodeclass.h"
#include<queue>
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
void printLevelWise(TreeNode<int> *root)
{
    queue<TreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while(pendingNodes.size()!=0)
    {
        TreeNode<int> *front=pendingNodes.front();
        pendingNodes.pop();
        cout<<front->data<<":";
        for(int i=0;i<front->children.size();i++)
        {
            if(i==0)
            cout<<front->children[i]->data;
            else    
            cout<<","<<front->children[i]->data;
            pendingNodes.push(front->children[i]);
        }
        cout<<endl;
    }
}
int main()
{
    TreeNode<int> *root=takeInputLevelWise();
    printLevelWise(root);   
}