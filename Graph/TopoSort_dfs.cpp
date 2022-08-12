// Topological Sort is only For Directed Acyclic Graph(DAG)
#include <bits/stdc++.h>
using namespace std;
vector<int> visited(100000, 0);
vector<int> adjacency_list[100000];
void topoSort(int n, stack<int> &st)
{
    visited[n] = 1;
    // cout << n << " ";
    for (auto it : adjacency_list[n])
    {
        if (!visited[it])
            topoSort(it, st);
    }
    st.push(n);
}
int main()
{
    int n, m;
    cin >> n >> m;
    stack<int> st;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adjacency_list[a].push_back(b);
    }
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
            topoSort(i, st);
    }
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
}
// 6 5
// 1 2
// 2 3
// 5 3
// 4 5
// 4 0