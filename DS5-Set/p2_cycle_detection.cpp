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

bool has_cycle(vector<pair<int,int>> &edges,int size){

    DisjointSet s = DisjointSet(size+1);

    for(int i=0; i<edges.size(); i++){

        int u = edges[i].first;
        int v = edges[i].second;

        int u_rep = s.find(u);
        int v_rep = s.find(v);

        if(u_rep == v_rep) return true;

        s.Union(u,v);
    }

    return false;
}

int main(){

    vector<pair<int, int>> edges = {{1,2},{2,4}, {4,3}, {3,6},{2,3}};
    int size = 6;

    if(has_cycle(edges,size)) cout<<"cycle exists"<<endl;
    else cout<<"no cycle exists"<<endl;

return 0;
}