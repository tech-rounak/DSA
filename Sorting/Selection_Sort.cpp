#include <bits/stdc++.h>
using namespace std;
void Selection_sort(vector<int> &vec)
{
    int n = vec.size();
    int mini = 1e7;
    for (int i = 0; i < n; i++)
    {
        mini = min_element(vec.begin() + i, vec.end()) - vec.begin();
        swap(vec[i], vec[mini]);
    }
}
int main()
{
    vector<int> vec = {1, 5, 2, 3, 6, 7, 23, 21, 16};
    Selection_sort(vec);
    for (auto it : vec)
        cout << it << " ";
}