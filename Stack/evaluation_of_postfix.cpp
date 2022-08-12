#include <bits/stdc++.h>
using namespace std;

void evaluate_postfix(string s)
{
    stack<int> st;
    int ans = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] >= '0' && s[i] <= '9')
            st.push(s[i] - '0');
        else
        {
            int a = st.top();
            st.pop();
            int b = st.top();
            st.pop();
            if (s[i] == '+')
            {
                st.push(b + a);
            }
            if (s[i] == '-')
            {
                st.push(b - a);
            }
            if (s[i] == '*')
            {
                st.push(b * a);
            }
            if (s[i] == '/')
            {
                st.push(b / a);
            }
            if (s[i] == '^')
            {
                st.push(pow(b, a));
            }
            // cout<<ans<<" ";
        }
    }
    cout << st.top() << endl;
}
int main()
{
    evaluate_postfix("12*12++");
}
