#include <bits/stdc++.h>
using namespace std;
void lomuto_partion(vector<int> &vec, int h)
{
    int pivot = vec[h];
    int j = -1, i;
    for (i = 0; i < h; i++)
    {
        if (vec[i] < pivot)
        {
            j++;
            swap(vec[i], vec[j]);
        }
    }
    swap(vec[h], vec[j + 1]);
}
int main()
{
    vector<int> vec1;
    vec1 = {45, 67, 12, 25, 25, 34, 78, 46, 98, 25};
    cout << "Before Partioning:: ";

    for (auto &it : vec1)
        cout << it << " ";
    cout << endl;

    // Merge_sort(vec1, 0, vec1.size() - 1);
    lomuto_partion(vec1, vec1.size() - 1);

    cout << "After Partioning :: ";
    for (auto &it : vec1)
        cout << it << " ";
}