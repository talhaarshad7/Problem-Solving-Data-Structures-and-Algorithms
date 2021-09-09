#include <iostream>
using namespace std;
#include "treenodeclass.h"
#include <queue>
#include <climits>
class pairs
{
    public:
    TreeNode<int> *node;
    int sum;
    pairs(TreeNode<int> *n)
    {
        node=n;
        sum=0;
        for(int i=0;i<n->children.size();i++)
        sum+=n->children[i]->data;
        sum+=n->data;
    }
};
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
pairs maxChildSum(TreeNode<int> *root)
{
    pairs result(root);
    for(int i=0;i<root->children.size();i++)
    {
        pairs p=maxChildSum(root->children[i]);
        if(p.sum>result.sum)
        {
            result.node=p.node;
            result.sum=p.sum;
        }
    }
    return result;
}
int main()
{
    TreeNode<int> *root = takeInputLevelWise();
    pairs p=maxChildSum(root);
    cout<<p.node->data<<endl;
}