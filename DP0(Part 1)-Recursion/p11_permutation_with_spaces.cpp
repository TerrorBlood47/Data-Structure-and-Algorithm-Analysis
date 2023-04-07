/*
Problem Link  : Aditya Verma - Permutation with spaces ( https://youtu.be/1cspuQ6qHW0 )
About Problem : Recursion implementation
Tags          : 
Notes         : 

 */

//////problem ase
#include <bits/stdc++.h>
using namespace std;

void permutation_with_spaces(string in, string out){

    if(in.length()==0){
        cout<<out<<endl;
        return;
    }

    string out_1 = out;
    string out_2 = out;
    out_1.push_back(in[0]);
    out_2.push_back(in[0]);
    out_2.push_back(' ');

    in.erase(in.begin());

    permutation_with_spaces(in , out_1);
    permutation_with_spaces(in , out_2);

}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    string input;

    cin>>input;

    string output="";

    permutation_with_spaces(input,output);

    return 0;
}