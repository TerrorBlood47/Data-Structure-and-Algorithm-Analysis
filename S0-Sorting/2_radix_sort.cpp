#include<bits/stdc++.h>
using namespace std;

//all are sorted in non-decreasing order

void view_output(int a[], int n){
    int i;

    for(i=0;i<n;i++)printf("%d ",a[i]);

    cout<<endl;
    return;
}

int get_max(int a[], int n){
    int i,m=0;

    for(i=0;i<n;i++){

        if(m<a[i])m=a[i];

    }

    return m;
}


void modified_count_sort(int a[], int n, int pos){
    int i,j;
    int count[10]={0};//check
    int output[n]; //temporary output array

    for(i=0;i<n;i++){
        int k = (a[i]/pos)%10;
        count[k]++;
    }

    for(i=1;i<10;i++){
        count[i] = count[i] + count[i-1];
    }

    for(i=n-1;i>=0;i--){    // this needs to be iterated from (n-1)th to 0th index, otherwise it creates error   
        int k = (a[i]/pos)%10;
        --count[k];
        output[count[k]] = a[i];
    }

    for(i=0;i<n;i++){
        a[i] = output[i];
    }

    return ;
}

//a non-comparison based algorithm
void radix_sort(int a[], int n){
    //(a) link : youtube: Farhan Hossan
    int pos;

    int max = get_max(a,n);

    for(pos = 1 ; (max/pos) > 0; pos= pos*10){ ///another way to write the condition : max >= pos
        modified_count_sort(a,n,pos);
        //view_output(a,n);
    }
    
    return;

    //Time Complexity- O((log10(max)+1)*(n + k))
    //Space Complexity- O(k) where k= effective size of the count array(k=10 here)
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

    radix_sort(arr,n);
    

    view_output(arr,n);

    return 0;
}