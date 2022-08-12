// Graph Representation Using Adajcency Matrix
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> adjacency_list[n + 1];
    for (int i = 0; i < m; i++)
    {
        int a, b, w;
        cin >> a >> b >> w;
        adjacency_list[b].push_back({a, w});
        adjacency_list[a].push_back({b, w});
    }
    for (int i = 1; i < n + 1; i++)
    {
        cout << i << "-";
        for (auto &it1 : adjacency_list[i])
            cout << "{" << it1.first << " ," << it1.second << " }"
                 << ", ";
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
// 1 2 5
// 2 3 6
// 4 3 2 
// 4 1 3
// 1 3 14