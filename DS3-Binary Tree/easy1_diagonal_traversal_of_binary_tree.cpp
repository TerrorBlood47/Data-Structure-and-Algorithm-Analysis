
//pore korbo - g4g - bt

#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* left; //left_child
    Node* right;  // right_child

    Node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

class BinarySearchTree{
public: 

    Node* root;

    BinarySearchTree(){
        root = NULL;
    }

private: 

    Node* p_insert(Node* parent, int val){
        if(parent==NULL){
            parent = new Node(val);
            return parent;
        }
        if(val < parent->data){ // <= ??
            parent->left = p_insert(parent->left,val);
        }
        else{
            parent->right = p_insert(parent->right,val);
        }
        return parent;
    }









    Node* findMinNode(Node* node){
        Node* curr = node;

        while(curr && curr->left!=NULL){
            curr = curr->left ;
        }

        return curr;
    }


    Node* remove(Node* node, int val){
        
        if(node == NULL){
            return node;
        }

        if(val < node->data){
            node->left = remove(node->left,val);
        }
        else if(val > node->data){
            node->right = remove(node->right,val);
        }
        else{

            if(node->left==NULL && node->right==NULL){
                free(node);
                return NULL;
            }
            else if(node->left!=NULL && node->right==NULL){//node with only left child
                Node* temp = node->left;
                free(node);
                return temp;
            }
            else if(node->left==NULL && node->right!=NULL){//node with only right child
                Node* temp = node->right;
                free(node);
                return temp;
            }

            //nodes with two children
            Node* temp = findMinNode(node->right);
            node->data = temp->data;

            node->right = remove(node->right,temp->data);

        }

        return node; //to make connection
    }













    void PreOrder(Node* curr_node){
        if(curr_node==NULL){
            return;
        }
        cout<<curr_node->data<<" ";
        PreOrder(curr_node->left);
        PreOrder(curr_node->right);
    }


    void InOrder(Node* curr_node){

        if(curr_node==NULL){
            return;
        }
        InOrder(curr_node->left);

        cout<<curr_node->data<<" ";
        InOrder(curr_node->right);
    }


    void PostOrder(Node* curr_node){
        if(curr_node==NULL){
            return;
        }
        PostOrder(curr_node->left);
        PostOrder(curr_node->right);

        cout<<curr_node->data<<" ";
    }

    int p_height(Node* node){

        if(node == NULL){
            return 0;
        }

        int left_subtree_depth = p_height(node->left);
        int right_subtree_depth = p_height(node->right);

        if(left_subtree_depth >= right_subtree_depth){
            return left_subtree_depth + 1;
        }
        else{
            return right_subtree_depth + 1;
        }
    }

    void printGivenLevel(Node* node, int level){
        if(node==NULL){
            return;
        }
        if(level==1){
            cout<<node->data<<" ";
            return;
        }
        else if(level > 1){
            printGivenLevel(node->left,level-1);
            printGivenLevel(node->right,level-1);
        }
    }

void printLeafNodes(Node* node){

    if(node==NULL){
        return;
    }

    if(node->left==NULL && node->right==NULL){
        cout<<node->data<<" ";
        return;
    }
    else{
        printLeafNodes(node->left);
        printLeafNodes(node->right);
    }
}

void print_NonLeafNodes(Node* node){
    if(node==NULL){
        return;
    }
    if(node->left!=NULL || node->right!=NULL){
        cout<<node->data<<" ";
        
        print_NonLeafNodes(node->left);
        print_NonLeafNodes(node->right);
    }
}


int node_count(Node* node){

    if(node==NULL){
        return 0;
    }

    return node_count(node->left) + node_count(node->right) + 1;//check
}


Node* clearBST(Node* node){

    if(node==NULL){
        return NULL;
    }

    clearBST(node->left);
    clearBST(node->right);

    cout<<"\nReleased node:"<< node->data;

    Node* temp = node;
    free(temp);
    node=NULL;
    return node;
}


int p_search(Node* node, int val){

    if(node == NULL){ //this needs to come above all as it might be nullptr
        return -1;
    }

    if(node->data == val){
        return 1;
    }

    if(val< node->data){
        return p_search(node->left,val);
    }
    else if(val>node->data){
        return p_search(node->right,val);
    }
}




public:

    void addNode(int val){
        root = p_insert(root,val);
    }

    void deleteNode(int value){
        root = remove(root,value);
    }

    void printPreOrder(){//prints in order of the input provided - hence used to copy the tree
        PreOrder(root);
    }

    void printInOrder(){//prints nodes in non-decreasing order
        InOrder(root);
    }

    void printPostOrder(){//prints in reverse order of the input provided - hence used to delete the tree
        PostOrder(root);
    }

    int height_of_the_tree(){
        return p_height(root);
    }

    void printTheLevel(int level){
        printGivenLevel(root,level);
    }

    void print_All_Leaf_Nodes(){
        printLeafNodes(root);
    }

    void print_All_NonLeaf_Nodes(){
        print_NonLeafNodes(root);
    }

    int minValue(){
        Node* curr = root;
        if(root==NULL){
            cout<<"Empty tree"<<endl;
            return INT_MIN;
        }
        while(root!=NULL && curr->left!=NULL){
            curr = curr->left;
        }
        return curr->data;
    }

    int totalNodeCount(){
        return node_count(root);
    }

    void clear(){
        root = clearBST(root);
    }

    int search(int val){
        return p_search(root,val);
    }

};





int main(){

    BinarySearchTree t  = BinarySearchTree();

    t.addNode(50);
    t.addNode(30);
    t.addNode(20);
    t.addNode(40);
    t.addNode(70);
    t.addNode(60);
    t.addNode(80);
    t.addNode(10);
    t.addNode(100);

    

    

    return 0;
}