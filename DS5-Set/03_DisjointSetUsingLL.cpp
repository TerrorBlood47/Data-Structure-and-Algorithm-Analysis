#include<bits/stdc++.h>
using namespace std;

class DisjointSetNode{
public:
    int data;
    DisjointSetNode* parent;

    DisjointSetNode(){

    }

    DisjointSetNode(int val){
        this->data = val;
        this->parent = this; //check
    }
};

class VectorNode{
public:
    VectorNode* next;
    DisjointSetNode* node;

    VectorNode(DisjointSetNode* node){
        this->node = node;
        this->next = nullptr;
    }
};

class VectorLL{
public:
    VectorNode* root;
    int size;

    VectorLL(){
        root = nullptr;
        size = 0;
    }

    void insertNew(DisjointSetNode* newNode){

        if(root == nullptr){
            root = new VectorNode(newNode);
            root->next = nullptr;
            size++;
            return;
        }

        VectorNode*  curr = root;

        while(curr->next != nullptr){
            curr = curr -> next;
        }

        curr->next = new VectorNode(newNode);
        curr->next->next = nullptr;
        size++;
    }

    void CreateVector(int given_size){ //makeSet()

    }

    VectorNode* get(DisjointSetNode* Node){
        VectorNode* curr = root;

        while(curr != nullptr){

            if(curr->node->data == Node->data){
                return curr;
            }
            curr = curr->next;
        }

        return nullptr;
    }

    void print(){
        VectorNode* curr = root;
        while(curr != nullptr){
            cout<<"val = "<<curr->node->data<<" parent = "<<curr->node->parent->data<<endl;
            curr = curr->next;
        }
    }
};

class DisjointSetLL{
    VectorLL v;
public:
    DisjointSetLL(int size){
        makeSet(size);
    }

    void makeSet(int size){
        for(int i=1; i<=size; i++){
            v.insertNew(new DisjointSetNode(i));
        }
    }

    VectorNode* find(DisjointSetNode* Node){
        VectorNode* i = v.get(Node);
        if(i->node->data == i->node->parent->data){
            return i;
        }

        return find(i->node->parent);
    }

    void unite(int a, int b){
        VectorNode* i_rep = find(new DisjointSetNode(a));
        VectorNode* j_rep = find(new DisjointSetNode(b));

        if(i_rep == j_rep) return ;
        else{
            j_rep->node->parent = i_rep->node;
        }
    }

    void printSet(){
        v.print();
    }

};

int main(){

DisjointSetLL s  = DisjointSetLL(10);

s.unite(1,3);
s.unite(1,4);

s.printSet();


return 0;
}