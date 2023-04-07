/*
Problem Link  : Aditya Verma - Sort An array using Recursion ( https://youtu.be/AZ4jEY_JAVc )
About Problem : Recursion implementation
Tags          : Need to see again..................
Notes         :

 */

#include <bits/stdc++.h>
using namespace std;

void insert(vector<int> &v, int temp)
{
    if (v.size() == 0 || v[v.size() - 1] <= temp)
    {
        v.push_back(temp);
        return;
    }

    int val = v[v.size() - 1];

    v.pop_back();

    insert(v, temp);

    v.push_back(val);
}



void sort_using_recursion(vector<int> &v)
{ // call by reference

    if (v.size() == 1)
    {
        return;
    }

    int temp = v[v.size() - 1];

    v.pop_back(); // deletes the last element from the vector

    sort_using_recursion(v);

    insert(v, temp);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vector<int> v;

    int n;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }

    sort_using_recursion(v);

    for (int i = 0; i < n; i++)
        cout << v[i] << " ";

    return 0;
}