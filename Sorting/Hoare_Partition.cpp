#include <bits/stdc++.h>
using namespace std;
void hoare_partion(vector<int> &vec, int low, int h)
{
    int pivot = vec[low];
    int i = 0, j = h;
    while (true)
    {
        while (vec[i] <= pivot)
        {
            i++;
        }
        while (vec[j] > pivot)
        {
            j--;
        }
        if (j <= i)
            break;
        // cout << i << " " << j << endl;
        // for (auto it : vec)
        //     cout << it << " ";
        // cout << endl;
        swap(vec[j], vec[i]);
    }
}

int main()
{
    vector<int> vec1 = {45, 67, 12, 34, 78, 46, 45, 98, 25};
    cout << "Before Partioning:: ";

    for (auto &it : vec1)
        cout << it << " ";
    cout << endl;

    // Merge_sort(vec1, 0, vec1.size() - 1);
    hoare_partion(vec1, 0, vec1.size() - 1);

    cout << "After Partioning :: ";
    for (auto &it : vec1)
        cout << it << " ";
}