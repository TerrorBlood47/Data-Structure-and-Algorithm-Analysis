#include<bits/stdc++.h>
using namespace std;



void counting_sort_for_only_pos(int arr[], int n,int max){
    
    int i,j,count[max + 1]={0};   
    int output[n];    
    for(i=0;i<n;i++){
        count[arr[i]]++;
    }

    for(i=1;i<=max;i++){
        count[i] = count[i] + count[i-1]; 
        
    }

    for(i=n-1;i>=0;i--){
        output[--count[arr[i]]] = arr[i]; 
    }
    
    for(i=0;i<n;i++){
        arr[i] = output[i];
    }

    return ;
    
}




void counting_sort_for_both_pos_and_neg(int arr[], int n,int max,int min){
    
    int range = max - min + 1; // range
    int i,j,count[range]={0};   
    int output[n];
    
    for(i=0;i<n;i++){
        count[arr[i] - min]++;
    }

    for(i=1;i<range;i++){
        count[i] = count[i] + count[i-1]; 
        
    }

    //cout<<max<<" "<<min<<endl;

    for(i=n-1;i>=0;i--){
        output[--count[arr[i] - min]] = arr[i]; 
    }
    
    for(i=0;i<n;i++){
        arr[i] = output[i];
    }

    return ;
    
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

    int arr[n],min,max;
    bool neg_element_exists = false;

    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);

        if(i==0){
            max = arr[i];
            min = arr[i];
        }

        if(i>0 && arr[i]>max){
            max = arr[i];
        }

        if(i>0 && arr[i]<min){
            min = arr[i];
        }

        if(arr[i]<0){
            neg_element_exists = true;
        }
    }


    if(neg_element_exists)counting_sort_for_both_pos_and_neg(arr,n,max,min); 
    else  counting_sort_for_only_pos(arr,n,max);       
    

    
    view_output(arr,n);

    return 0;
}