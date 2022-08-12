#include <bits/stdc++.h>
using namespace std;

// memoization
// Time complexity O(N)
// Space Complexity O(N)+O(N)~~ O(N)
int fibo_memo(int n, vector<int> &dp)
{
    if (n <= 1)
    {
        return n;
    }
    if (dp[n] != -1)
        return dp[n];
    dp[n] = fibo_memo(n - 1, dp) + fibo_memo(n - 2, dp);
    return dp[n];
}

// Tabulation
// Time complexity O(N)
// Space Complexity O(N)
void fibo_tabu(int n, vector<int> &dp)
{
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
}
// Time complexity O(N)
// Space Complexity O(1)
void fibo(int n)
{
    int prev1 = 1, prev2 = 0;
    for (int i = 2; i <= n; i++)
    {
        int k = prev1 + prev2;
        prev2 = prev1;
        prev1 = k;
    }
    cout << prev1 << endl;
}
int main()
{
    int n;
    cin >> n;
    vector<int> dp(n + 1, -1);
    // cout << fibo_memo(n, dp) << endl;
    // fibo_tabu(n, dp);
    fibo(n);
    // cout << dp[n];
}
// 0 1 1 2 3 5 8 13 21