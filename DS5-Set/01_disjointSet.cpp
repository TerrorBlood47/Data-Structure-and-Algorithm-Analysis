#include<bits/stdc++.h>
using namespace std;

class DisjointSet{
    int *parent,n;

    void makeSet(int n){
        for(int i=0; i< n;i++){
            parent[i] = i;//all elements are representatives of themselves
        }
    }

public:
    DisjointSet(int n){
        this->n = n;
        parent = new int[n];
        makeSet(n);
    }

    int findParent(int x){ //finds representative of the set where the element belongs 
        if(parent[x]==x){
            return x;
        }

        return findParent(parent[x]);
    }

    void Union(int x, int y){
        
        int x_representative = findParent(x);
        int y_representative = findParent(y);

        if(x_representative == y_representative) return;
        else{
            parent[y_representative] = x_representative;
        }

    }
};

int main(){

return 0;
}