/*
Problem Link  : This is JEE - -Codechef -> ICM2003
About Problem : Ternary Search Problem
Tags          : 
Notes         : 
        
 */



#include <bits/stdc++.h>
using namespace std;

double f(double x, double b, double c){
    double fx = (x*x + b * x + c);
    double d = sin(x);
    fx /= d;
    
    return fx;
}

void findMin(double b, double c){
    
    double l = 0, r = acos(-1)/2 , m1,m2;
    
    m1 = l + (r - l)/3.0;
    m2 = r - (r - l)/3.0;
    
    double f1 = f(m1,b,c);
    double f2 = f(m2,b,c);
    
    while((r - l) > 0.000001){
        m1 = l + ((r - l)/3.0);
        m2 = r - ((r - l)/3.0);
        
        f1 = f(m1,b,c);
        f2 = f(m2,b,c);
        
        if(f1 < f2){
            r = m2;
        }
        else if( f1 > f2){
            l = m1;
        }
        else{
            l = m1;
            r = m2;
        }
    }
    
    cout << setprecision(6) << fixed << f(l,b,c) << '\n'; //check
    
}


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
	int t;
	cin>>t;
	
	while(t--){
	    double b,c;
	    
	    cin>>b>>c;
	    
	    findMin(b,c);
	    
	}
	return 0;
}
/*
The setprecision manipulator allows you to specify the number of digits to be displayed after the decimal point. It is defined 
in the <iomanip> header. 

The fixed manipulator is used to display floating-point numbers in fixed-point notation, which means that the decimal point is 
always displayed, even if there are no fractional digits. By default, numbers are displayed in scientific notation if they are 
too large or too small. 

*/