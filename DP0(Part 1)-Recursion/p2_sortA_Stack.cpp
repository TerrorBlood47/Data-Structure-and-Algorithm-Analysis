/*
Problem Link  : Aditya Verma - Sort A Stack ( https://youtu.be/MOGBRkkOhkY )
About Problem : Recursion implementation
Tags          : Need to see again..................
Notes         : -> same as sorting an array

 */

#include <bits/stdc++.h>
using namespace std;

void insert(stack<int>&s, int temp)
{
    if (s.size() == 0 || s.top() <= temp)
    {
        s.push(temp);
        return;
    }

    int val = s.top();

    s.pop();

    insert(s, temp);

    s.push(val);
}


//the stack is stored in descending order, but only printed in ascending order due to the characteristics of the container


void sort_Stack(stack<int>&s)
{ // call by reference

    if (s.size() == 1)
    {
        return;
    }

    int temp = s.top();  //check 

    s.pop(); // deletes the last element from the stack

    sort_Stack(s);

    insert(s, temp);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    stack<int>s;

    int n;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        s.push(x);
    }

    sort_Stack(s);

    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }

    return 0;
}