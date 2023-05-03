// LUV series of graphs/trees

#include<bits/stdc++.h>
#include "dynQueue.h"
using namespace std;

class graphNode{

public:
    int data;
    graphNode* next;

    graphNode(int val){
        this->data = val;
        this->next = nullptr;
    }
};

class Graph{
    int num_of_vertices;
    graphNode** vertices;
    

public:

    Graph(int number_of_vertices){
        this->num_of_vertices = number_of_vertices;

        vertices = new graphNode*[num_of_vertices];

        for(int i=0; i<num_of_vertices; i++){
            vertices[i] = new graphNode(i + 1);
        }

        
    }


    void addEdge(int u, int v){

        graphNode* new_node = new graphNode(v);
        graphNode* curr = vertices[u - 1] ;
        while(curr -> next != nullptr){
            curr = curr -> next;
        }
        curr -> next = new_node;


        //the portion below should be commented out for a directed graph
        new_node = new graphNode(u);
        curr = vertices[v - 1] ;
        while(curr -> next != nullptr){
            curr = curr -> next;
        }
        curr -> next = new_node;
    }


    void dfs(bool visited[], int vertex){
        
        //cout<<vertex<<" checking "<<endl;
        if(visited[vertex - 1] == true) return;
        //cout<<vertex<<" check passed "<<endl;
        visited[vertex - 1] = true;
        graphNode* child = vertices[vertex - 1] -> next;

        while(child != nullptr){
            dfs(visited, child->data);
            child = child -> next;
        }
    }

    bool ameliorated_dfs(bool vis[], int vertex, int parent){
        
        vis[vertex - 1] = true;
        //parent = vertex;
        bool isLoop = false;
        graphNode* child = vertices[vertex - 1] -> next;

        while(child != nullptr){
            //cout<<"parent = "<<parent<<" child = "<<child->data<<endl;

            if(vis[(child->data) - 1] == true && (parent==child->data)) {
                child = child -> next;
                continue;
            }

            if(vis[(child->data) - 1] == true && parent!=(child->data) ) {
                //cout<<"bullseye parent = "<<parent<<" child = "<<child->data<<endl;
                return true;
            }
            
            isLoop |= ameliorated_dfs(vis,child->data,vertex);

            child = child -> next;
        }

        return isLoop;
    }

    bool isCycle(){
        
        bool* vis = new bool[num_of_vertices];

        for(int i=0; i<num_of_vertices; i++){
            vis[i] = false;
        }

        bool isLoopExists = false;

        for(int i=0; i<num_of_vertices; i++){
            if(vis[i] == true) continue;
            isLoopExists |= ameliorated_dfs(vis,i+1,-1);
        }

        return isLoopExists;
    }


    void bfs(bool visited[], int source){//only traverses connected components
        Queue_dyn q = Queue_dyn();
        q.enque(source);
        visited[source - 1] = true;

        while(q.isEmpty()==false){

            int current_vertex = q.bottom();
            q.deque();

            graphNode* child = vertices[current_vertex - 1] -> next;
            cout<<current_vertex<<" ";
            while(child != nullptr){

                if(visited[child->data - 1]==false){
                    q.enque(child->data);
                    visited[child->data - 1] = true;
                }

                child = child -> next;
            }

        }

    }


    void printAdjList(){

        for(int i=0; i<num_of_vertices; i++){
            cout<< vertices[i]->data <<" -> ";

            graphNode* j = vertices[i] -> next;

            while(j != nullptr){
                cout<< j->data <<" ";
                j = j->next;
            }

            cout<<endl;
        }
    }

private :



};


int counting_components(Graph g, int n){
    bool* visited = (bool*) calloc(n,sizeof(bool));

    int count = 0;

    for(int i=0; i<n ; i++){
        if(visited[i] == true) continue;
        else{
            g.dfs(visited,i+1);
            count++;
        }
    }

    return count;
}




int main(){

    Graph g = Graph(8);

    g.addEdge(2,3);
    g.addEdge(1,2);
    g.addEdge(3,5);
    g.addEdge(2,4);
    g.addEdge(6,7);
    g.addEdge(6,5);
    g.addEdge(1,4);

    bool* visited = (bool*)calloc(8,sizeof(bool));

    //g.dfs(visited,1);
    
    delete[] visited;

    //cout<<counting_components(g,8)<<endl;

    //cout<<endl<<g.isCycle()<<endl<<endl;

    //g.printAdjList();

    visited = (bool*)calloc(8,sizeof(bool));

    g.bfs(visited,1);//only traverses connected components

return 0;
}