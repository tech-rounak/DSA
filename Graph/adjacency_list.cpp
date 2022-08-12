// Graph Representation Using Adajcency Matrix
//Space Complexity = O(n+2m) for undirected
//                    O(n+m) for directed
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> adjacency_list[n + 1];
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adjacency_list[b].push_back(a);
        adjacency_list[a].push_back(b);
    }
    for (int i = 1; i < n + 1; i++)
    {
        cout << i << "-";
        for (auto &it1 : adjacency_list[i])
            cout << it1 << " ";
        cout << endl;
    }
}
// input pattern contains
// n, m [n=number of nodes ,m=number of edges]
// the next m lines contains nodes connected in any order
// 1------2
// | \   /
// |  \ /
// |   3
// |  /
// | /
// 4
// Input
// 4 5 //n,m
// 1 2
// 2 3
// 4 3
// 4 1
// 1 3