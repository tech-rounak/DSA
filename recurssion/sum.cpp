#include <bits/stdc++.h>
using namespace std;

// In order to print only one subsequence;
// bool subsequence(int ind, vector<int> &vec, vector<int> &ds, int &sum, int given_sum, int n)
// {
//     if (ind == n)
//     {
//         if (sum == given_sum)
//         {
//             for (auto &it : ds)
//                 cout << it << " ";
//             cout << endl;
//             return true;
//         }
//         return false;
//     }
//     ds.push_back(vec[ind]);
//     sum += vec[ind];
//     if (subsequence(ind + 1, vec, ds, sum, given_sum, n))
//         return true;

//     ds.pop_back();
//     sum -= vec[ind];
//     if (subsequence(ind + 1, vec, ds, sum, given_sum, n))
//         return true;
//     return false;
// }
void subsequence(int ind, vector<int> &vec, vector<int> &ds, int &sum, int given_sum, int n)
{
    if (sum == given_sum)
    {
        for (auto &it : ds)
            cout << it << " ";
        cout << endl;
        return;
    }
    ds.push_back(vec[ind]);
    sum += vec[ind];
    subsequence(ind + 1, vec, ds, sum, given_sum, n);
    ds.pop_back();
    sum -= vec[ind];
    subsequence(ind + 1, vec, ds, sum, given_sum, n);
}
int main()
{
    vector<int> vec = {1, 5, 2, 3};
    vector<int> ds;
    int sum = 0;
    subsequence(0, vec, ds, sum, 6, vec.size());
}