/*
Problem Link  : Aditya Verma - Reverse a Stack using Recursion ( https://youtu.be/8YXQ68oHjAs )
About Problem : Recursion implementation
Tags          : 
Notes         : -> at first, remove the elements from the stack and store them in a global vector
                -> Then push them into the stack again in reverse order

 */

#include <bits/stdc++.h>
using namespace std;

vector<int>v;

void add_in_stack_in_reverse(stack<int>&s , int i , int n){

    if(i == n){
        return;
    }

    s.push(v[i]);

    i++;

    add_in_stack_in_reverse(s,i,n);

}

void remove_from_stack(stack<int>&s){
    if(s.size()==0){
        int i = 0;
        int n = v.size();

        add_in_stack_in_reverse(s ,i ,n);

        return; //-> returning here does not make any difference
    }

    int temp = s.top();

    v.push_back(temp);
    s.pop();

    remove_from_stack(s);

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

    remove_from_stack(s);

    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }

    

    return 0;
}