/*
Problem Link  : https://vjudge.net/problem/UVA-12197
About Problem : Ternary Search Problem
Tags          : 
Notes         : 
        
 */

#include<bits/stdc++.h>
using namespace std;

double longest_dist( vector<pair<double, double>>&v, double &x){
    int n = v.size();
    double dd = INT_MIN;
    
    for(int i=0; i<n; i++){
        double m = (v[i].first - x)*(v[i].first - x) + (v[i].second*v[i].second);
        m = sqrt(m);
        if(m > dd) dd = m;
    }

    return dd;
}


int main(){

while(true){

    int n;

    scanf("%d",&n);

    if(n==0)break;

    vector<pair<double,double>> v;

    double min = 200000.0;
    double max = -200000.0;

    while(n--){
        double a,b;

        scanf("%lf%lf",&a,&b);

        if(a < min) min = a;
        if(a > max) max = a;

        v.push_back(make_pair(a,b));
    }

double l=min, r = max;
    double m1, m2;
    double dm1, dm2;

    while((r - l)> 0.0000000001){

        m1 = l + (r-l)/3;
        m2 = r - (r-l)/3;

        dm1 = longest_dist(v,m1);
        dm2 = longest_dist(v,m2);

        if(dm1 == dm2){
            l = m1;
            r = m2;
        }
        else if(dm1 < dm2){
            r = m2;
        }
        else if(dm1 > dm2){
            l = m1;
        }
    }

    double x,dist = INT_MIN,time;

    x = l;
    
    
    for(int i=0; i<v.size(); i++){
        double k  =  (v[i].first - x)*(v[i].first - x) + (v[i].second*v[i].second);

        k = sqrt(k);

        if(k > dist) dist = k;
    }

    time = dist;

    printf("%.9lf %.9lf\n",x,time);

}
return 0;
}