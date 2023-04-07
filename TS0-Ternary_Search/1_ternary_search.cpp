/*
Problem Link  : Ternary Search Basic-Pepcoding (https://youtu.be/kch3MpnylB8) + Code Wagon(https://youtu.be/WyWL1PBNvb8)
About Problem : Ternary Search Implementation
Tags          : 
Notes         : -> used for unimodal(having one max or min) cases/functions(binary search is used for functions which is 
                    strictly increasing)
        
 */


#include<bits/stdc++.h>
using namespace std;

int Ternary_search(int a[], int n, int k){
    int right,left,mid_1,mid_2;

    left = 0;
    right = n-1;

    while(left <= right){
        mid_1 = left + (right - left)/3; //check
        mid_2= right + (right - left)/3; //check

        if(a[mid_1]==k){
            return mid_1;
        }
        else if(a[mid_2]==k){
            return mid_2;
        }
        else if(k < a[mid_1]){
            right = mid_1 - 1;
        }
        else if(a[mid_1]<k && k<a[mid_2]){
            left = mid_1 + 1;
            right = mid_2 - 1;
        }
        else if(a[mid_2]>k){
            left = mid_2 + 1;
        }
    }

    return -1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,i,key;
    scanf("%d%d",&n,&key);

    int arr[n];

    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    int ind = Ternary_search(arr,n,key);
    cout<<ind<<endl;
    
    return 0;
/*
    Time Complexity - a bit greater than binary search 

*/
}