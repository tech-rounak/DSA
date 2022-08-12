#include <bits/stdc++.h>
using namespace std;
vector<int> merge_two_sorted_array(vector<int> &vec1, vector<int> &vec2)
{
    int size1 = vec1.size();
    int size2 = vec2.size();
    int i = 0, j = 0;
    vector<int> ans;
    while (i < size1 && j < size2)
    {
        if (vec1[i] <= vec2[j])
            ans.push_back(vec1[i++]);

        if (vec1[i] > vec2[j])
            ans.push_back(vec2[j++]);
    }

    while (i < size1)
        ans.push_back(vec1[i++]);
    while (j < size2)
        ans.push_back(vec2[j++]);
    return ans;
}
void merge(vector<int> &vec, int left, int right, int mid)
{
    vector<int> l, r;
    for (int i = left; i <= mid; i++)
        l.push_back(vec[i]);
    for (int i = mid + 1; i <= right; i++)
        r.push_back(vec[i]);
    vector<int> ans = merge_two_sorted_array(l, r);
    int j = 0;
    for (int i = left; i <= right; i++)
    {
        vec[i] = ans[j];
        j++;
    }
}

void Merge_sort(vector<int> &vec, int l, int r)
{
    if (r == l)
        return;

    int m = (l + r) / 2;
    Merge_sort(vec, l, m);
    Merge_sort(vec, m + 1, r);
    merge(vec, l, r, m);
}
int main()
{
    vector<int> vec1 = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    cout << "Before Sorting :: ";
    for (auto &it : vec1)
        cout << it << " ";
    cout << endl;

    Merge_sort(vec1, 0, vec1.size() - 1);

    cout << "After Sorting :: ";
    for (auto &it : vec1)
        cout << it << " ";
}