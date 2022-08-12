#include <bits/stdc++.h>
using namespace std;
void Bubble_sort(vector<int> &vec)
{
    int n = vec.size();
    bool flag = false;
    for (int i = 0; i < n; i++)
    {
        flag = false;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (vec[j] > vec[j + 1])
            {
                flag = true;
                swap(vec[j], vec[j + 1]);
            }
        }
        if (!flag)
            return;
    }
}
int main()
{
    vector<int> vec = {1, 5, 2, 3, 6, 7, 23, 21, 16};
    Bubble_sort(vec);
    for (auto it : vec)
        cout << it << " ";
}