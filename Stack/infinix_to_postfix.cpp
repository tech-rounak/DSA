#include <bits/stdc++.h>
using namespace std;
int precedence(char c)
{
    if (c == '^')
        return 3;
    if (c == '*' || c == '/')
        return 2;
    if (c == '+' || c == '-')
        return 1;
    if (c == '(')
        return 0;
    else
        return -1;
}
void infinix_to_postfix(string s)
{

    stack<char> st;
    string ans = "";
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == ')')
        {
            while (1)
            {
                if (st.top() == '(')
                {
                    st.pop();
                    break;
                }
                ans += st.top();
                st.pop();
            }
        }
        else if (precedence(s[i]) == -1)
        {
            ans += s[i];
        }
        else if (st.empty() || s[i] == '(')
        {
            st.push(s[i]);
        }
        else
        {
            while (!st.empty() && precedence(s[i]) <= precedence(st.top()))
            {
                ans += st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }
    while (!st.empty())
    {
        ans += st.top();
        st.pop();
    }
    cout << ans << endl;
}
int main()
{
    infinix_to_postfix("a+b*(c^d-e)^(f+g*h)-i");
    infinix_to_postfix("a/c*e");
    infinix_to_postfix("a+b/c-d*e");
    infinix_to_postfix("a+b+c+d");
    infinix_to_postfix("(a/b)*(c-d)+(e*(f-g))");
}
