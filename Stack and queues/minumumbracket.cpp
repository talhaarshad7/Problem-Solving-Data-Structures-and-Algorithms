#include <iostream>
using namespace std;
#include <stack>
int main()
{
    stack<char> s;
    string st;
    cin >> st;
    int count = 0;
    if (st.length() % 2 == 0)
    {
        for (int i = 0; i < st.length(); i++)
        {
            if (st[i] == '{')
                s.push('{');
            else
            {
                if (s.size() > 0 && s.top() == '{')
                    s.pop();
                else
                    s.push('}');
            }
        }
        while(!s.empty())
        {
            char c1=s.top();
            s.pop();
            char c2=s.top();
            s.pop();
            if(c1==c2)
            count+=1;
            else
            count+=2;
        }
    }
    else
        count = -1;
    cout<<count<<endl;
}