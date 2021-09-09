#include <iostream>
using namespace std;
#include "treenodeclass.h"
#include <queue>
class pairs
{
    public:
    TreeNode<int> *root;
    int d;
    pairs(TreeNode<int> *root)
    {
        this.root=root;
        d=0;
    }
}
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
pairs replace(TreeNode<int> *root)
{
    
}
int main()
{
    TreeNode<int> *root=takeInputLevelWise();

}