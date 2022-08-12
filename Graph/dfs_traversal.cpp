// Graph Representation Using Adajcency Matrix
// Time Complexity =  O(n);
#include <bits/stdc++.h>
using namespace std;
vector<int> visited(100000, 0);
vector<int> adjacency_list[100000];
void dfs(int n)
{
    if (visited[n] == 1)
        return;
    visited[n] = 1;
    cout << n << " ";
    for (auto it : adjacency_list[n])
    {
        dfs(it);
    }
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
    for (int i = 1; i < n + 1; i++){
        if(!visited[i])
            dfs(i);
    }
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

// Input
// 7 8 //n,m
// 1 2
// 2 3
// 4 3
// 1 3
// 4 1
// 5 6
// 6 7
// 5 7