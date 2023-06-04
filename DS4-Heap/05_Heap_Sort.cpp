#include<bits/stdc++.h>
using namespace std;

void Maxheapify(int a[], int n, int i){
    int largest = i;
    int l = (2*i + 1);
    int r = (2*i + 2);

    if(l<n && (a[l]>a[largest])){
        largest = l;
    }

    if(r<n && (a[r]>a[largest])){
        largest = r;
    }

    if(largest != i){
    
        swap(a[i],a[largest]);
        Maxheapify(a,n,largest);
    }
}

void heap_sort(int a[], int n){
    
    for(int i=n/2 - 1; i>=0 ; i--){ //bottom-up heap construction method
        Maxheapify(a,n,i);
    }

    for(int i=n-1; i>0; i--){
        swap(a[0],a[i]);
        Maxheapify(a,i,0);
    }

    
}

int main(){

int a[] = {20,23,232,1,3242,231,32,343,23,3223,2332};

int n = sizeof(a)/sizeof(a[0]);

cout<<n<<endl;

heap_sort(a,n);

for(int i=0; i<n; i++){
    cout<<a[i]<<" ";
}


return 0;
}