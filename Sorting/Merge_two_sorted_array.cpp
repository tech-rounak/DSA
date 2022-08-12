#include <bits/stdc++.h>
using namespace std;
vector<int> merge(vector<int> &vec1, vector<int> &vec2)
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

int main()
{
    vector<int> vec1 = {1, 2, 3, 4, 5, 6}, vec2 = {5, 8, 67, 541};
    vector<int> ans = merge(vec1, vec2);
    cout << ans.size() << endl;
    for (auto &it : ans)
        cout << it << " ";
}