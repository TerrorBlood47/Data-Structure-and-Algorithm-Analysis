
#include<bits/stdc++.h>
using namespace std;

class Node{
public:
        int data;
        Node* next;
};


//CodeVault
void appropriate_insertion_in_a_sorted_list(Node** root, int data_to_add){

    Node* new_node = new Node();

    if(new_node == NULL){
        exit(3);
    }

    new_node->data = data_to_add;

    //cout<<new_node->data<<endl;

    //cout<<(*root)->data<<endl;

    if(*root == NULL){
        *root = new_node;
        return;
    }

    if(((*root)->data) > data_to_add){ //adding element at the beginning
        new_node->next = *root;
        *root = new_node;
        return;
    }

    Node* curr = *root;
    Node* prev = *root;

    while(curr != nullptr){
        if((curr->data) > data_to_add){//adding element in the middle
            new_node->next = curr;
            prev->next = new_node;
            return;
        }
        prev = curr;
        curr = curr->next;
        prev->next = curr; // remember to link up
    }

    prev->next = new_node; //add element at the end

    return;

}




void PrintList(Node** root){

    Node* curr = *root;

    while(curr != nullptr){
        cout<<curr->data<<" ";
        curr = curr->next;
    }
    
}


void free_memory(Node** root){
    Node* curr = *root;
    Node* aux;

    while(curr!=nullptr){
        aux = curr;
        curr = curr -> next;

        free(aux);
    }
    *root = nullptr;
    return ;
}

int main(){

    Node* head = nullptr;
    
    head = new Node();

    if(head==nullptr){
        exit(0);
    }
    head->data = 10;
    head->next = new Node();
    if((head->next)==nullptr){
        exit(1);
    }
    head->next->data = 20;

    head->next->next = new Node();
    if((head->next->next)==nullptr){
        exit(2);
    }
    head->next->next->data = 30;

    head->next->next->next = nullptr;

    appropriate_insertion_in_a_sorted_list(&head,25);

    PrintList(&head);


    free_memory(&head);

    return 0;
}
