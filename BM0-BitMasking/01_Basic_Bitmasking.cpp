#include<bits/stdc++.h>
using namespace std;

void printBinary(int n){

    for(int i=ceil(log(n)); i>=0; i--){

        if(n & (1<<i)){
            cout<<1;
        }
        else{
            cout<<0;
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


int main(){

    printBinary(3);
    printBinary(4);

    cout<<isSet(4,1)<<endl;

    int n = UnSet(4,2);
    cout<<n<<endl;

    n = toggle(4,0);

return 0;
}