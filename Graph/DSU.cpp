#include <bits/stdc++.h>
using namespace std;

class DSU
{
public:
    vector<int> size, par, rank;

    DSU(int n)
    {
        for (int i = 0; i <= n; i++)
        {
            par.push_back(i);
            size.push_back(1);
            rank.push_back(0);
        }
    }

public:
    int findpar(int node)
    {
        if (par[node] == node)
            return node;
        return (par[node] = findpar(par[node]));
    }

public:
   void makeUnionBySize(int a, int b) {
    a = findpar(a);
    b = findpar(b);
        if (a != b) {
            if (size[a] < size[b])
                swap(a, b);
            par[b] = a;
            size[a] += size[b];
        }
    }
public:
    void unionByRank(int u, int v)
    {
        int paru = findpar(u);
        int parv = findpar(v);
        if (paru == parv)
            return;
        if (rank[paru] > rank[parv])
        {
            par[parv] = paru;
        }
        else if (rank[paru] < rank[parv])
        {
            par[paru] = parv;
        }
        else
        {
            par[paru] = parv;
            rank[parv]++;
        }
    }
};
int solve()
{
    int n;
    cin >> n;
    DSU dsu(n);
}
int main()
{
    solve();
}