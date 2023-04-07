/*
Problem Link  : Aditya Verma - Letter Case Permutation ( https://youtu.be/4eOPYDOiwFo )
About Problem : Recursion implementation
Tags          : 
Notes         : -> Given a string S, we can transform every letter individually to be lowercase or 
                    uppercase to create another string.Return a list of all possible strings we could create.

 */


#include <bits/stdc++.h>
using namespace std;


void letter_case_perm(string in, string out, vector<string>&v){

    if(in.length()==0){
        v.push_back(out);
        return;
    }

    if(isalpha(in[0])){

        string out_1 = out;
        string out_2 = out;

        out_1.push_back(tolower(in[0]));
        out_2.push_back(toupper(in[0]));//toupper = changes small case letters to capital letters

        in.erase(in.begin());
        letter_case_perm(in,out_1,v);
        letter_case_perm(in,out_2,v);

    }
    else{

        out.push_back(in[0]);

        in.erase(in.begin());

        letter_case_perm(in,out,v);
    }

}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    string input;

    cin>>input;

    string output="";

    vector<string>v;

    letter_case_perm(input,output,v);

    for(int i=0;i<v.size();i++){
        cout<<v[i]<<endl;
    }

    return 0;
}