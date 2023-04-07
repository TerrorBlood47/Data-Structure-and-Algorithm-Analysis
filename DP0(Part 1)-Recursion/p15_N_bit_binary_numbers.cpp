/*
Problem Link  : Aditya Verma - Print N-bit binary numbers having more 1’s than 0’s for any prefix ( https://youtu.be/U81n0UYtk98 )
About Problem : Recursion implementation
Tags          : 
Notes         : Given a positive integer N, print all N bit binary numbers having more 1’s than 0’s for any prefix of 
                the number.

Input:
t = 2
2
3
Output:
11 10
111 110 101 . 

 */


#include <bits/stdc++.h>
using namespace std;

void prefix_creation(vector<string>&v, string output, int ones, int zeroes, int n){

    if(ones + zeroes == n){
        v.push_back(output);
        return;
    }


    if(ones==1 && zeroes==0){
        string output_1 = output;
        string output_2 = output;

        output_1.push_back('1');
        output_2.push_back('0');

        prefix_creation(v,output_1,ones+1,zeroes,n);
        prefix_creation(v,output_2,ones,zeroes + 1,n);
    }
    else if(ones> zeroes + 1){
        string output_1 = output;
        string output_2 = output;

        output_1.push_back('1');
        output_2.push_back('0');

        prefix_creation(v,output_1,ones + 1,zeroes,n);
        prefix_creation(v,output_2,ones,zeroes + 1,n);
    }
    else{
        output.push_back('1');
        prefix_creation(v,output,ones+1,zeroes,n);
    }

}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;

    cin>>n;

    string output="";

    vector<string>v;

    prefix_creation(v,output,0,0,n);

    
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<endl;
    }

    return 0;
}