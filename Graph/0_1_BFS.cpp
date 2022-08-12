// only possible if weight are 0 and 1
// Graph Representation Using Adajcency Matrix
#include <bits/stdc++.h>
using namespace std;
vector<int> dis(100000, INT_MAX);
vector<pair<int, int>> adjacency_list[100000];
void BFS(int source)
{
    deque<pair<int, int>> qu;
    qu.push_back({source, 0});
    dis[source] = 0;
    while (!qu.empty())
    {
        cout << 1;
        int node = qu.front().first;
        int weight = qu.front().second;
        qu.pop_front();
        for (auto it : adjacency_list[node])
        {
            int adj = it.first;
            int w = it.second;
            if (dis[adj] > w + weight)
            {
                dis[adj] = w + weight;

                if (w == 0)
                {
                    qu.push_front({adj, dis[adj]});
                }
                else
                    qu.push_back({adj, dis[adj]});
            }
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int a, b, w;
        cin >> a >> b >> w;
        adjacency_list[b].push_back({a, w});
        adjacency_list[a].push_back({b, w});
    }
    BFS(1);
    for (int i = 1; i <= n; i++)
        cout << dis[i] << " ";
}

// input pattern contains
// n, m [n=number of nodes ,m=number of edges]
// the next m lines contains nodes connected in any order

// 6 8
// 1 2 0
// 1 3 1
// 2 4 1
// 2 3 1
// 3 5 1
// 4 5 1
// 4 6 0
// 6 5 1