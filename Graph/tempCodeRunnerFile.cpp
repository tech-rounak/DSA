// only possible if weight are 0 and 1
// Graph Representation Using Adajcency Matrix
#include <bits/stdc++.h>
using namespace std;
vector<long long int> dis(100001, INT_MAX), par(100001, -1), visited(100001, 0);
vector<pair<long long int, long long int>> adjacency_list[100000];
void BFS(long long int source)
{
    priority_queue<pair<long long int, long long int>, vector<pair<long long int, long long int>>, greater<pair<long long int, long long int>>> qu;
    qu.push({0, source});
    dis[source] = 0;
    par[source] = 1;
    while (!qu.empty())
    {
        // cout << 1;
        long long int node = qu.top().second;
        long long int weight = qu.top().first;
        qu.pop();
        for (auto it : adjacency_list[node])
        {
            long long int adj = it.first;
            long long int w = it.second;
            if (dis[adj] > w + weight)
            {
                dis[adj] = w + weight;
                qu.push({dis[adj], adj});
                par[adj] = node;
            }
        }
    }
}

int main()
{
    long long int n, m;
    cin >> n >> m;

    for (long long int i = 0; i < m; i++)
    {
        long long int a, b, w;
        cin >> a >> b >> w;
        adjacency_list[b].push_back({a, w});
        adjacency_list[a].push_back({b, w});
    }
    BFS(1);
    // for (int i = 1; i <= n; i++)
    //     cout << dis[i] << " ";
    // cout << endl;
    // for (int i = 1; i <= n; i++)
    //     cout << par[i] << " ";
    // cout << endl;
    if (par[n] == -1)
    {
        cout << -1;
    }
    else
    {
        vector<long long int> ans;
        long long int k = n;
        ans.push_back(k);
        while (visited[k] != 1)
        {
            k = par[k];
            visited[k] = 0;
            ans.push_back(k);
            if (k == 1 && par[k])
                break;
        }
        reverse(ans.begin(), ans.end());
        if (ans[0] != 1)
            cout << -1;

        else
        {
            for (auto it : ans)
                cout << it << " ";
        }
    }
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