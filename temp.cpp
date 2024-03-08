#include<bits/stdc++.h>
using namespace std;
void conquer(int arr[], int si, int mid, int ei)
{
    vector<int> merge(ei - si + 1);
    int idx1 = si;
    int idx2 = ei;
    int x = 0;
    
    while (arr[idx1] <= mid && arr[idx2] <= ei)
    {
        if (arr[idx1] <= arr[idx2])
        {
            marge[x++] = arr[idx1++];
        }
        else
        {
            marge[x++] = arr[idx2];
        }
        while (arr[idx1] <= mid)
        {
            marge[x++] = arr[idx1++];
        }

        while (arr[idx2] <= ei)
        {
            marge[x++] = arr[idx1++];
        }
        for (int i = 0, j = si; i < marge.length(); i++, j++)
        {
            arr[i] = marge[i];
        }
    }

}
void devide(int arr[], int si, int ei)
{
    if (si >= ei) return;
    int mid = si + (si - ei) / 2;
    devide(arr, si, mid);
    devide(arr, mid + 1, ei);
    conquer(arr, si, mid, ei);
}

int main()
{
    int n;
    int arr[n] = {1, 3, 4, 5, 56, 67, 78, };
    devide(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}