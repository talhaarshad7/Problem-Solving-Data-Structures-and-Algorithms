#include"TrieNodeClass.h"
#include<iostream>
using namespace std;
class Trie
{
    TrieNode *root;
    public:
    Trie()
    {
        root=new TrieNode('\0');
    }
    void insertWord(TrieNode *root,string word)
    {
        //Base Case
        if(word.length()==0)
        {
            root->isTerminal=true;
            return;
        }
        //Small calculation
        int index=word[0]-'a';
        TrieNode *child;
        if(root->children[index]!=NULL)
        child=root->children[index];
        else
        {
            child=new TrieNode(word[0]);
            root->children[index]=child;
        }
        //recursive call
        insertWord(child,word.substr(1));
    }
    void insertWord(string wo)
    {
        insertWord(root,wo);
    }
    bool searchWord(TrieNode *root,string word)
    {
        if(word.length()==0)
        return root->isTerminal;
        int index=word[0]-'a';
        if(root->children[index]!=NULL)
        return searchWord(root->children[index],word.substr(1));
        else
        return false;
    }
    bool searchWord(string wo)
    {
        return searchWord(root,wo);
    }
    void removeWord(TrieNode *root,string word)
    {
        //base case
        if(word.length()==0)
        {
            root->isTerminal=false;
            return;
        }
        //small calculation
        TrieNode *child;
        int index=word[0]-'a';
        if(root->children[index]!=NULL)
        {
            child=root->children[index];
        }
        else//word not found
        return;
        //recursive call
        removeWord(root->children[index],word.substr(1));
        //remove child if it is useless
        if(child->isTerminal==false)
        {
            for(int i=0;i<26;i++)
            {
                if(child->children[i]==NULL)
                return;
            }
        }
        delete child;
        root->children[index]=NULL;
    }
    bool matchPattern(string s)
    {
        TrieNode *temp=root;
        while(!s.empty())
        {
            int index=s[0]-'a';
            if(temp->children[index]==NULL)
            return false;
            s=s.substr(1);
            temp=temp->children[index];
        }
        return true;
    }
    void removeWord(string wo)
    {
        removeWord(root,wo);
    }
    TrieNode* search(TrieNode* root,string w)
    {
        if(w.length()==0)
        return root;
        int index=w[0]-'a';
        TrieNode *child;
        if(root->children[index]!=NULL)
        {
            child=root->children[index];
            return search(child,w.substr(1));
        }
        else
        return NULL;
    }
    TrieNode* search(string w)
    {
        return search(root,w);
    }
    void printMatch(TrieNode *l,string w)
    {
        if(l==NULL)
        return;
        if(l->isTerminal)
        cout<<w<<endl;
        for(int i=0;i<26;i++)
        {
            if(l->children[i]!=NULL)
            printMatch(l->children[i],w+l->children[i]->data);
        }

    }
};