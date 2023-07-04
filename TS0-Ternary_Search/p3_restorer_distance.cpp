/*
Problem Link  : https://codeforces.com/problemset/problem/1355/E
About Problem : Ternary Search Problem
Tags          : 
Notes         : 
        
 */

///really hard, saved for later

#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

ll MinCost(int h[],int n, int a, int r, int m){
    
}

int main(){

int n,a,r,m;

cin>>n>>a>>r>>m;

int h[n];

for(int i=0; i<n; i++){
    cin>>h[i];
}

ll min_cost = MinCost(h,n,a,r,m);

cout<<min_cost<<endl;
return 0;
}