#include<bits/stdc++.h>
using namespace std;

//all are sorted in non-decreasing order

void swap_array(int *a , int *b){
    int temp=*a;
    *a = *b;
    *b = temp;

    return;
}

void bubble_sort(int arr[], int n){
    //repeatedly swap two adjacent elements if they are in wrong order, takes the max value to the rightmost part in the 1st loop

    //(a) link : https://youtu.be/Jdtq5uKz-w4      //youtube: mycodeschool


    int i,j;
    bool flag = true;
    for(i=0;i<n-1 && flag==true ;i++){
        
        flag = false;// if checking/traversing the array requires no swapping, then it means the array is already sorted.....
                     //then the sorting will be stopped immediately
        
                
        for(j=0;j<n-1-i;j++){ //checks out the condition for the 2nd loop for faster output & avoid unnecessary 
                              //repetition of the sorted part at hand
            
            
            if(arr[j]>arr[j+1]){
                swap_array(&arr[j] , &arr[j+1]);
                flag = true;
                
            }
        }

        
    }

    return;
    //Time Complexity- O(n^2)
    //Space Complexity- O(1)
    //Stable sorting algorithm
}




void selection_sort(int arr[], int n){
    //Find the minimum element in unsorted array and swap it with element at beginning
    int i,j;

    for(i=0;i<n-1;i++){
        for(j=i+1;j<n;j++){
            if(arr[i]>arr[j]){
                swap_array(&arr[i],&arr[j]);
            }
        }
    }
    return;
    //Time Complexity- O(n^2) =BEST AND AVERAGE CASE
    //Space Complexity- O(1)
    //Unstable sorting algorithm
}



void insertion_sort(int arr[], int n){
    //(a) link : https://youtu.be/i-SKeOcBwko      //youtube: mycodeschool

    int i,j,value;

    for(i=1; i<n ; i++){
        value = arr[i];   //take the new value of argument
        j = i;            //mark the position of the value
        bool flag=false;
        while(arr[j-1]>value && j>0){   //shift the elements right until the it is not greater than the value, it is already in optimized form
            arr[j]=arr[j-1];
            j--;
            flag=true;
        }
        if(flag)arr[j]=value;
    }
    return;
    //Time Complexity- O(n^2)
    //Space Complexity- O(1)
    //Stable sorting algorithm
    /*
    Insertion sort takes maximum time to sort if elements are sorted in reverse order. And it takes 
    minimum time (Order of n) when elements are already sorted. 
    */
}




//for merging the fractionated arrays
void merge(int l[], int r[], int a[], int n){
    int i=0,j=0,k=0,mid,nL,nR;

    mid = n/2;
    nL = mid ; // (mid+1) does not work
    nR = n-nL;

    while(i<nL && j<nR){

    if(l[i]<=r[j]){
        a[k]=l[i];
        k++;
        i++;
    }
    else{
        a[k]=r[j];
        k++;
        j++;
    }

}

while(i<nL){
    a[k]=l[i];
    i++;
    k++;
}

while(j<nR){
    a[k]=r[j];
    j++;
    k++;
}

    return;
}

void merge_sort(int arr[], int n){

    int i,j,k,mid,nL,nR;

    if(n<2)return;

    mid = n/2;
    nL = mid ; // (mid+1) does not work
    nR = n-nL;

    int left[nL];
    int right[nR];

    for(i=0;i<mid;i++){ // check thr conditions
        left[i]=arr[i];
    }

    for(i=mid;i<n;i++){  // check the conditions 
        right[i-mid]=arr[i];
    }

    merge_sort(left,nL);
    merge_sort(right,nR);
    merge(left,right,arr,n);

    return;

    //Time Complexity- O(nlog(n))
    //Space Complexity- O(n)
    //Stable sorting algorithm
}






// a non-comparison based algorithm, works for non-negative integers only
void counting_sort(int arr[], int n){
    //(a) link : youtube: Farhan Hossan

    int i,j,count[100006]={0},max=-1;   //1e5+6 ,1e6 or more does not work,max from 0 is for the range of count array which is relevant for the operation
    int output[n];     //for storing the sorted array

    for(i=0;i<n;i++){
        count[arr[i]]++;
        if(arr[i]>max)max=arr[i];
    }

    for(i=1;i<=max;i++){
        count[i] = count[i] + count[i-1]; //for positioning the values in the correct sorted way
        
    }

    for(i=n-1;i>=0;i--){
        output[--count[arr[i]]] = arr[i]; //--count[arr[i]] is important because an element must be allocated at place with index=10 for array with size 11,
                                          //so checking out the cumulated count array, we take the cumulated frequency of the element and subtract 1 from it,
                                          //which produces position for the element in resultant/output array
    }
    
    for(i=0;i<n;i++){
        arr[i] = output[i];
    }

    return ;
    //Time Complexity- O(n + k)
    //Space Complexity- O(k) where k= effective size of the count array
    //Stable sorting algorithm
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

    //bubble_sort(arr,n);       
    //selection_sort(arr,n);  
    //insertion_sort(arr,n);
    //merge_sort(arr,n);          //officially the fastest sorting algorithm
    counting_sort(arr,n);         //only works for non-negative values afaik...implementation for negative values is suggested for future exercise
    

    view_output(arr,n);

    return 0;
}