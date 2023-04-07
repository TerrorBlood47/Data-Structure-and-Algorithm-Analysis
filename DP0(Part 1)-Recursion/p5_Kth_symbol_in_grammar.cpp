/*
Problem Link  : Aditya Verma - Kth Symbol in Grammar ( https://youtu.be/5P84A0YCo_Y )
About Problem : Recursion implementation
Tags          : 
Notes         : -> requires individual observation skill

 */



///need to practice more like it


#include <bits/stdc++.h>
using namespace std;

int make_grammar(int n, int k){

    if(n==1 && k==1){
        return 0;
    }

    int length  = pow(2,n-1);

    int mid = length/2;


    if(k<=mid) return make_grammar(n-1,k);
    else return !make_grammar(n-1,k-mid);

}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,k;

    cin>>n>>k;

    int ans = make_grammar(n,k);

    cout<<ans<<endl;

    return 0;
}