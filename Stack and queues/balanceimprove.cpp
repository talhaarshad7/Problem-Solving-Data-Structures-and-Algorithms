#include <iostream>
using namespace std;
#include <stack>
char invert(char c)
{
    if (c == '}')
        return '{';
    else if (c == ']')
        return '[';
    else
        return '(';
}
int main()
{
    stack<char> s;
    string st;
    cin >> st;
    int l = st.length();
    bool balance = 1;
    for (int i = 0; i < l; i++)
    {
        if (st[i] == '(' || st[i] == '{' || st[i] == '[')
            s.push(st[i]);
        else
        {
            char iv = invert(st[i]);
            if (s.empty())
            {
                balance = 0;
                break;
            }
            else if (iv == s.top())
                s.pop();
            else
            {
                balance = 0;
                break;
            }
        }
    }
    if (s.empty() && balance == 1)
        cout << "true";
    else
        cout << "false";
}
