

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

class BinaryTree{
public:
    Node* root;

    BinaryTree(){
        root = NULL;
    }

    void addNode(int data){
        Node* new_node = new Node(data);
        if(root==NULL){
            root = new_node;
            return;
        }
        else{
            Node* curr = root;
            Node* curr_parent;

            while(47){
                curr_parent = curr;

                if(data < curr->data){
                    curr = curr->left;

                    if(curr==NULL){
                        curr_parent->left = new_node;
                        return;
                    }
                }
                else{
                    curr = curr->right;
                    if(curr==NULL){
                        curr_parent->right = new_node;
                        return;
                    }
                }
            }
        }
    }


    void printPreOrder(Node* node){

        if(node==NULL){
            return;
        }

        cout<<node->data<<" ";

        printPreOrder(node->left);
        printPreOrder(node->right);
    }


    void printInOrder(Node* node){

        if(node==NULL){
            return;
        }

        printInOrder(node->left);
        cout<<node->data<<" ";
        printInOrder(node->right);
    }

    void printPostOrder(Node* node){

        if(node==NULL){
            return;
        }

        printPostOrder(node->left);
        printPostOrder(node->right);
    
        cout<<node->data<<" ";

    }

    

};


int main(){

    BinaryTree t = BinaryTree();
    t.addNode(1);
    t.addNode(2);
    t.addNode(3);
    t.addNode(4);
    t.addNode(5);
    t.addNode(6);

    t.printPreOrder(t.root);
    cout<<endl;
    t.printInOrder(t.root);
    cout<<endl;
    t.printPostOrder(t.root);

    return 0;
}