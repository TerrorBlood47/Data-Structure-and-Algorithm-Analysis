#include<bits/stdc++.h>
using namespace std;

class Object{
public:

    int roll ;
    string name;
    int section;

    Object(int roll, string name, int section){
        this->name = name;
        this->roll = roll;
        this->section = section;
    }

    Object(){
        this->name = "";
        this->roll = 0; //roll cannot be less than 1 -> can replace with INT_MIN instead
        this->section = 0;
    }

    Object(int roll){
        this->name = "";
        this->roll = roll; 
        this->section = 0;
    }

    bool equals(Object obj){
        if(this->roll==obj.roll && this->name==obj.name && this->section == obj.section){
            return true;
        }
        else{
            return false;
        }
    }

    
};

class BinarySearchTreeArray{
    int capacity ;
    Object* bt;
    int root;

public:

    BinarySearchTreeArray(int capacity){
        this->capacity = capacity;
        bt = new Object[4*capacity]; //check

        
        root = 0;
    }

private:

void insert(int node, Object x){

    if(bt[node].roll == 0){
        bt[node] = x;
        return ;
    }
    else if(bt[node].roll > x.roll){
        insert(2*node + 1, x );
    }
    else if(bt[node].roll < x.roll){ //dont know what to do with equal values
        insert(2*node + 2, x );
    }
}


void remove(int node, Object x){

    if(node> 4*capacity){
        cout<<"not found"<<endl;
        return;
    }

    if(x.roll < bt[node].roll){
        remove(2*node+1,x);
    }
    else if(x.roll > bt[node].roll){
        remove(2*node+2,x);
    }
    else if(x.roll == bt[node].roll){

        if(x.equals(bt[node])){ //equals works

            //cout<<"2dwdsad"<<endl;
            bt[node] = Object();
            return ;
        }
        else{
            cout<<"not found"<<endl;
            return ;
        }

        // bt[node].roll = 0;
        // bt[node].name = "";
        // bt[node].section = 0;
        //return;
    }
}



int p_height(int node){
    if(bt[node].roll==0){
            return 0;
        }

        int left_subtree_depth = p_height(2*node + 1);
        int right_subtree_depth = p_height(2*node + 2);

        if(left_subtree_depth >= right_subtree_depth){
            return left_subtree_depth + 1;
        }
        else{
            return right_subtree_depth + 1;
        }
}




void PrintPreOrder(int node){

    if(node >= 4*capacity) return;

    if(bt[node].roll != 0) cout<<bt[node].roll<<" ";

    PrintPreOrder(2*node + 1);
    PrintPreOrder(2*node + 2);
}


void PrintInOrder(int node){
    if(node >= 4*capacity) return;
    PrintInOrder(2*node + 1);
    if(bt[node].roll != 0) cout<<bt[node].roll<<" ";
    PrintInOrder(2*node + 2);
}


void PrintPostOrder(int node){
    if(node >= 4*capacity) return;
    PrintPostOrder(2*node + 1);
    PrintPostOrder(2*node + 2);
    if(bt[node].roll != 0) cout<<bt[node].roll<<" ";
}



void printGivenLevel(int node, int level){
    if(bt[node].roll == 0){
        return;
    }
    if(level==1){
        cout<<bt[node].roll<<" ";
        return;
    }
    else if(level > 1){
        printGivenLevel(2*node + 1,level-1);
        printGivenLevel(2*node + 2,level-1);
    }
}

int node_count(int node){
    if(bt[node].roll==0){
        return 0;
    }
    return node_count(2*node + 1) + node_count(2*node + 2) + 1;//check
}



void clearBST(int node){

    if(bt[node].roll==0){
        return ;
    }

    clearBST(2*node + 1);
    clearBST(2*node + 2);

    cout<<"\nReleased node:"<< bt[node].roll;

    bt[node] = Object();
}


bool determineFull(int node){
    if(bt[node].roll==0){
        return true;
    }
    
    if((bt[2*node + 1].roll==0 && bt[2*node + 2].roll != 0) or (bt[2*node + 1].roll==0 && bt[2*node + 2].roll != 0)){
        //cout<<"node of conviction : "<<node->data<<endl;
        return false;
    }
    else{
        //cout<<" going left : "<<node->left->data<<" maybe left isn't right :"<<node->right->data<<endl;
        return determineFull(2*node + 1) and determineFull(2*node + 2);
    }
}

public:
    
    void addNode(Object x){
        insert(root, x);
    }

    void removeNode(Object x){
        remove(0,x);
    }

    void removeNode(int roll){
        remove(0,Object(roll));
    }

    void PreOrder(){
        PrintPreOrder(0);
    }

    void InOrder(){
        PrintInOrder(0);
    }

    void PostOrder(){
        PrintPostOrder(0);
    }

    void print_f(){
        for(int i = 0; i< 4*capacity - 1;i++){
            if(bt[i].equals(Object(0))==false)cout<<bt[i].name<<" "<<bt[i].roll<<" "<<bt[i].section<<endl;
        }
    }

    int height_of_the_tree(){
        return p_height(0);
    }

    void printTheLevel(int level){
        printGivenLevel(0,level);
    }

    int totalNodeCount(){
        return node_count(root);
    }

    void clear(){
        clearBST(0);
    }


    bool isFull(){
        return determineFull(root);
    }


    int get(int i){
        return bt[i].roll;
    }

};


int main(){

BinarySearchTreeArray t = BinarySearchTreeArray(5);

    t.addNode(Object(50,"a",1));
    t.addNode(Object(30,"b",2));
    t.addNode(Object(70,"c",3));
    t.addNode(Object(60,"a",4));
    t.addNode(Object(40,"b",5));
    t.addNode(Object(80,"c",6));
    t.addNode(Object(20,"c",6));

    //t.removeNode(Object(40,"b",5));


    t.print_f();

    //t.PostOrder();

    
    cout<<t.height_of_the_tree()<<endl;

    cout<<t.isFull()<<endl;

    
return 0;
}