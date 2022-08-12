#include <bits/stdc++.h>
using namespace std;
// int lomuto_partition(vector<int> &vec, int l, int h)
// {
//     int pivot = vec[h];
//     int j = -1, i;
//     for (i = 0; i < h; i++)
//     {
//         if (vec[i] < pivot)
//         {
//             j++;
//             swap(vec[i], vec[j]);
//         }
//     }
//     swap(vec[h], vec[j + 1]);
//     return (j + 1);
// }
int hoare_partition(vector<int> &vec, int low, int h)
{
    int pivot = vec[low];
    int i = 0, j = h;
    while (true)
    {
        while (vec[i] <=pivot)
        {
          
            i++;
        }
        while (vec[j] > pivot)
        {
            j--;
        }
        cout << i << " " << j << endl;
        for (auto it : vec)
            cout << it << " ";
        cout << endl;
        if (j <= i)
            break;
        swap(vec[j], vec[i]);
    }
    return j;
}
void quick_sort(vector<int> &vec, int low, int high)
{
    if (low < high)
    {
        // int partition = lomuto_partition(vec, low, high );
        // quick_sort(vec, low, partition-1);
        // quick_sort(vec, partition+1, high);
        int partition = hoare_partition(vec, low, high);
        cout << partition << " ";
        quick_sort(vec, low, partition);
        quick_sort(vec, partition + 1, high);
    }
}
int main()
{
    vector<int> vec1 = {15, 67, 12, 125, 78, 46, 98, 25};
    vec1 = {5, 3, 8, 4, 2, 7, 5,1, 10};
    cout << "Before Partioning:: ";

    for (auto &it : vec1)
        cout << it << " ";
    cout << endl;

    quick_sort(vec1, 0, vec1.size() - 1);
    // int p = hoare_partition(vec1, 0, vec1.size() - 1);
    // cout << "After Partioning :: ";
    // for (auto &it : vec1)
    //     cout << it << " ";
    // cout << hoare_partition(vec1, 0, p) << endl;

    cout << "After Partioning :: ";
    for (auto &it : vec1)
        cout << it << " ";
}