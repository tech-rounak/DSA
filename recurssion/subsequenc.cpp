#include <bits/stdc++.h>
using namespace std;

void subsequence(int ind, vector<int> &vec, vector<int> &ds, int n)
{
    if (ind == n)
    {
        for (auto &it : ds)
            cout << it << " ";
        cout << endl;
        return;
    }
    ds.push_back(vec[ind]);
    subsequence(ind + 1, vec, ds, n);
    ds.pop_back();
    subsequence(ind + 1, vec, ds, n);
}
int main()
{
    vector<int> vec = {1, 5, 3};
    vector<int> ds;
    subsequence(0, vec, ds, 3);
}