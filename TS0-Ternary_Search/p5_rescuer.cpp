/*
Problem Link  : https://www.hackerearth.com/problem/algorithm/rescuer-2d2495cb/
About Problem : Ternary Search Problem
Tags          : 
Notes         : 
        
 */



#include <bits/stdc++.h>
using namespace std;

double time(double a,double b,double c,double d,double u,double v, double x){
	double s = sqrt((x - a)*(x - a) + (b*b));
	double p = sqrt((x - c)*(x - c) + (d*d));

	double t = (s/u) + (p/v);

	return t;
}

int main() {
	int t;
	scanf("%d", &t);

	while(t--){
		double a,b,c,d,u,v;

		scanf("%lf%lf%lf%lf%lf%lf",&a,&b,&c,&d,&u,&v);

            double l,r;
            if(a<=c) l = a, r = c;
            else l = c, r = a;

            while((r-l) > 0.000001){
                double x1 , x2;
                
                x1 = l + (r-l)/3;
                x2 = r - (r-l)/3;

                double t1, t2;

                t1 = time(a,b,c,d,u,v,x1);
                t2 = time(a,b,c,d,u,v,x2);

                cout<<t1<<" "<<t2<<endl;

                if(t1 == t2){
                    l = x1;
                    r = x2;
                }
                else if(t1 < t2){
                    r = x2;
                }
                else{
                    l = x1;
                }
            }

            double min_time = min(time(a,b,c,d,u,v,l), time(a,b,c,d,u,v,r));

            printf("%.5lf\n",min_time);
        
	}

    return 0;
}