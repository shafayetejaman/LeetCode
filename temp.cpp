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
            merge[x++] = arr[idx1++];
        }
        else
        {
            merge[x++] = arr[idx2];
        }
        while (arr[idx1] <= mid)
        {
            merge[x++] = arr[idx1++];
        }

        while (arr[idx2] <= ei)
        {
            merge[x++] = arr[idx1++];
        }
        for (int i = 0, j = si; i < merge.size(); i++, j++)
        {
            arr[i] = merge[i];
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
    // int n;
    // int arr[n] = {1, 3, 4, 5, 56, 67, 78, };
    // devide(arr, 0, n - 1);
    cout << "int :" << sizeof(int) << endl;
    cout << "long : " << sizeof(long) << endl;
    cout << "long long : " << sizeof(long long) << endl;
    cout << "float : " << sizeof(float) << endl;
    cout << "double : " << sizeof(double) << endl;
    cout << "long double : " << sizeof(long double) << endl;
    // for (int i = 0; i < n; i++)
    // {
    //     cout << arr[i] << " ";
    // }

    return 0;
}