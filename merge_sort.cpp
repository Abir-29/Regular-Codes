#include <bits/stdc++.h>
using namespace std;

void mergey(vector<int> &arr, int st, int mid, int end)
{
    int i = st, j = mid + 1;
    vector<int> temp;
    while (i <= mid && j <= end)
    {
        if (arr[i] < arr[j])
        {
            temp.push_back(arr[i]);
            i++;
        }
        else
        {
            temp.push_back(arr[j]);
            j++;
        }
    }
    while (i <= mid)
    {
        temp.push_back(arr[i]);
        i++;
    }
    while (j <= end)
    {
        temp.push_back(arr[j]);
        j++;
    }
    int l = temp.size();
    for (int k = 0; k < l; k++)
    {
        arr[st+k] = temp[k];
    }
}

void mergeSort(vector<int> &arr, int st, int end)
{
    if (st < end)
    {
        int mid = st + (end - st) / 2;
        mergeSort(arr, st, mid);
        mergeSort(arr, mid + 1, end);
        mergey(arr, st, mid, end);
    }
}

int main()
{
    vector<int> arr = {2, 1, 8, 4, 3, 6};
    mergeSort(arr, 0, 5);
    int l = arr.size();
    for (int t1 = 0; t1 < l; t1++)
        cout << arr[t1] << " ";
    cout << endl;
    return 0;
}