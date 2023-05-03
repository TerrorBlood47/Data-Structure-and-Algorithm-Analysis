//g4g - Fractional knapsack 

#include<bits/stdc++.h>
using namespace std;

class item{
public:
    int profit;
    int weight;


    item(int profit, int weight){
        this->profit = profit;
        this->weight = weight;
    }
};


bool cmp(item* a, item* b){

    double d1 = (double)a->profit/a->weight;
    double d2 = (double)b->profit/b->weight;
    
    if(d1>=d2) return true;
    else return false;
}

item** merging(item** a, int st, int mid, int end){

    int nl = (mid - st) + 1;
    int nr = end - mid;

    item** l = new item*[nl];
    item** r = new item*[nr];

    for(int i=0; i<nl; i++){
        l[i] = a[st + i];
    }

    for(int i=0; i<nr; i++){
        r[i] = a[mid + 1 + i];
    }

    int i=0,j=0,k=0;

    while(i<nl and j<nr){
        
        if(cmp(l[i],r[j])){
            a[k] = l[i];
            k++;
            i++;
        }
        else{
            a[k] = r[j];
            j++;
            k++;
        }
    }

    while(i<nl){
        a[k] = l[i];
            k++;
            i++;
    }

    while(j<nr){
        a[k] = r[j];
            k++;
            j++;
    }

    return a;
}

item** merge_sort(item** a, int st, int end){

    if(st < end){
        int mid = st + (end - st)/2 ;
        a = merge_sort(a,st,mid);
        a = merge_sort(a,mid+1,end);
        a = merging(a,st,mid,end);
    }
    else return a;
}

int fractional_knapsack(item** a, double profit, int w, int i, int n){
    cout<<i<<" "<<profit<<endl;
    if(i==n){
        cout<<"sad"<<endl;
        return profit;
    }

    if(w-(a[i]->weight) <= 0){
        cout<<"adea"<<endl;
        double q = a[i]->weight;
        double p = a[i]->profit;
        profit += (double)(w/q)*(p);
        return profit;
    }

    w = w - a[i]->weight;
    profit += (double)a[i]->profit; 
    i++;

    return fractional_knapsack(a,profit,w,i,n);

}

int main(){

int n;

cin>>n;

item** a = new item*[n];

for(int i=0; i<n; i++){
    int p,w;
    cin>>p>>w;

    a[i] = new item(p,w);
}

int w;
cin>>w;

a = merge_sort(a,0,n-1);

// for(int i=0; i<n; i++){
//     cout<<a[i]->profit<<" "<<a[i]->weight<<endl;
// }

cout<<fractional_knapsack(a,0,w,0,n);

return 0;
}