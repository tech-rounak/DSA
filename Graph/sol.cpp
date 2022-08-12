#include <bits/stdc++.h>
#include <string.h>
#include <stdio.h>
#define ll long long
#define mod 1000000007
#define loopforward(i, a, b) for (ll i = a; i < b; i++)
#define loopbackward(i, b, a) for (ll i = b; i > a; i--)
#define ff first
#define ss second
#define pb push_back
#define eb emplace_back
#define all(x) x.begin(), x.end()
#define lb lower_bound
#define ub upper_bound
#define vv vector<ll>
#define vvp vector<pair<ll, ll>>
#define endl "\n"
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
// const ll N=1e7;
// ll prime[N];
using namespace std;
const double pi = 3.14159265358979323846;

void fast_io()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void dijkstra(ll source, vector<pair<ll, ll>> adjacency_list[], vector<ll> &dis)
{
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> qu;
    qu.push({0, source});
    dis[source] = 0;

    while (!qu.empty())
    {
        // cout << 1;
        ll node = qu.top().second;
        ll weight = qu.top().first;
        qu.pop();
        // if(dis[node]<weight) continue;
        for (auto &it : adjacency_list[node])
        {
            ll adj = it.first;
            ll w = it.second;
            // if(dis[adj]<=w+weight) continue;
            if (dis[adj] > w + weight)
            {
                dis[adj] = w + weight;
                qu.push({w + weight, adj});
            }
        }
    }
}

int main()
{

    ll n, m;
    cin >> n >> m;
    vector<ll> dis(n + 1, 1e18), dis1(n + 1, 1e18);
    vector<pair<ll, ll>> adj1[n + 1], adj[n + 1];
    // vector<tuple<ll, ll, ll>> edge;
    for (ll i = 0; i < m; i++)
    {
        ll u, v, w;
        cin >> u >> v >> w;
        // edge.push_back({u, v, w});
        adj[u].push_back({v, w});
        adj1[v].push_back({u, w});
    }

    dijkstra(1, adj, dis);
    dijkstra(n, adj1, dis1);

    // for(ll i=1;i<=n;i++)
    //     cout<<dis[i]<<" ";
    ll ans = 1e18;
    // cout<<ans<<endl;
    // for (auto &it : edge)
    // {
    //     auto [u, v, w] = it;
    //     ans = min(ans, dis[u] + dis1[v] + w / 2);
    // }
    cout << ans << endl;
}