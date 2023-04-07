/*
Problem Link  : Aditya Verma - 17 Peak Element ( https://youtu.be/OINnBJTRrMU )  
                
About Problem : 
Tags          : 
Notes         : -> a peak element is an (unsorted) array is greater than both of its neighbors
                -> There can be multiple peak elements in an array, just finding one is sufficient
        
 */


#include<bits/stdc++.h>
using namespace std;

int peak_element(int arr[], int n){ 
    int start,end,mid,previous,next;

    
    if(arr[0] > arr[1]){
        return 0;   
    }
    if(arr[n-1] > arr[n-2]){
        return n-1;   
    }
    
    start=1; end=n-2; mid ; 

        while(start<=end){
            mid=(start + (end-start)/2);
            previous = mid-1;  
            next = mid+1; 
            
            if(arr[previous] < arr[mid] && arr[mid] > arr[next]){
                return mid;
            }
            else if(arr[mid] < arr[previous]){ // just move towards the element that is greater
                end = mid -1;
            }
            else if(arr[mid] < arr[next]){ 
                start = mid + 1;
            }
            
        }
    
    return -1;
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
    scanf("%d",&n); 

    int arr[n];

    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    
    int peak_element_index = peak_element(arr,n);

    //view_output(arr,n);
    
    cout<<peak_element_index<<endl;
    
    return 0;
}