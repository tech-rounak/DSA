#include <bits/stdc++.h>
using namespace std;
int precedence(char k)
{
    switch (k)
    {
    case '^':
        return 3;
    case '*':
    case '/':
        return 2;
    case '+':
    case '-':
        return 1;
    case ')':
        return 0;
    default:
        return -1;
    }
}
string infinix_to_prefix(string s)
{
    string ans = "";
    stack<char> st;
    for (int i = s.length() - 1; i >= 0; i--)
    {
        if (s[i] == '(')
        {
            while (!st.empty())
            {
                if (st.top() == ')')
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
        else if (st.empty() || s[i] == ')' || precedence(st.top()) < precedence(s[i]))
        {
            st.push(s[i]);
            // cout << st.top() << " " << s[i] << endl;
        }
        else
        {
            while (st.size() != 0 && precedence(s[i]) <= precedence(st.top()))
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
    reverse(ans.begin(), ans.end());
    return ans;
}
int main()
{
    cout << infinix_to_prefix("x+y*z") << endl;
    cout << infinix_to_prefix("(x+y)*z") << endl;
    cout << infinix_to_prefix("x^y^z") << endl;
    cout << infinix_to_prefix("x+y/z-w*u") << endl;
    cout << infinix_to_prefix("((a+b)*c-(d-e)^(f+g))") << endl;
}
