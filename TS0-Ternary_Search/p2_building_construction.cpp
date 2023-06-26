/*
Problem Link  : KOPC12A - K12 - Building Construction
About Problem : Ternary Search Problem
Tags          : 
Notes         : 
        
 */


#include<bits/stdc++.h>
using namespace std;


typedef long long int ll;

ll func(int x,int h[], int c[], int n){
    ll sum = 0;
    //cout<<x<<endl;

    for(int i=0; i<n ;i++){
        sum += abs(x - h[i])*c[i];
    }
    return sum;
}

ll MinCost(int h[], int c[], int n, int max_height){

    ll l = 0, r = max_height;

    ll m1,m2,cm1,cm2;

    while(l<=r){
        m1 = l + (r-l)/3;
        m2 = r - (r-l)/3;

        cm1 = func(m1,h,c,n);
        cm2 = func(m2,h,c,n);

        if(cm1 < cm2){
            r = m2 - 1;
        }
        else if(cm1 > cm2){
            l = m1 + 1;
        }
        else{
            r = m2 - 1;
            l = m1 + 1;
        }
    }


    return min(cm1,cm2);

}


int main(){
int t;
cin>>t;

while(t--){
    int n;
    cin>>n;
    int h[n];
    int c[n];

    int max_height = 0;

    for(int i=0; i<n; i++){
        cin>>h[i];

        if(h[i] > max_height){
            max_height = h[i];
        }
    }

    for(int i=0; i<n; i++)cin>>c[i];

    ll min_cost = MinCost(h,c,n,max_height);

    cout<<min_cost<<endl;
}
return 0;
}