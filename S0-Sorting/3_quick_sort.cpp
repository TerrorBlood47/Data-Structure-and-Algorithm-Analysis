#include<bits/stdc++.h>
using namespace std;


void swap_array(int *a , int *b){
    int temp=*a;
    *a = *b;
    *b = temp;

    return;
}

//Haore's Partition
int partition(int arr[], int low ,int high){

    // Link - GeeksForGeeks
    
    int i=low-1,j=high+1; //check
    int pivot = arr[low];
    
    while(true){

        do{             
            i++; //because i needs to be incremented right after swapping otherwise the loop will go on for infinity 
        }while(arr[i]<pivot);//finds the index whose value is greater than or equal to the pivot

        do{             
            j--; //same reason as j
        }while(arr[j]>pivot);//finds the index whose value in less than or equal to the pivot 

        if(i>=j) {
            return j; //next pivot
        }

        swap_array(&arr[i],&arr[j]);
        
/*
        int temp =arr[i];
        arr[i] = arr[j];
        arr[j] = temp; */
    }
    

}

void quick_sort(int arr[], int lower_bound, int upper_bound){
    
    if(lower_bound < upper_bound){
        int next_pivot = partition(arr,lower_bound,upper_bound);
        quick_sort(arr,lower_bound,next_pivot); //check
        quick_sort(arr,next_pivot+1,upper_bound); 
    }

    return;

    /* Time complexity : Average Case : O(nlog(n))
                         Worst Case   : O(n^2)
                         Best Case    : O(n)

      Space Complexity : Worst Case   : O(1)

      Unstable sorting algorithm
       T(n) = T(k) + T(n-k-1) + theta(n)
       The first two terms are for two recursive calls, the last term is for the partition process. 
       k is the number of elements that are smaller than the pivot. 

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

    
    quick_sort(arr,0,n-1);      /* usually the fastest sorting algorithm at average case....most in-built sort fuctions are 
                                     //implementation of quick sort algo..  */
    

    //sort(arr,arr+n);

    view_output(arr,n);

    return 0;
}

/*
Q1)Why Quick Sort is preferred over MergeSort for sorting Arrays ?

Ans : Quick Sort in its general form is an in-place sort (i.e. it doesn’t require any extra storage) whereas merge sort requires O(N) 
extra storage, N denoting the array size which may be quite expensive. Allocating and de-allocating the extra space used for merge sort
increases the running time of the algorithm. Comparing average complexity we find that both type of sorts have O(NlogN) average complexity 
but the constants differ. For arrays, merge sort loses due to the use of extra O(N) storage space.

Most practical implementations of Quick Sort use randomized version. The randomized version has expected time complexity of O(nLogn). 
The worst case is possible in randomized version also, but worst case doesn’t occur for a particular pattern (like sorted array) and 
randomized Quick Sort works well in practice.

Quick Sort is also a cache friendly sorting algorithm as it has good locality of reference when used for arrays.
Quick Sort is also tail recursive, therefore tail call optimizations is done.

Q2) Is QuickSort stable? 
Ans: The default implementation is not stable. However any sorting algorithm can be made stable by considering indexes as comparison parameter. 

Q3) Is QuickSort In-place? 
Ans : As per the broad definition of in-place algorithm it qualifies as an in-place sorting algorithm as it uses extra space only for storing 
recursive function calls but not for manipulating the input. 

*/