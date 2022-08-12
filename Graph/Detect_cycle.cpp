// Graph Representation Using Adajcency Matrix
// Time Complexity =  O(n);
#include <bits/stdc++.h>
using namespace std;
vector<int> visited(100000, 0);
vector<int> adjacency_list[100000];
bool detectCycle_dfs(int node, int parent)
{
    visited[node] = 1;
    for (auto it : adjacency_list[node])
    {
        // cout << it << " : " << node << endl;
        if (visited[it] == 0)
        {
            if (detectCycle_dfs(it, node) == true)
                return true;
        }
        else if (visited[it] == 1 && it != parent)
            return true;
    }
    return false;
}
bool detectCycle_bfs(int node)
{
    queue<pair<int, int>> qu;
    qu.push({node, 0});
    visited[node] = 1;
    while (!qu.empty())
    {
        int parent = qu.front().second;
        int node = qu.front().first;
        qu.pop();
        for (auto it : adjacency_list[node])
        {
            if (visited[it] == 0)
            {
                qu.push({it, node});
                visited[it] = 1;
            }
            else if (visited[it] == 1 && it != parent)
                return true;
        }
    }
    return false;
}
void CycleChecker(int n)
{
    string ans = "NOT CYCLE";
    for (int i = 1; i <= n; i++)
    {
        if (visited[i] == 0)
        {
            if (detectCycle_dfs(i, 0) == true)
            {
                ans = "CYCLE";
                break;
            }
        }
    }
    cout << ans;
}
int main()
{
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adjacency_list[b].push_back(a);
        adjacency_list[a].push_back(b);
    }
    CycleChecker(n);
}
// input pattern contains
// n, m [n=number of nodes ,m=number of edges]
// the next m lines contains nodes connected in any order
// 1------2
// | \   /
// |  \ /     5----6
// |   3      \   /
// |  /        \ /
// | /          7
// 4
// 1 - 2 3 4 2 - 3 1 3 - 1 2 4 4 - 3 1

// Input
// 7 8
// 1 2
// 2 3
// 4 3
// 1 3
// 4 1
// 5 6
// 6 7
// 5 7