#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

int Binary_Search_using_Recursion(int a[], int n, int k, int low, int high)
{

    if (low > high)
        return -1; // base case 1

    int mid = low + (high - low) / 2;

    if (a[mid] == k)
        return mid; // base case 2

    else if (k > a[mid])
        return Binary_Search_using_Recursion(a, n, k, mid + 1, high);

    else
        return Binary_Search_using_Recursion(a, n, k, low, mid - 1);
}

int main()
{

    int n, k;

    cin >> n >> k;

    int a[n];

    for (int i = 0; i < n; i++)
        cin >> a[i];

    cout << Binary_Search_using_Recursion(a, n, k, 0, n - 1) << endl;

    return 0;
}