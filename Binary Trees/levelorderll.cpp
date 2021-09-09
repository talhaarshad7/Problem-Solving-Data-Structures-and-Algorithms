#include <iostream>
#include "BinaryTree.h"
#include <queue>
#include <vector>
using namespace std;
class Node
{
    public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};
BinaryTreeNode<int> *takeInputLevelWise()
{
    int rootData;
    cin >> rootData;
    if (rootData == -1)
        return NULL;
    queue<BinaryTreeNode<int> *> pendingNodes;
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    pendingNodes.push(root);
    while (pendingNodes.size() != 0)
    {
        BinaryTreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        int leftChildData;
        cin >> leftChildData;
        if (leftChildData != -1)
        {
            BinaryTreeNode<int> *child = new BinaryTreeNode<int>(leftChildData);
            front->left = child;
            pendingNodes.push(child);
        }
        int rightChildData;
        cin >> rightChildData;
        if (rightChildData != -1)
        {
            BinaryTreeNode<int> *child = new BinaryTreeNode<int>(rightChildData);
            front->right = child;
            pendingNodes.push(child);
        }
    }
    return root;
}
vector<Node *> levelOrderLL(BinaryTreeNode<int> *root)
{
    vector<Node *> levelLL;
    queue<BinaryTreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    pendingNodes.push(NULL);
    Node *head = NULL, *tail = NULL;
    while (pendingNodes.size() != 0)
    {
        BinaryTreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        if (front != NULL)
        {
            Node *newNode = new Node(front->data);
            if (head == NULL)
            {
                head = newNode;
                tail = newNode;
            }
            else
            {
                tail->next = newNode;
                tail = newNode;
            }
            if (front->left)
                pendingNodes.push(front->left);
            if (front->right)
                pendingNodes.push(front->right);
        }
        else
        {
            levelLL.push_back(head);
            head = NULL;
            tail = NULL;
            if (pendingNodes.size() != 0)
                pendingNodes.push(NULL);
            else
                return levelLL;
        }
    }
}
int main()
{
    BinaryTreeNode<int> *root = takeInputLevelWise();
    vector<Node *> ll = levelOrderLL(root);
    while(ll.size()!=0)
    {
        Node *head = ll.front();
        while (head != NULL)
        {
            cout << head->data << " ";
            head=head->next;
        }
        cout << endl;
        ll.erase(ll.begin());
    }
}
