/*
Problem Link  : https://codeforces.com/problemset/problem/578/C
About Problem : Ternary Search Problem
Tags          : 
Notes         : 
        
 */

////mile nai

#include<bits/stdc++.h>
using namespace std;

double func(double x,vector<double>a){
    int n = a.size();
    for(int i=0; i<a.size(); i++){
        a[i] = a[i] - x;
    }

    vector<double> b;
    double k = 0;
    for(int i=0; i<a.size(); i++){
        k += a[i];

        b.push_back( k);
    }

    double maxi = 1.00*INT_MIN;

    vector<double>c;
    c.push_back(abs(b[0]));

    
    int i=1,j=1;
    int sum = 0;
    while(!(i==n-1 and j==n-1)){

        if(i==j){
            if(i==n and j==n) break;
            else if(i==n){
                c.push_back(abs(c[i-1]-b[j]));
                j++;
            }
            else{
                c.push_back(abs(c[i-1] + b[i]));
                i++;
            }
        }
        else{
            if(i!=n){
                c.push_back(abs(c[i-1] + b[i]));
                i++;
            }else{
                c.push_back(abs(c[i-1]-b[j]));
                j++;
            }
        }
    }


    for(int k=0; k<c.size(); k++){
        maxi = max( maxi, c[i]);
    }

    return maxi;
}

int main(){
int n;
cin>>n;

vector<double> a(n);
double min = 100001, sum = 0; 
for(int i=0; i<n; i++){
    cin>>a[i];

    if(min > a[i]) min = a[i];

    sum += a[i];
}

double l = min, r = sum;

double m1, m2;

while( (r - l) > 0.0000001){

    m1 = l + (r - l)/3;
    m2 = r - (r - l)/3;

    double fm1 = func(m1,a);
    double fm2 = func(m2,a);

    if( fm1 > fm2){
        l = m1;
    }
    else if( fm1 < fm2){
        r = m2;
    }
    else{
        l = m1;
        r = m2;
    }
}

double fx = func(l,a);

cout<<l<<endl;

return 0;
}