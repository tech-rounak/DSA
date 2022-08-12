// Graph Representation Using Adajcency Matrix
// Time Complexity =  O(n);
#include <bits/stdc++.h>
using namespace std;
vector<int> visited(100000, 0), colour(100000, -1);
vector<int> adjacency_list[100000];
void dfs(int n)
{
    visited[n] = 1;
    for (auto it : adjacency_list[n])
    {
        if (visited[it] == 0)
        {
            colour[it] = !colour[n];
            dfs(it);
        }
    }
}
void Biparte_checker(int n)
{
    for (int i = 1; i < n + 1; i++)
    {
        for (auto it : adjacency_list[i])
        {
            if (colour[it] == colour[i])
            {
                cout << "NOT BIPARTITE" << endl;
                return;
            }
        }
    }
    cout << "BIPARTITE" << endl;
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
    for (int i = 1; i < n + 1; i++)
    {
        if (!visited[i])
        {
            colour[i] = 1;
            dfs(i);
        }
    }
    for (int i = 1; i < n + 1; i++)
        cout << colour[i] << " ";
    Biparte_checker(n);
}

// Input
// 9 9
// 1 2
// 2 3
// 3 4
// 4 8
// 4 5
// 5 6
// 6 7
// 7 9
// 9 3
