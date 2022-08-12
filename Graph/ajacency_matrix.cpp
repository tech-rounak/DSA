// Graph Representation Using Adajcency Matrix
// Space Complexity ~ O(N*N);
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    int adjacency_matrix[n + 1][n + 1];
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < n + 1; j++)
            adjacency_matrix[i][j] = 0;
    }
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adjacency_matrix[a][b] = 1;
        adjacency_matrix[b][a] = 1;
    }
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < n + 1; j++)
            cout << adjacency_matrix[i][j] << " ";
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
// 4 5
// 1 2
// 2 3
// 4 3
// 1 3
// 4 1