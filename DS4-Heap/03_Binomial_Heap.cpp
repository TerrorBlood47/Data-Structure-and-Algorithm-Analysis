#include<bits/stdc++.h>
using namespace std;

class BinomialTreeNode{
public: 
    BinomialTreeNode* parent; // ptr to parent , null for root
    int data;
    int degree;//number of children
    BinomialTreeNode* leftmost_child;
    BinomialTreeNode* right_sibling;

    BinomialTreeNode(int data){
        this->parent = nullptr;
        this->data = data;
        this->degree = 0;
        this->leftmost_child = nullptr;
        this->right_sibling = nullptr;
    }

    ~BinomialTreeNode(){};// a destructor
    /*
    ~BinomialTreeNode(){} is a destructor for the Node class. It's used to perform cleanup operations when a Node object is destroyed, such as 
    releasing any dynamically allocated memory associated with the object.

    In this case, the destructor is empty, which means it doesn't do anything. This is because the Node class doesn't have any 
    dynamically allocated memory that needs to be released explicitly. However, if you had added any dynamic memory allocation 
    in the Node class, you would need to free it in the destructor to prevent memory leaks.
    */
};


class BinomialHeap{
    BinomialTreeNode* root;
    int count;



public: 

    BinomialHeap(){
        root = nullptr;
        count = 0;
    }

    bool is_empty(){
        return root == nullptr;
    }

    BinomialTreeNode* mergeTwoRoots(BinomialTreeNode* root1, BinomialTreeNode* root2){

        if(root1==nullptr)return root2;

        if(root2==nullptr)return root1;

        if((root1->degree) > (root2->degree)){
            swap(root1,root2);
        }

        root1->right_sibling = root2;

        return root1;

    }

};

int main(){

return 0;
}