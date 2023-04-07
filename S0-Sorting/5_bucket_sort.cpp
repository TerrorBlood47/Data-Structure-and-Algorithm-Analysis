/*
Bucket Sort for numbers having integer part:
Algorithm : 

        1. Find maximum element and minimum of the array
        2. Calculate the range of each bucket
                range = (max - min) / n;
                n is the number of buckets

        3. Create n buckets of calculated range

        4. Scatter the array elements to these buckets
                BucketIndex = ( arr[i] - min ) / range;

        5. Now sort each bucket individually
        6. Gather the sorted elements from buckets to original array


*/


// link - geeksforgeeks 



#include<bits/stdc++.h>
using namespace std;

void swap_array(double *a, double *b){
    double temp = *a;
    *a = *b;
    *b = temp;
}

void insertion_sort(vector<double>&arr, int n){
    int i,j;
    double value;

    for(i=1; i<n ; i++){
        value = arr[i];   
        j = i;            
        bool flag=false;
        while(arr[j-1]>value && j>0){  
            arr[j]=arr[j-1];
            j--;
            flag=true;
        }
        if(flag)arr[j]=value;
    }
    return;
    //Time Complexity- O(n^2)
    //Space Complexity- O(1)
}


void bubble_sort(vector<double>&arr, int n){ //vector does not pass by reference by default, be careful
    int i,j;
    bool flag = true;
    for(i=0;i<n-1 && flag==true ;i++){
        
        flag = false;
                
        for(j=0;j<n-1-i;j++){ 
            if(arr[j]>arr[j+1]){
                swap_array(&arr[j] , &arr[j+1]); //passing by reference is better
                flag = true;
                
            }
        }
    }

    return;
    //Time Complexity- O(n^2)
    //Space Complexity- O(1)
}



void bucketSort(double arr[], int n, double max_element, double min_element, int num_of_buckets){

    // range (for buckets)
    double range = (max_element - min_element)/num_of_buckets;

    vector<vector<double>>temp;

    //create empty buckets
    for(int i=0; i< num_of_buckets; i++){
        temp.push_back(vector<double>()); //check
    }


    // scatter the array elements into the correct bucket
    for(int i=0; i<n; i++){

        double diff = ((arr[i] - min_element)/range) - (int)((arr[i] - min_element)/range);

        // append the boundary elements to the lower array
        if(diff==0 && arr[i]!=min_element){
            temp[(int)((arr[i]-min_element)/range) - 1].push_back(arr[i]);
        }
        else{
            temp[(int)((arr[i]-min_element)/range)].push_back(arr[i]);
        }

    }

    // Sort each bucket individually
    for(int i=0;i<num_of_buckets;i++){
        if(!temp[i].empty()){
            
            //sort(temp[i].begin(),temp[i].end());
            bubble_sort(temp[i],temp[i].size());
            //insertion_sort(temp[i],temp[i].size());
        }
    }

    // Gather sorted elements to the original array

    int k=0;
    for(int i=0;i<num_of_buckets;i++){

        if(temp[i].empty() == false){
            int size = temp[i].size();

            for(int j=0; j<size; j++){
                arr[k] = temp[i][j];
                k++;
            }
        }
    }

    return ;
/*
Time Complexity : best : O(n+k),where n is the number of elements and k is the number of buckets.
                  worst: O(n^n)
Space Complexity : O(n + k) -   This is because we need to create a new array of size k to store the buckets and another array of size n 
                                to store the sorted elements.
Stable algorithm
*/

}




void view_output(double a[], int n){
    int i;

    for(i=0;i<n;i++)printf("%g ",a[i]); //%g = to print without trailing zeroes

    cout<<endl;
    return;
}



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,i;
    scanf("%d",&n);

    double arr[n];

    double max,min;

    for(i=0;i<n;i++){
        scanf("%lf",&arr[i]);

        if(i==0){
            max = arr[0];
            min = arr[0];
        }

        if(i>0 && max<arr[i]){
            max = arr[i];
        }

        if(i>0 && min>arr[i]){
            min = arr[i];
        }

    }

    int num_of_buckets = 10;

    bucketSort(arr,n,max,min,num_of_buckets); //good for doubles array sorting because of precision, works for both neg and non-neg int
                                            //and floating point numbers

    view_output(arr,n);

    return 0;
}