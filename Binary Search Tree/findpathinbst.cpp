#include <iostream>
using namespace std;
#include "BinaryTree.h"
#include <queue>
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
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    while (pendingNodes.size() != 0)
    {
        BinaryTreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        int leftData;
        cin >> leftData;
        if (leftData != -1)
        {
            BinaryTreeNode<int> *leftChild = new BinaryTreeNode<int>(leftData);
            front->left = leftChild;
            pendingNodes.push(leftChild);
        }
        int rightData;
        cin >> rightData;
        if (rightData != -1)
        {
            BinaryTreeNode<int> *rightChild = new BinaryTreeNode<int>(rightData);
            front->right = rightChild;
            pendingNodes.push(rightChild);
        }
    }
    return root;
}
class pairs
{
    public:
    bool ispath;
    Node *head;
    Node *tail;
};
pairs path(BinaryTreeNode<int> *root,int k)
{
    if(root==NULL)
    {
        pairs ans;
        ans.ispath=false;
        ans.head=NULL;
        ans.tail=NULL;
        return ans;
    }
    if(root->data==k)
    {
        Node *newNode=new Node(k);
        pairs ans;
        ans.ispath=true;
        ans.head=newNode;
        ans.tail=newNode;
        return ans;
    }
    pairs leftAns=path(root->left,k);
    pairs rightAns=path(root->right,k);
    pairs ans;
    if(leftAns.ispath||rightAns.ispath)
    {
        ans.ispath=true;
        Node *newNode=new Node(root->data);
        if(leftAns.ispath)
        {
            leftAns.tail->next=newNode;
            ans.head=leftAns.head;
            ans.tail=newNode;
        }
        else
        {
            rightAns.tail->next=newNode;
            ans.head=rightAns.head;
            ans.tail=newNode;

        }
    }
    else
    {
        ans.ispath=false;
        ans.head=NULL;
        ans.tail=NULL;
    }
    return ans;
}
void printLL(Node *head)
{
    while (head)
    {
        cout << head->data << " ";
        head = head->next;
    }
}
int main()
{
    BinaryTreeNode<int> *root = takeInputLevelWise();
    int k;
    cin>>k;
    pairs p=path(root,k);
    if(p.ispath==false)
    cout<<"NO path"<<endl;
    else
    printLL(p.head);
}