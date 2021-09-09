#include"Trie.h"
#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    Trie t;
    for(int i=0;i<n;i++)
    {
        string st;
        cin>>st;
        while(!st.empty())
        {
            t.insertWord(st);
            st=st.substr(1);
        }
    }
    string p;
    cin>>p;
    cout<<boolalpha<<t.matchPattern(p);
}