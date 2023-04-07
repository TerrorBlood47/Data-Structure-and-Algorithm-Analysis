/*
Problem Link  : Aditya Verma - 7 Number of Times a Sorted array is Rotated ( https://youtu.be/4WmTRFZilj8 ) , 
                geeksforgeeks(https://www.geeksforgeeks.org/find-rotation-count-rotated-sorted-array/ )
About Problem : Finding number of rotation  in a sorted array
Tags          : 
Notes         : -> The index of the minimum element is the number of times the array is rotated
                -> The minimum element is smaller than both of its neighbors in a sorted array
                -> The approach should be always moving towards the unsorted part of the array w.r.t. the mid-element
        
 */


#include<bits/stdc++.h>
using namespace std;

int number_of_rotation(int arr[], int n){ //returns index of the smallest element
    int start,end,mid,previous,next;

    start=0; end=n-1; mid=(start + (end-start)/2) ; 

    if(arr[start]<=arr[end]){
        return 0;    /*returns 0 if array is already sorted*/
    }
    else{
        while(start<=end){
            mid=(start + (end-start)/2);
            previous = (mid-1+n)%n; //so that the index does not become neg and can rotate back to the top once it tends to....
            next = (mid+1)%n; //check........
            

            if(arr[previous]>=arr[mid] && arr[mid]<=arr[next]){
                return mid;
            }
            else if(arr[mid]<=arr[end]){ //then the left part is unsorted
                end = mid-1;
            }
            else if(arr[mid]>=arr[start]){ //then the right part is unsorted
                start = mid+1;
            }
            
        }
    } 
/*
    Time_Complexity : O(log N)
    Space_Complexity: O(1), since no extra space has been taken  
*/
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

    int n,i,rotation_number;
    scanf("%d",&n); 

    int arr[n];

    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    
    rotation_number = number_of_rotation(arr,n);

    view_output(arr,n);
    
    cout<<rotation_number<<endl;
    
    return 0;
}