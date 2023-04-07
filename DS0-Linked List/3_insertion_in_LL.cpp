#include<bits/stdc++.h>
using namespace std;

                    

class Node{
public:

    int data;
    Node* next_link;//link to the next element
};



//CodeVault - Adding elements to a linked list
void insert_element_at_the_end(Node** root, int element_to_add){ //if the root is not empty, double referencing is not needed
                                                                  //nullptr does not point to anything, so we took double referencing
                                                                  //in case the list is empty
    
    Node* new_node = new Node();

    if(new_node == NULL){
        cout<<"Memory could not be allocated"<<endl;
        exit(1);
    }

    new_node->next_link = NULL;//because we want to add it in the end, the next element does not exist
    new_node->data = element_to_add;

    if(*root == NULL){
        *root = new_node;
        return;
    }

    Node* curr;
    curr = *root;

    while(curr -> next_link != NULL){ //check the condition
        curr = curr -> next_link;
    }
    curr -> next_link = new_node; // linking up

/*

Time complexity: O(N), where N is the number of nodes in the linked list. Since there is a loop from head to end, the function does 
O(n) work. This method can also be optimized to work in O(1) by keeping an extra pointer to the tail of the linked list

Auxiliary Space: O(1)
*/
}




//CodeVault - Adding at the beginning of a linked list
void insert_element_at_the_beginning(Node** root, int element_to_add){
    
    Node* new_node = new Node();

    if(new_node==NULL){
        exit(2);
    }

    new_node->data = element_to_add;
    new_node->next_link = *root; //the previous root becomes linked with new_node

    *root = new_node; // we change the root every time the function is called

/*
Time Complexity: O(1), We have a pointer to the head and we can directly attach a node and change the pointer. So 
                        the Time complexity of inserting a node at the head position is O(1) as it does a constant amount of work.
Auxiliary Space: O(1)
*/
}



//CodeVault
void insert_after_a_node(Node** prev_node, int data_to_insert){

    if(prev_node==NULL){
        cout<<"The Given Node is Null"<<endl;
        return;
    }


    Node* new_node = new Node();
    if(new_node == NULL){
        exit(3);
    }

    new_node->next_link = (*prev_node)->next_link;
    new_node->data = data_to_insert;

    (*prev_node)->next_link = new_node;
}






void printList(Node* root){
    Node* curr;
    curr = root;

    while(curr != NULL){
        cout<<curr->data<<" ";
        curr = curr->next_link;
    }
}


void free_memory(Node** root){

    Node* curr = *root;

    while(curr != NULL){
        Node* temp = curr;
        curr = curr -> next_link;
        free(temp);
    }
    *root = NULL;
}




int main(){

    Node* head;
    head = new Node();
    if(head==NULL){
        cout<<"Memory to head not allocated"<<endl;
        exit(0);
    }
    
    head -> data = 15;

    head->next_link = new Node();
    head->next_link -> data = 25; 

    head->next_link->next_link = new Node();
    head->next_link->next_link->data = 35;

    head->next_link->next_link->next_link = NULL;
    

    int x = 20;
    //int n;
    //cin>>n;

    //for(int i=0;i<n;i++){
    //cin>>x;
    //insert_element_at_the_end(&head,x); //kinda like stack implementation
    //insert_element_at_the_beginning(&head,x);
    //}

    
    insert_after_a_node(&(head->next_link),x);

    printList(head);

    free_memory(&head);
    //UNABLE TO USE MEMORY LEAK DETECTION FUNCTION
    return 0;
}
