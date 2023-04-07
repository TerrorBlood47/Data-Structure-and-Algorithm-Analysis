
#include<bits/stdc++.h>
using namespace std;

class Node{
public:
        int data;
        Node* next_link;
};

//CodeVault

void reversing_list(Node** root){
    Node* curr = *root;
    Node* prev = nullptr;

    while(curr != nullptr){

        Node* next = curr->next_link;

        curr->next_link = prev;
        prev = curr;
        curr = next;
        
    }
    
    *root = prev;
}


void PrintList(Node** root){

    Node* curr = *root;

    while(curr != nullptr){
        cout<<curr->data<<" ";
        curr = curr->next_link;
    }
    
}


void free_memory(Node** root){
    Node* curr = *root;
    Node* aux;

    while(curr!=nullptr){
        aux = curr;
        curr = curr -> next_link;

        free(aux);
    }
    *root = nullptr;
    return ;
}




int main(){

    Node* head;
    head = new Node();

    if(head==nullptr){
        exit(0);
    }
    head->data = 10;
    head->next_link = new Node();
    if((head->next_link)==nullptr){
        exit(1);
    }
    head->next_link->data = 20;

    head->next_link->next_link = new Node();
    if((head->next_link->next_link)==nullptr){
        exit(2);
    }
    head->next_link->next_link->data = 30;

    head->next_link->next_link->next_link = nullptr;

    reversing_list(&head);


    PrintList(&head);


    free_memory(&head);

    return 0;
}
