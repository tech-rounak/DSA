#include <bits/stdc++.h>
using namespace std;

void evaluate_prefix(string s)
{
    stack<int> st;
    int ans = 0;
    for (int i = s.length() - 1; i >= 0; i--)
    {
        if (s[i] >= '0' && s[i] <= '9')
            st.push(s[i] - '0');
        else
        {
            int b = st.top();
            st.pop();
            int a = st.top();
            st.pop();
            //op2 operator op1
            //b operator a
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
    evaluate_prefix("+*123");
    evaluate_prefix("^2^23");
}
