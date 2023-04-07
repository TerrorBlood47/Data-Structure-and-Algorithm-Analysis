/*
Problem Link     : Aditya Verma - 11 Ceil of an element in a Sorted Array( https://youtu.be/uiz0IxPCUeU)
About Problem    : Implementation of Binary Search on a sorted array  to find the ceil of an element
Tags             :
Notes            : 
*/


#include<bits/stdc++.h>
using namespace std;


int binary_search_ceil(vector<int>a, int n, int k){
    int i=0,j=n-1,mid=i+(j-i)/2,res=-1;

    while(i<=j){
        mid=i+(j-i)/2;
        if(k==a[mid]){  
            return a[mid];//ceil of an integer element is the element itself....that is if it is present in the array
        }
        else if(k>a[mid]){
            i = mid + 1;
        }   
        else{
            j = mid - 1;
            res = a[mid];// if the mid is greater than the element than we will store it.....the goal is to find the element with the smallest value 
        }                 // which is larger than the searched element
    }
    

    return res;
}



int main(){
    int ceil,i,j,n,k;

    vector<int>a;

    cin>>k>>n;

    for(i=0;i<n;i++){
        int x;
        cin>>x;
        a.push_back(x);
    }

    ceil = binary_search_ceil(a,n,k);

    if(ceil>=0)cout<<ceil<<endl;
    else cout<<"not found\n";

    return 0;
}