#include<iostream>
using namespace std;
#include"treenodeclass.h"
#include<queue>
void printTree(TreeNode<int> *root)
{
    if(root==NULL)//This is not a base case ,base case is handled implicitly,it is an implicit case that is to be handeled.
    return;
    cout<<root->data<<":";
    for(int i=0;i<root->children.size();i++)
    cout<<root->children[i]->data<<",";
    cout<<endl;
    for(int i=0;i<root->children.size();i++)
    printTree(root->children[i]);
}
TreeNode<int> *takeInput()
{
    int rootData;
    cout<<"Enter data:"<<endl;
    cin>>rootData;
    TreeNode<int> *root=new TreeNode<int>(rootData);
    int n;
    cout<<"Enter Number of child of "<<rootData<<endl;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        TreeNode<int> *child=takeInput();
        root->children.push_back(child);
    }
    return root;
}
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
            cout<<front->children[i]->data<<",";
            pendingNodes.push(front->children[i]);
        }
        cout<<endl;
    }
}
int countNodes(TreeNode<int> *root)
{
    
}
int main()
{
    TreeNode<int> *root=takeInputLevelWise();
    printLevelWise(root);   
}