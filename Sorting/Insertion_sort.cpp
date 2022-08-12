#include <bits/stdc++.h>
using namespace std;
void Insertion_sort(vector<int> &vec)
{
    int n = vec.size();
    int key;
    for (int i = 1; i < n; i++)
    {
        key = vec[i];
        int j = i - 1;
        while (j >= 0 && vec[j] > key)
        {
            vec[j + 1] = vec[j];
            j--;
        }
        vec[j + 1] = key;
    }
}
int main()
{
    vector<int> vec = {1, 5, 2, 3, 6, 7, 23, 21, 16};
    Insertion_sort(vec);
    for (auto it : vec)
        cout << it << " ";
}