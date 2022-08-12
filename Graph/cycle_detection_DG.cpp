// Graph Representation Using Adajcency Matrix
// Time Complexity =  O(n);
#include <bits/stdc++.h>
using namespace std;
vector<int> visited(100000, 0), pathvis(100000, 0);

vector<int> adjacency_list[100000];
bool detectCycle_dfs(int node)
{
    visited[node] = 1;
    pathvis[node] = 1;
    for (auto it : adjacency_list[node])
    {
        // cout << it << " : " << node << endl;
        if (visited[it] == 0)
        {
            if (detectCycle_dfs(it) == true)
                return true;
        }
        else if (visited[it] == 1 && pathvis[it] == 1)
            return true;
    }
    pathvis[node] = 0;
    return false;
}

void CycleChecker(int n)
{
    string ans = "NOT CYCLE";
    for (int i = 1; i <= n; i++)
    {
        if (visited[i] == 0)
        {
            if (detectCycle_dfs(i) == true)
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
        adjacency_list[a].push_back(b); // Directed Graph
    }
    CycleChecker(n);
}
// input pattern contains
// n, m [n=number of nodes ,m=number of edges]
// the next m lines contains nodes connected in any order
// 10 10
// 1 2
// 2 3
// 3 4
// 3 7
// 4 5
// 5 6
// 7 5
// 8 2
// 8 9
// 9 10