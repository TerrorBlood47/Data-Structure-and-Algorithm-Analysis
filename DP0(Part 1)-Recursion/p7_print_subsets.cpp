/*
Problem Link  : Aditya Verma - Print Subsets ( https://youtu.be/Yg5a2FxU4Fo )
About Problem : Recursion implementation
Tags          : 
Notes         : 

 */

#include <bits/stdc++.h>
using namespace std;

void create_subsets(string inp, string out){

    if(inp.length()==0){
        cout<<out<<endl;
        return;
    }

    string out_1 = out;
    string out_2 = out;

    out_2.push_back(inp[0]);

    inp.erase(inp.begin() + 0);

    create_subsets(inp,out_1);
    create_subsets(inp,out_2);

}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    string input;

    cin>>input;

    string output="";

    create_subsets(input,output);

    return 0;
}