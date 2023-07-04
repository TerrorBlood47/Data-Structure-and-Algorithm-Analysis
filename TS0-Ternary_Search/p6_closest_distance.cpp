/*
Problem Link  : lightoj - closest distance
About Problem : Ternary Search Problem
Tags          : 
Notes         : 
        
 */



#include<bits/stdc++.h>
using namespace std;


class Point{
public:
    double x;
    double y;

    Point(){

    }

    Point(double x, double y){
        this->x = x;
        this->y = y;
    }

};

double dist(Point &a, Point &b){
    double dist = sqrt( (a.x - b.x)*( a.x - b.x)  +  (a.y - b.y)*(a.y - b.y));

    return dist;
}

int main(){
int t;
scanf("%d",&t);

int w=1;

while(w<=t){
    Point a,b,c,d;

    cin>>a.x>>a.y>>b.x>>b.y>>c.x>>c.y>>d.x>>d.y;

    Point m1, m2 , k1 , k2;

    Point l,r;
    Point st, end;

    l.x = a.x;
    l.y = a.y;
    r.x = b.x;
    r.y = b.y;

    st.x = c.x;
    st.y = c.y;
    end.x = d.x;
    end.y = d.y;

    double d1, d2;

    while(dist(l,r) > 0.00000001){
        
        m1.x = l.x + (r.x - l.x)/3;
        m1.y = l.y + (r.y - l.y)/3;
        m2.x = r.x - (r.x - l.x)/3;
        m2.y = r.y - (r.y - l.y)/3;

        k1.x = st.x + (end.x - st.x)/3;
        k1.y = st.y + (end.y - st.y)/3;
        k2.x = end.x - (end.x - st.x)/3;
        k2.y = end.y - (end.y - st.y)/3;

        d1 = dist(m1,k1);
        d2 = dist(m2,k2);

        if(d1 == d2){
            l = m1;
            r = m2;

            st = k1;
            end = k2;
        }
        else if(d1 < d2){
            r = m2;
            end = k2;
        }
        else if(d1 > d2){
            l = m1;
            st = k1;
        }
    }

    double min_dist = min(d1,d2) ;

    cout<<"Case "<<w<<": ";
    printf("%.10lf\n",min_dist);

    w++;
}
return 0;
}