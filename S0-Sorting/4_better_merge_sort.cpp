#include<bits/stdc++.h>
using namespace std;


//for dividing and merging the arrays to sort them....this one is more flexible for comparators

void divide_and_merge(int arr[], int start, int mid, int end){
    
    int nL,nR;

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

    
}

void merge_sort(int arr[], int start, int end){

    if(start < end){   //base case

        int mid = start + (end - start)/2;

        merge_sort(arr,start, mid);
        merge_sort(arr,mid + 1,end);
        divide_and_merge(arr,start,mid,end);

    }

    //Time Complexity- O(nlog(n)) -best,worst & average case
    //Space Complexity- O(n)
    //T(n) = 2T(n/2) + θ(n)
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
    //scanf("%d",&n);

    cin>>n;

    int arr[n];

    for(i=0;i<n;i++){
        //scanf("%d",&arr[i]);

        cin>>arr[i];
    }

    
    merge_sort(arr,0,n-1);          //officially the fastest sorting algorithm
    

    view_output(arr,n);

    return 0;
}


/*

Q1) Why MergeSort is preferred over QuickSort for Linked Lists ? 

Ans: In case of linked lists the case is different mainly due to difference in memory allocation of arrays and linked lists. Unlike arrays, 
linked list nodes may not be adjacent in memory. Unlike array, in linked list, we can insert items in the middle in O(1) extra space and O(1) time.
Therefore merge operation of merge sort can be implemented without extra space for linked lists.
In arrays, we can do random access as elements are continuous in memory. Let us say we have an integer (4-byte) array A and let the 
address of A[0] be x then to access A[i], we can directly access the memory at (x + i*4). Unlike arrays, we can not do random access in 
linked list. Quick Sort requires a lot of this kind of access. In linked list to access i’th index, we have to travel each and every node 
from the head to i’th node as we don’t have continuous block of memory. Therefore, the overhead increases for quick sort. Merge sort accesses 
data sequentially and the need of random access is low. 

*/