// link -> yt - logic first (https://youtu.be/4jY57Ehc14Y)

#include<bits/stdc++.h>
using namespace std;

void KMP(string txt, string pat){
    int n = txt.size(), m = pat.size();
    int lps[m]; // stores lengths of lps' lps = longest prefix that is equal to suffix

    int i=1, len=0;

    lps[0] = 0;

    while(i<m){

        if(pat[i]==pat[len]){
            lps[i] = len + 1;
            i++;
            len++;
        }
        else{
            if(len != 0){
                len = lps[len-1];
            }
            else{
                lps[i] = len;
                i++;
            }
        }
    }


    i = 0;
    int j = 0;

    while(i<n){

        if(j==m){
            cout<<"index = "<<( i - m )<<endl; //check
            j = lps[j-1];
        }

        if(txt[i] == pat[j]){
            i++;
            j++;
        }
        else{
            if(j != 0){
                j = lps[j-1];
            }
            else{
                i++;
            }
        }

    }

    if(j==m){
        cout<<"index = "<<( i - m )<<endl; ///check
    }


}

int main(){
string txt ;
string pat ;

getline(cin,txt);
getline(cin,pat);

KMP(txt,pat);

return 0;
}