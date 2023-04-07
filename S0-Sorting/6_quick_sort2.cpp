#include<bits/stdc++.h>
using namespace std;


void swap_array(int *a , int *b){
    int temp=*a;
    *a = *b;
    *b = temp;

    return;
}

/* This function takes last element as pivot, places the pivot element at its correct position in sorted array,
 and places all smaller (smaller than pivot) to left of pivot and all greater elements to right of pivot */

int lomuto_partition(int a[], int low, int high){

    int pivot = a[high];// pivot (Element to be placed at right position)
    int i = low - 1;// Index of smaller element and indicates the 
                    // correct position of pivot found so far

    for(int j = low; j<high ; j++){

        if(a[j] < pivot){   // If current element is smaller than the pivot
            
            i++;    // increment index of smaller element    
            swap_array(&a[i],&a[j]);
        }

    }

    swap_array(&a[i+1],&a[high]);

    return i+1;

}



void quick_sort_2(int arr[], int lower_bound, int upper_bound){
    
    if(lower_bound < upper_bound){
        int next_pivot = lomuto_partition(arr,lower_bound,upper_bound);
        quick_sort_2(arr , lower_bound , next_pivot - 1); //before pivot
        quick_sort_2(arr , next_pivot + 1 , upper_bound); //after pivot
    }

    return;

    /* Time complexity : Average Case : O(nlog(n))
                         Worst Case   : O(n^2)

      Space Complexity : Worst Case   : O(n)
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

    int n,i;
    scanf("%d",&n);

    int arr[n];

    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    
    quick_sort_2(arr,0,n-1);      
    

    //sort(arr,arr+n);

    view_output(arr,n);

    return 0;
}