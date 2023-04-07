/*
Problem Link  : Aditya Verma - 15 Minimum Difference Element in a Sorted Array( https://youtu.be/3RhGdmoF_ac )
About Problem : Binary Search Implementation
Tags          : 
Notes         : -> Find the index of the key element , that is where the difference will be minimum which is zero
                -> If the exact match to the key element is not present in the array, just run the same-old binary search 
                   casually; when the outer while loop will be broken, the end and start index will represent the immediate 
                   smaller and greater values than the key element present in the array respectively......the index pointing to
                   minimum difference is one of these indices....

        
 */


#include<bits/stdc++.h>
using namespace std;

int binary_search(int arr[], int n, int element){
    int i,j,start,end,mid,res;

    start=0; end=n-1; mid=(start + (end-start)/2) ; 
    
    while(start<=end){
        mid=(start + (end-start)/2);

        if(element==arr[mid]){
            return mid;
        }
        else if(element<arr[mid]){ 
            end = mid-1;
        }
        else if(element>arr[mid]){ 
            start = mid+1;
        }
    }

    if(abs(arr[end]-element)<=abs(arr[start]-element))res=end; 
    else res=start;

    return res;    
}




void view_output(int a[], int n){
    int i;

    for(i=0;i<n;i++)printf("%d ",a[i]);

    cout<<endl;
    return;
}



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,i,index,element;
    scanf("%d%d",&n,&element); 

    int arr[n];

    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    sort(arr,arr+n); // the array must be sorted for correct implementation of binary search

    //view_output(arr,n);
    index = binary_search(arr,n,element);
    
    cout<<index<<endl;

    view_output(arr,n);
    
    return 0;
}