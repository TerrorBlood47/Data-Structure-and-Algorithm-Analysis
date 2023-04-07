
#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node* prev;
};

void PrintList_DLL(Node* root){

    Node* curr = root;

    while(curr != nullptr){
        cout<<curr->data<<" ";
        curr = curr -> prev;
    }
    
    
}


void free_memory_DLL(Node** tail, Node** head){
    if(*tail == nullptr){
        cout<<"List is  empty....nothing to free"<<endl;
        return ;
    }

    Node *curr = *tail;

    while((curr->next) != nullptr){
        curr = curr->next;
        free(curr->prev);//no need for auxiliary ptr
    }
    free(curr);

    *tail = nullptr;
    *head = nullptr;
}



int main(){

    Node* tail = new Node();

    if(tail == nullptr){
        exit(0);
    }
    tail->data = 10;
    tail->prev = nullptr;
    tail->next = new Node();
    if(tail->next == nullptr){
        exit(1);
    }
    tail->next->data = 20;
    tail->next->prev = tail;
    tail->next->next  = new Node();
    if(tail->next->next == nullptr){
        exit(2);
    }
    tail->next->next->data = 30;
    tail->next->next->prev = tail->next;
    tail->next->next->next = nullptr;

    Node* head = tail->next->next;

    PrintList_DLL(head);

    free_memory_DLL(&tail, &head);

    return 0;
}
