#include"Trie.h"
#include<iostream>
using namespace std;
int main()
{
    string st="hello";
    Trie t;
    t.insertWord(st);
    st="helloo";
    cout<<boolalpha<<t.searchWord(st);
 
    
}