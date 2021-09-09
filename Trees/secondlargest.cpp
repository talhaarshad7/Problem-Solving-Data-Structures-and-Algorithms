#include <iostream>
using namespace std;
#include "treenodeclass.h"
#include <queue>
class pairs
{
public:
    TreeNode<int> *f;
    TreeNode<int> *s;
    pairs(TreeNode<int> *node)
    {
        f = node;
        s = NULL;
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
pairs secondLargest(TreeNode<int> *root)
{
    pairs ans(root);
    for (int i = 0; i < root->children.size(); i++)
    {
        pairs so = secondLargest(root->children[i]);
        if (so.s == NULL && ans.s == NULL)
        {
            if (ans.f->data < so.f->data)
            {
                TreeNode<int> *temp = ans.f;
                ans.f = so.f;
                ans.s = temp;
            }
            else
            {
                ans.s = so.f;
            }
        }
        else if (ans.s == NULL && so.s != NULL)
        {
            if (so.f->data > ans.f->data)
            {
                if (ans.f->data > so.s->data)
                {
                    TreeNode<int> *temp = ans.f;
                    ans.f = so.f;
                    ans.s = temp;
                }
                else
                {
                    ans.f=so.f;
                    ans.s=so.s;
                }
            }
            else if (so.f->data < ans.f->data)
            {
                ans.s = so.f;
            }
        }
        else
        {
            if(ans.f->data<so.f->data)
            {
                if(ans.s->data<so.s->data)
                {
                    ans.f=so.f;
                    ans.s=so.s;
                }
                else
                {
                    ans.f=so.f;
                }
            }
            else
            {
                if(ans.s->data<so.f->data)
                ans.s=so.f;
            }
        }
    }
    return ans;
}
int main()
{
    TreeNode<int> *root = takeInputLevelWise();
    pairs p=secondLargest(root);
    cout<<p.s->data<<endl;
}