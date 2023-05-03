#include<bits/stdc++.h>
using namespace std;

class DisjointSet{
    int *parent, *rank, n;

    void makeSet(){

        //cout<<n<<endl;

        for(int i=0; i<n; i++){
            parent[i] = i;
            rank[i] = -1;
        }
    }

public:
    DisjointSet(int n){
        this->n = n;
        parent = new int[n];
        rank = new int[n];
        makeSet();
    }

    int find(int i){

        if(parent[i] == i){
            return i;
        }
        else{

            int res = find(parent[i]);

            parent[i] = res;

            return res;
        }
    }

    void Union(int i, int j){

        int i_rep = find(i);
        
        int j_rep = find(j);

        //cout<<i_rep<<" "<<j_rep<<endl;
        //cout<<rank[i_rep]<<" "<<rank[j_rep]<<endl;

        if(i_rep == j_rep) return;
        else{

            if(abs(rank[i_rep]) >= abs(rank[j_rep])){
                //cout<<"das"<<endl;
                parent[j_rep] = i_rep;
                rank[i_rep] += rank[j_rep];
            }
            else{
                parent[i_rep] = j_rep;
                rank[j_rep] += rank[i_rep];
            }
        }
    }
};

int main(){

    DisjointSet d = DisjointSet(10);

    d.Union(0,2);
    d.Union(2,4);

    for(int i =0; i< 10; i++){
        cout<<"i = "<<i<<" parent = "<<d.find(i)<<endl;
    }

return 0;
}