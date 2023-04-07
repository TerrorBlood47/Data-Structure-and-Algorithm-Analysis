#include<bits/stdc++.h>
using namespace std;

/*
Difference between Dot(.) and Arrow(->) operator:  
1. GeeksForGeeks(https://www.geeksforgeeks.org/arrow-operator-in-c-c-with-examples/)
2. Learning Monkey- youtube (https://youtu.be/wmoYW3q2Vxo)

*/

//CodeVault vid - 1 & 2 - Short introduction to linked lists in C
//                      - Iterating over a linked list in C

class Node{
    public:
        int data;
        Node* next;

};


int main(){

    /*
    //Basic Implementation of linked list

    /
    Node root, branch1,branch2;
    
    root.data = 100;
    root.next = &branch1;

    branch1.data = 200;
    branch1.next = &branch2;

    branch2.data = 300;
    branch2.next = nullptr; //last element is null
    /
    */
    //another way to implement

    Node *root;
    root = (Node*)malloc(sizeof(Node)); // another way: root = new Node();
    root->data = 100;

    root->next = (Node*)malloc(sizeof(Node));
    root->next->data = 200;

    root->next->next = (Node*)malloc(sizeof(Node));// writing this line equal to null , root->next->next->data  does not print anything
                                                    //so in this method, extra one ptr needs to be pointed as nullptr
    root->next->next->data = 300;
    root->next->next->next = nullptr; //extra line as nullptr


    //cout<<root->next->next->data<<endl;

    //*/

    //Iterating over a linked list in C - CodeVault

    Node *curr = root ; // curr prints the same memory address as root; *curr,*root does not exists and prints nothing
    
    //cout<<root<<" "<<curr<<endl;

    while(curr != NULL){
        printf("%d ",curr->data);
        curr = curr->next;// curr is pointing the next pointer
    }


    free(root->next->next);//freeing the dynamic allocations, check out the order
    free(root->next);
    free(root);
    return 0;
}
