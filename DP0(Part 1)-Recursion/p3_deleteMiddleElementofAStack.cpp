/*
Problem Link  : Aditya Verma - Delete Middle Element of a Stack ( https://youtu.be/oCcUNRMl7dA )
About Problem : Recursion implementation
Tags          : Need to see again..................
Notes         : -> delete the topmost element and push them back later except for the case of mid element

 */

#include <bits/stdc++.h>
using namespace std;

void delete_element_until_mid_is_found(stack<int>&s, int k){
    // if(s.empty()){
    //     return ; //?????
    // }

    if(k==1){
        s.pop();
        return ;//s.top();
    }
    int temp = s.top();
    s.pop();
    delete_element_until_mid_is_found(s,k-1);
    s.push(temp);   //push them again into the stack except for mid element
    return ;
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

    int mid = n/2 + 1;

    delete_element_until_mid_is_found(s,mid);

    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }

    

    return 0;
}