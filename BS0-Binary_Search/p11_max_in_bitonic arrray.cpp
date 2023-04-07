/*
Problem Link  : Aditya Verma - 18 Find maximum element in Bitonic Array   
                
About Problem : 
Tags          : 
Notes         : -> A Bitonic Point is a point in bitonic sequence before which elements are strictly increasing and after which elements 
                    are strictly decreasing. 
                -> A Bitonic point doesn't exist if array is only decreasing or only increasing.

        
 */


#include<bits/stdc++.h>
using namespace std;

int max_in_bitonic_array(int arr[], int n){ 
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

    
    int peak_element_index = max_in_bitonic_array(arr,n);

    //view_output(arr,n);
    
    cout<<arr[peak_element_index]<<endl;
    
    return 0;
}