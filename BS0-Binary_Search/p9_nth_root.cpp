/*
Problem Link  : Given by sir - Finding nth root
About Problem : 
Tags          : 
Notes         : 

        
 */


#include<bits/stdc++.h>
using namespace std;


double multiply(double mid, int n){
    double res = 1;

    for(int i=0;i<n;i++)res *= mid;

    return res;
}

double nth_root(int n, double x){

    double i = 0, j = x, mid; // works for x >= 1 only

    while(i<j){

        mid = i + (j-i)/2;
        double m = multiply(mid,n);

        if(abs(x-m)<0.0000001){
            return mid;
        }
        else if(m<x) i = mid;
        else if(m>x) j = mid; 
        }

}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    double x;

    cin>>n>>x;

    double root = nth_root(n,x);

    cout<<root<<endl;
    
    return 0;
}