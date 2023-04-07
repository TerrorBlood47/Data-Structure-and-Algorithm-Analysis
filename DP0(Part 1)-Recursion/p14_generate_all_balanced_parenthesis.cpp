/*
Problem Link  : Aditya Verma - Generate all Balanced Parentheses ( https://youtu.be/eyCj_u3PoJE )
About Problem : Recursion implementation
Tags          : 
Notes         : 

 */


#include <bits/stdc++.h>
using namespace std;

void balanced_parentheses(vector<string>&v,string output, int open_brackets,int close_brackets){

    if(open_brackets==0 && close_brackets==0){ //Base case
        v.push_back(output);
        
        return;
    }


    if(open_brackets==0){ //choice of open brackets is always available
        output.push_back(')');
        balanced_parentheses(v,output,open_brackets,close_brackets-1);

    }
    else if(open_brackets < close_brackets && open_brackets!=0){ //choice of close brackets are only available when
                                                                //there is at least one open bracket exists to the left of it
        string output_1 = output;
        output_1.push_back('(');
        string output_2 = output;
        output_2.push_back(')');

        balanced_parentheses(v,output_1,open_brackets-1,close_brackets);
        balanced_parentheses(v,output_2,open_brackets,close_brackets-1);
    }
    else{
        output.push_back('(');
        balanced_parentheses(v,output,open_brackets-1,close_brackets);
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

    balanced_parentheses(v,output,n,n);


    for(int i=0;i<v.size();i++){
        cout<<v[i]<<endl;
    }

    return 0;
}