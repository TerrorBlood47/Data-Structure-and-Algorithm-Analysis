/*
Problem Link  : Aditya Verma - Josephus Problem ( https://youtu.be/ULUNeD0N9yI )
About Problem : Recursion implementation
Tags          : 
Notes         : ->  IBH method



 */


#include <bits/stdc++.h>
using namespace std;

int finding_safe_pos_for_josephus(vector<int>&v, int k, int index){
    if(v.size()==1){
        return v[0];
    }

    index = ((index+k)%v.size());

    v.erase(v.begin()+index);

    return finding_safe_pos_for_josephus(v,k,index);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n,k;

    cin>>n>>k;

    k--; //(k-1)th person will be killed

    vector<int>v;

    for(int i=1;i<=n;i++){
        v.push_back(i);
    }

    int safe_position = finding_safe_pos_for_josephus(v,k,0);

    cout<<safe_position<<endl;

    return 0;
}