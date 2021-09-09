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
bool identical(TreeNode<int> *r1, TreeNode<int> *r2)
{
    if (r1->children.size() == r2->children.size())
    {
        for (int i = 0; i < r1->children.size(); i++)
        {
            bool res = identical(r1->children[i], r2->children[i]);
            if ((res== true)&& (r1->data == r2->data))
                return true;
            else
                return false;
        }
        if (r1->data == r2->data)
            return true;
    }
    return false;
}
int main()
{
    TreeNode<int> *root1 = takeInputLevelWise();
    TreeNode<int> *root2 = takeInputLevelWise();
    bool id=identical(root1, root2);
    cout << boolalpha << id << endl;
}