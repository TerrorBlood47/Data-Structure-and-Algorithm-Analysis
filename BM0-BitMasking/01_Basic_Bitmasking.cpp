#include<bits/stdc++.h>
using namespace std;

void printBinary(long long int n){

    if(n>=0){
        for(int i=log2(n); i>=0; i--){

            if((n & (1<<i)) != 0){
                cout<<1;
            }
            else{
                cout<<0;
            }
        }
    }
    else{
        for(int i=31; i>=0; i--){

            if(n & (1<<i)){
                cout<<1;
            }
            else{
                cout<<0;
            }
        }
    }

    cout<<endl;
}


bool isSet(int n, int i){

    if(n & (1<<i)) return true;
    else return false;
}

int Set(int n, int i){

    if(isSet(n,i)){
        return n;
    }
    else{
        n = n | (1<<i);
        return n;
    }
}

int UnSet(int n, int i){

    if(isSet(n,i)==false){
        return n;
    }
    else{
        n = n & ~(1<<i);
        return n;
    }
}

int toggle(int n, int i){// 1 xor 0 = 1, 1 xor 1 = 0
    n = n ^ (1<<i);
    printBinary(n);
    return n;
}

int countSetBits(int n){
    int count = 0;

    for(int i=31; i>=0;i--){

        if(n & (1<<i)) count++;
    }

    return count;
}

bool isEven(int n){ //faster than % 
    if(n & 1) return true;
    else return false;
}

// ">>" - right shift = integer division( 5/2 = 2 not 2.5)
// "<<" - left shift = multiplied by 2

char setLowerCase(char c){
    int a = (int)c;

    int b = Set(a,5);

    return (char)b;
}

char setUpperCase(char c){
    int a = (int)c;

    int b = UnSet(a,5);

    return (char)b;
}

int clearLSB(int n, int i){ //in a single operation

    i = i%32;

    //printBinary(n);
    int a = (~(1<<(i+1))) + 1;
    //cout<<a<<endl;
    //printBinary(a&n);
    return a&n;
}

int clearMSB(int n, int i){ //in a single operation

    i = i%32;
    //printBinary(n);
    int a = (1<<(i+1)) - 1 ;
    //cout<<a<<endl;
    //printBinary(a&n);
    return a&n;
}



int main(){

    // printBinary(3);
    // printBinary(4);

    // cout<<isSet(4,1)<<endl;

    // int n = UnSet(4,2);
    // cout<<n<<endl;

    // n = toggle(4,0);

    // for(char c = 'A'; c<='E'; c++){
    //     cout<<c<<endl;
    //     printBinary(c);
    // }

    // for(char c = 'a'; c<='e'; c++){
    //     cout<<c<<endl;
    //     printBinary(c);
    // }

    clearLSB(59,3);

    clearMSB(59,3);

return 0;
}