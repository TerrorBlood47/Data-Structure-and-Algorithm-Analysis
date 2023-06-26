//link - g4g 


#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

ll q = 47; // a prime number
ll d = 256;

void RubinKarp(string txt, string pat){

    int n = txt.size();
    int m = pat.size();

    //cout<<n<<" "<<m<<endl;
    

    ll h = 1;

    ll t = 0; // hash value of the substring of txt
    ll p = 0; // hash value of the pattern


    // h = pow(d, m-1) % q
    for(int i=1; i<=m - 1; i++){
        h = (h*d) % q;
    }

    //cout<<h<<endl;

    for(int i=0; i<=m-1; i++){
        t = (d*t + txt[i]) % q;
        p = (d*p + pat[i]) % q;
    }

    //cout<<t<<" "<<p<<endl;

    int i=0, j=0;

    while( i<(n-m+1)){

        if(t == p){
            //cout<<"i = "<<i<<endl;
            int a = i, b = j;
            while(b<m){

                if(txt[a] != pat[b]){
                    break;
                }
                a++;
                b++;
            }

            if(b==m){
                cout<<"pattern found at index = "<<i<<endl;
            }
        }

        t = (d*(t - h*txt[i]) + 1*txt[i+m]) % q;
        
        i++;

        if(t<0) t = t+q;
    }

}

int main(){

string txt, pat;

getline(cin,txt);
getline(cin,pat);


RubinKarp(txt,pat);


return 0;
}