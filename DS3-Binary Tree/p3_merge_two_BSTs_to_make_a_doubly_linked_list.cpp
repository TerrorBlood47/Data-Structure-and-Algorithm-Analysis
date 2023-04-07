#include<bits/stdc++.h>
using namespace std;


class Node {
public:
    int data;
    Node* left;
    Node* right;

    // Constructor
    Node(int data)
    {
        this->data = data;
        this->left = this->right = nullptr;
    }
};



Node* ConvertBSTtoDLL(Node* )


Node* merge(Node* a, Node* b){

    Node* head_dll_1 = ConvertBSTtoDLL(a);
    Node* head_dll_2 = ConvertBSTtoDLL(b);
}



int main()
{
    /* Construct the following BST
          20
         /  \
       10    30
            /  \
           25  100
    */
 
    Node* a = new Node(20);
    a->left = new Node(10);
    a->right = new Node(30);
    a->right->left = new Node(25);
    a->right->right = new Node(100);
 
    /* Construct the following BST
          50
         /  \
        5   70
    */
 
    Node* b = new Node(50);
    b->left = new Node(5);
    b->right = new Node(70);
 
    // merge both BSTs into a doubly-linked list
    Node* root = merge(a, b);
    printDoublyLinkedList(root);
 
    return 0;
}