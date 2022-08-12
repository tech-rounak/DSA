#include <bits/stdc++.h>
using namespace std;

class segmentTree
{
    vector<int> seg;
    public:
    segmentTree(int n){
        seg.resize(n);
    }
    void build(int ind, int low, int high, vector<int> &vec)
    {
        if (low == high){
            seg[ind] = vec[low];
            return;
        }
        int mid = (mid + high) / 2;
        build(2 * ind + 1, low, mid, vec);
        build(2 * ind + 2, mid + 1, high, vec);
        seg[ind] = min(seg[2 * ind + 1], seg[2 * ind + 2]);
    }
    int query(int ind, int l, int r, int low, int high)
    {
        // no overlap happens
        if (l > high || r < low)
            return INT_MAX;
        // complete overlap
        if (l >= low && r <= high)
            return seg[ind];
        // partial overlap
        int mid = (low + high) / 2;
        int left = query(2 * ind + 1, l, r, low, mid);
        int right = query(2 * ind + 2, l, r, mid + 1, high);
        return min(left, right);
    }
    void update(int ind, int low, int high, int i, int val)
    {
        if (low == high)
        {
            seg[ind] = val;
        }
        int mid = (high + low) / 2;
        if (i <= mid)
        {
            update(2 * ind + 1, low, mid, i, val);
        }
        else
            update(2 * ind + 2, mid + 1, high, i, val);

        seg[ind] = min(seg[ind * 2 + 1], seg[ind * 2 + 2]);
    }
};

int main()
{
    int n;
    cin >> n;
    segmentTree sg1(n);
    vector<int> vec(n);

    for (int i = 0; i < n; i++)
        cin >> vec[i];
    sg1.build(0, 0, n - 1, vec);
    cout << "yes";
    // for(int i = 0 ; i < n ; i++){
    //     cout<<seg[i]<<" ";
    // }
    // int q;cin>>q;
    // while(q--){
    //     int l,r;cin>>l>>r;
    //     cout<<sg1.query(0,l,r,0,n-1);
    // }
}