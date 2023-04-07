/*
Problem Link     : Aditya Verma - 9 Searching in a Nearly Sorted Array( https://youtu.be/W3-KgsCVH1U )
About Problem    : Implementation of Binary Search on a nearly sorted array  
Tags             :
Notes            : 
*/


#include<bits/stdc++.h>
using namespace std;


int binary_search_nearly_sorted_array(vector<int>a, int n, int k){
    int i=0,j=n-1,mid=i+(j-i)/2;

    while(i<=j){
        mid=i+(j-i)/2;
        if(k==a[mid]){  
            return mid;
        }
        else if(k==a[mid+1] && mid+1<=j){ //check
            return mid+1;
        }
        else if(k==a[mid-1] && mid-1>=i){ //check
            return mid-1;
        }
        else if(k<a[mid])j=mid-2;
        else  i=mid+2;
    }

    return -1;
}


int main(){
    int index,i,j,n,k;

    vector<int>a;

    cin>>k>>n;

    for(i=0;i<n;i++){
        int x;
        cin>>x;
        a.push_back(x);
    }

    index = binary_search_nearly_sorted_array(a,n,k);

    if(index>=0)cout<<index<<endl;
    else cout<<"not found\n";

    return 0;
}