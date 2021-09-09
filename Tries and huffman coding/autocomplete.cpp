#include<iostream>
using namespace std;
#include"Trie.h"

int main()
{
    int n;
    cin>>n;
    Trie t;
    for(int i=0;i<n;i++)
    {
        string st;
        cin>>st;
        t.insertWord(st);
    }
    string s;
    cin>>s;
    TrieNode *l=t.search(s);
    t.printMatch(l,s);
}
