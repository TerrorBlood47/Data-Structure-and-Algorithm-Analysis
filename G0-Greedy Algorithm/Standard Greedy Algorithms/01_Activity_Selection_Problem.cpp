//g4g - Activity Selection Problem

#include<bits/stdc++.h>
using namespace std;

void printMaxActivities(int start[], int finish[], int n){

    for(int i=0; i<n; i++){

        cout<<i<<" ";

        bool found = false;

        for(int j=i+1; j<n; j++){

            if(start[j]>=finish[i]){
                i = j-1;
                found = true;
                break;
            }
        }

        if(found==false) break;
    }
}


void bubble_sort(int start[], int finish[], int n){

    int i,j;

    for(i=0;i<n;i++){
        for(int j=0; j<n-1 ;j++){

            if(finish[j] > finish[j+1]){
                swap(finish[j], finish[j+1]);
                swap(start[j],start[j+1]);
            }
        }
    }
}

int main(){

int n;
cin>>n;
int start[n], finish[n];

for(int i=0;i<n;i++){
    int s,f;
    cin>>s>>f;
    start[i] = s;
    finish[i] = f;
}

bubble_sort(start,finish,n);


// for(int i=0;i<n;i++){
   
//    cout<<start[i]<<" "<<finish[i]<<endl;
// }

printMaxActivities(start,finish,n);


return 0;
}