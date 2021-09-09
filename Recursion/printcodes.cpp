#include<iostream>
using namespace std;
void help(string input,string output)
{
    if(input[0]=='\0')
    {
        cout<<output<<endl;
        return;
    }
    
    char c1=(input[0]-'0')+96;
    help(input.substr(1),output +c1);
    
    int d =(input[0]-'0')*10 +(input[1]-'0');
    if( d>=10 && d<=26)
    {   char c2= d+96;
        help(input.substr(2),output +c2);
    }
}
int main()
{
    string s;
    cin>>s;
    string op;
    help(s,op);
}