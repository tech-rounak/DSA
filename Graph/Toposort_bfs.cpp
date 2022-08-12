// Topological Sort is only For Directed Acyclic Graph(DAG)
// BFS USING Kahn's Algorithm
#include <bits/stdc++.h>
using namespace std;
vector<int> visited(100000, 0);
vector<int> adjacency_list[100000];

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> indegree(n + 1, 0);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        indegree[b]++;
        adjacency_list[a].push_back(b);
    }
    queue<int> qu;
    for (int i = 1; i <= n; i++)
    {
        if (indegree[i] == 0)
            qu.push(i);
    }
    while (!qu.empty())
    {
        int k = qu.front();
        qu.pop();
        cout << k << " ";
        for (auto it : adjacency_list[k])
        {
            indegree[it]--;
            if (indegree[it] == 0)
                qu.push(it);
        }
    }
}
// 6 5
// 1 2
// 2 3
// 5 3
// 4 5
// 4 6