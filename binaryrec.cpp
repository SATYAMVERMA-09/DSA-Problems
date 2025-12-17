#include <bits/stdc++.h>
using namespace std;

bool binary(int *arr, int s, int e, int key)
{
    int mid = s + (e - s) / 2;
    if (arr[mid] == key)
        return true;
    if (s > e)
        return false;
    if (arr[mid] > key)
        return binary(arr, s, mid - 1, key);
    else
        return binary(arr, mid + 1, e, key);
}

int main()
{
    int arr[5] = {4, 5, 7, 8, 9};
    int key = 10;
    bool ans = binary(arr, 0, 4, key);
    if (ans)
        cout << "Present" << endl;
    else
        cout << "Absent" << endl;
}