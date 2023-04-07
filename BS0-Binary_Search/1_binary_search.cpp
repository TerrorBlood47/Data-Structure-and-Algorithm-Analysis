/*
Problem Link  : Binary Search, Lower Bound and Upper Bound Implemented and matched with STL
About Problem : Binary Search Implementation
Tags          : 
Notes         :
        lower_bound returns an iterator pointing to the first element 
        in the range [first,last) which has a value not less than ‘val’. 
        upper_bound returns an iterator pointing to the first element in the 
        range [first,last) which has a value greater than ‘val’. 
 */


#include<bits/stdc++.h>
using namespace std;

int binary_search(int arr[], int n, int element){
    int i,j,start,end,mid;

    start=0; end=n-1; mid=(start + (end-start)/2) ; /* mid=start + (end-start)/2 = (start + end)/2 ........however the initial one is safer because 
                                                     (start + end) might be greater than INT_MAX which might result in an unwanted overflow     */
    
    while(start<=end){
        mid=(start + (end-start)/2);

        if(element==arr[mid]){
            return mid;
        }
        else if(element<arr[mid]){ //the element is positioned to the left of the mid element
            start = start; 
            end = mid-1;
        }
        else if(element>arr[mid]){ //the element is positioned to the right of the mid element
            start = mid+1;
            end = end;
        }
    }
    return -1;    
}

int LowerBound(int arr[], int n, int element){
    int i,j,start,end,mid;

    start=0; end=n-1; mid=(start + (end-start)/2) ;
    
    while(start<=end){
        mid=(start + (end-start)/2);

        if(element==arr[mid]){
            return mid;
        }
        else if(element<arr[mid]){ //the element is positioned to the left of the mid element
            start = start; 
            end = mid-1;
        }
        else if(element>arr[mid]){ //the element is positioned to the right of the mid element
            start = mid+1;
            end = end;
        }
    }
    return end; //check   
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

    int n,i,index,element,LB_index,UB_index;
    scanf("%d%d",&n,&element); 

    int arr[n];

    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    sort(arr,arr+n); // the array must be sorted for correct implementation of binary search

    //view_output(arr,n);
    //index = binary_search(arr,n,element);
    LB_index = LowerBound(arr,n,element);

    cout<<endl<<arr[LB_index]<<endl;

    view_output(arr,n);
    /*
    if(index>=0){
        cout<<index<<endl;
    }
    else if(index<0){
        cout<<"Not Found\n";
    }
    */

    
    return 0;
}