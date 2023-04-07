/*
Problem Link  : Merge sort to count the number of inversions - Apna College
About Problem : Merge sort special
Tags          : 
Notes         : -> number of inversions = number of swapping between two adjacent elements to sort the array
                -> Can be implemented using global array too
        
 */


#include<bits/stdc++.h>
using namespace std;


int divide_and_merge(int arr[], int start, int mid, int end){
    
    int nL,nR, inversions = 0; //check

    nL = mid - start + 1;
    nR = end - mid ;

    int leftArr[nL];
    int rightArr[nR];

    for(int i=0;i<nL;i++){
        leftArr[i]=arr[start + i];
    }

    for(int j=0;j<nR;j++){
        rightArr[j]=arr[mid + 1 + j];
    }

    int i,j,k;

    i = 0;
    j = 0;
    k = start;

    while(i<nL && j<nR){

        if(leftArr[i]<rightArr[j]){
            arr[k] = leftArr[i];
            i++;
            k++;
        }
        else if(leftArr[i]>=rightArr[j]){
            arr[k] = rightArr[j];
            j++;
            k++;
            inversions += (nL - i); // if an element from right array is smaller than that of left, that it is smaller than all the elements 
                                // positioned left to the left array
        }

    }

    while(i<nL){
        arr[k] = leftArr[i];
        i++;
        k++;
        
    }

    while(j<nR){
        arr[k] = rightArr[j];
        j++;
        k++;
        
        
    }

    return inversions;
}

int merge_sort(int arr[], int start, int end){

    int inversions = 0;
    if(start < end){   //base case

        int mid = start + (end - start)/2;

        inversions += merge_sort(arr,start, mid);
        inversions += merge_sort(arr,mid + 1,end);
        inversions += divide_and_merge(arr,start,mid,end);

    }

    return inversions;

    //Time Complexity- O(nlog(n))
    //Space Complexity- O(n)
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

    int n,i;
    

    cin>>n;

    int arr[n];

    for(i=0;i<n;i++){
        cin>>arr[i];
    }

    int inv = merge_sort(arr,0,n-1);          
    
    view_output(arr,n);

    cout<<inv<<endl;

    return 0;
}