/*
Problem Link     : Aditya Verma - 12 Next Alphabetical Element( https://youtu.be/X45c37QMdX0 )
About Problem    : Implementation of Binary Search to find Next Alphabetical Element
Tags             :
Notes            : 
*/


#include<bits/stdc++.h>
using namespace std;


int binary_search_ceil_on_alphabet(vector<char>c, int n, char k){
    int i=0,j=n-1,mid=i+(j-i)/2; char res=-1;

    while(i<=j){
        mid=i+(j-i)/2;
        if(k>=c[mid]){
            i = mid + 1;
        }   
        else{
            j = mid - 1;
            res = c[mid];// if the mid is greater than the element than we will store it.....the goal is to find the element with the smallest value 
        }                 // which is larger than the searched element
    }
    

    return res;
}



int main(){
    int i,j,n;
    char ceil_on_alphabet, k;

    vector<char>a;

    cin>>k>>n;

    for(i=0;i<n;i++){
        char x;
        cin>>x;
        a.push_back(x);
    }

    ceil_on_alphabet = binary_search_ceil_on_alphabet(a,n,k);

    if(ceil_on_alphabet>=0)cout<<ceil_on_alphabet<<endl;
    else cout<<"not found\n";

    return 0;
}