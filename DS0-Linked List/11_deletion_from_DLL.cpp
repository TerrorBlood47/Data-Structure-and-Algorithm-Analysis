
#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node* prev;
};


void delete_from_DDL(Node** head,Node** tail, int pos){

    if(*head == NULL){
        cout<<"nothing to delete"<<endl;
        return;
    }

    if(pos==1){
        Node* temp = *head;
        *head = (*head)->next;
        free(temp);
        
        return;
    }

    Node* curr = *head;
    int i = 1;

    while(curr != NULL){

        if(i==pos){

            if(curr->next != NULL){
                Node* prev_of_curr = curr->prev;
                Node* next_of_curr = curr->next;

                prev_of_curr ->next = next_of_curr;
                next_of_curr->prev = prev_of_curr;
                free(curr);
                return;
            }
            else{
                *tail = curr->prev;
                (*tail)->next = nullptr;
                free(curr);
                return;
            }   
        }

        i++;
        curr = curr->next;
    }

    cout<<"invalid request"<<endl;


}


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

/*
    if(head == nullptr){      //to declare one element ddl list
        exit(0);
    }
    head->data = 10;
    head->prev = nullptr;
    Node* tail = head;
    head->next = nullptr;
    */
    
    if(head == nullptr){      
        exit(0);
    }
    head->data = 10;
    head ->prev = nullptr;

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
    Node* head = NULL; //this is how yoe declare empty doubly linked list
    Node* tail = NULL;
*/

    delete_from_DDL(&head,&tail,3);
    

    PrintList_DLL(head);

    
    free_memory_DLL(&head, &tail);

    return 0;
}
