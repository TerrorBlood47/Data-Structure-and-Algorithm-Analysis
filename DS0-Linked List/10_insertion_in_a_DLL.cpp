
#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node* prev;
};


void insert_to_the_beginning_DDL(Node** head, Node**tail,int value_to_add){
    Node* new_node = new Node();

    if(new_node == nullptr){
        exit(3);
    }

    new_node->data = value_to_add;
    cout<<new_node->data<<endl;
    new_node->prev = NULL;
    
    if(*head == NULL){
        new_node ->next = NULL;//makes no change

        *head = new_node;
        *tail = new_node;
        return;
    }


    new_node->next = *head;
    (*head)->prev = new_node;
    *head = new_node;
    return;
}



void insert_to_the_end_DDL(Node** head, Node** tail, int value_to_add){
    Node* new_node = new Node();
    if(new_node == nullptr){
        exit(3);
    }

    new_node->data = value_to_add;
    new_node->next = NULL;
    //cout<<new_node->data<<endl;

    if(*tail==NULL){
        new_node->prev = NULL;

        *head=new_node;
        *tail = new_node;
        return;
    }

    (*tail)->next = new_node;
    new_node->prev = *tail;
    *tail = new_node;

}


void insert_to_after_a_node_DDL(Node** head, Node** tail, int value_to_add, int pos){
    Node* new_node = new Node();
    if(new_node == NULL){
        exit(3);
    }

    new_node->data = value_to_add;
    cout<<new_node->data<<endl;

    int i = 1;

    Node* curr = *head;

    while(curr!=NULL){

        if(i==pos){
            if(curr->next != NULL){
                Node* curr_next = curr->next;  //check

                new_node->next = curr->next;
                new_node->prev = curr;
                curr->next = new_node;
                curr_next->prev = new_node;
                return;
            }
            else{
                curr->next = new_node;
                new_node->prev = curr;
                new_node->next = NULL;
                return;
            }
        }

        curr = curr->next;
        i++;
    }

    printf("Out of bound\n");

}






void PrintList_DLL(Node* root){

    Node* curr = root;

    while(curr != nullptr){
        cout<<curr->data<<" ";
        curr = curr -> next;
    }
    
    
}


void free_memory_DLL(Node** head, Node** tail){
    if(*head == nullptr){
        cout<<"List is empty....nothing to free"<<endl;
        return ;
    }

    Node *curr = *head;

    while((curr->next) != nullptr){
        curr = curr->next;
        free(curr->prev);//no need for auxiliary ptr
    }
    free(curr);

    *head = nullptr;
    *tail = nullptr;
}



int main(){

    Node* head = new Node();

    if(head == nullptr){
        exit(0);
    }
    head->data = 10;
    head->prev = nullptr;
    head->next = new Node();
    if(head->next == nullptr){
        exit(1);
    }
    head->next->data = 20;
    head->next->prev = head;
    head->next->next  = new Node();
    if(head->next->next == nullptr){
        exit(2);
    }
    head->next->next->data = 30;
    head->next->next->prev = head->next;
    head->next->next->next = nullptr;

    Node* tail = head->next->next;
/*
    Node* head = NULL; //this is how yoe declare doubly linked list
    Node* tail = NULL;
*/

    //insert_to_the_beginning_DDL(&head,&tail,200);
    
    //insert_to_the_end_DDL(&head,&tail,200);
    
    insert_to_after_a_node_DDL(&head,&tail,200,4);

    PrintList_DLL(head);

    free_memory_DLL(&head, &tail);

    return 0;
}
