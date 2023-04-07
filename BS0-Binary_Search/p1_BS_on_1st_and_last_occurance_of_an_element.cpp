/*
Problem Link     : Aditya Verma - 5 First and Last occurrence of an Element( https://youtu.be/zr_AoTxzn0Y )
About Problem    : Implementation of Binary Search on an array where an element occurs more than once 
Tags             :
Notes            :Instead of returning the index(mid), continue the search to ensure it is the 1st occurrence of the element or not

*/


#include<bits/stdc++.h>
using namespace std;


int binary_search_first_occurrence_of_an_element(vector<int>a, int n, int k){
    int i=0,j=n-1,mid=i+(j-i)/2,res=-1;

    while(i<=j){
        mid=i+(j-i)/2;
        if(k==a[mid]){  //Instead of returning mid,the process must continue to search the last occurrence of the desired element.
                        //if mid is found which satisfies the condition,we must search the sub-array left to the position of mid......
                        //if no element is found with the same value, then it is the ans.....otherwise the process continues... 
            res = mid;
            j=mid-1;
        }
        else if(k<a[mid])j=mid-1;
        else  i=mid+1;
    }

    return res;
}

int binary_search_last_occurrence_of_an_element(vector<int>a, int n, int k){
    int i=0,j=n-1,mid=i+(j-i)/2,res=-1;

    while(i<=j){
        mid=i+(j-i)/2;
        if(k==a[mid]){  //Instead of returning mid,the process must continue to search the last occurrence of the desired element.
                        //if mid is found which satisfies the condition,we must search the sub-array right to the position of mid......
                        //if no element is found with the same value, then it is the ans.....otherwise the process continues... 
            res = mid;
            i=mid+1;
        }
        else if(k<a[mid])j=mid-1;
        else  i=mid+1;
    }

    return res;
}




int main(){
    int index,i,j,n,k;

    vector<int>a;

    cin>>k>>n;

    for(i=0;i<n;i++){
        int x;
        cin>>x;
        a.push_back(x);
    }

    //index = binary_search_first_occurrence_of_an_element(a,n,k);
    index = binary_search_last_occurrence_of_an_element(a,n,k);    


    if(index>=0)cout<<index<<endl;
    else cout<<"not found\n";

    return 0;
}