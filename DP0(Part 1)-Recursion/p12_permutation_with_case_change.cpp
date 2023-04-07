/*
Problem Link  : Aditya Verma - Permutation with Case Change ( https://youtu.be/J2Er5XceU_I )
About Problem : Recursion implementation
Tags          : 
Notes         : ->Print all permutations of a string keeping the sequence but changing cases.

 */


#include <bits/stdc++.h>
using namespace std;


void permutation_with_Case_change(string in, string out){

    if(in.length()==0){
        cout<<out<<endl;
        return;
    }

    string out_1 = out;
    string out_2 = out;
    out_1.push_back(in[0]);
    out_2.push_back(toupper(in[0]));//toupper = changes small case letters to capital letters

    in.erase(in.begin());

    permutation_with_Case_change(in,out_1);
    permutation_with_Case_change(in,out_2);

}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    string input;

    cin>>input;

    

    string output="";

    permutation_with_Case_change(input,output);

    return 0;
}