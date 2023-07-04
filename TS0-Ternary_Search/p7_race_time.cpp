/*
Problem Link  : https://www.codechef.com/problems/AMCS03
About Problem : Ternary Search Problem
Tags          : 
Notes         : 
        
 */



#include <bits/stdc++.h>
using namespace std;

double f(double t, double s[], double d[], int n){
    
    double max = 1.00*INT_MIN;
    double min = 1.00*INT_MAX;
    
    for(int i=0; i<n; i++){
        double p = s[i]*t + d[i];

        if(max < p) max = p;

        if(min > p) min = p;
    }
    
    return (max - min);
}


int main() {
	int n;
    double k;
	
	cin>>n>>k;
	
	double s[n], d[n];
	
	
	for(int i=0; i<n; i++){
	    cin>>s[i]>>d[i];
	}
	
	double l = 0, r = k;
	double fm1, fm2;
	
	while((r-l)>0.00000001){
	    
	    double m1 = l + (r - l)/3;
	    double m2 = r - (r - l)/3;
	    
	    fm1 = f(m1,s,d,n);
	    fm2 = f(m2,s,d,n);
	    
	    if(fm1 == fm2){
	        l = m1;
	        r = m2;
	    }
	    else if(fm1 < fm2){
	        r = m2;
	    }
	    else {
	        l = m1;
	    }
	}
	
    double ans = f(l,s,d,n);
    
    printf("%.6lf",ans);
	
	
	return 0;
}
