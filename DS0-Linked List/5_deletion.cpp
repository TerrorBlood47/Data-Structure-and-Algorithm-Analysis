
#include<bits/stdc++.h>
using namespace std;

class Node{
public:
        int data;
        Node* next;
};


void delete_from_beginning(Node** root){

    if(*root == nullptr){
        printf("Nothing to delete...list is empty\n");
        return;
    }

    Node* temp = *root;
    *root = (*root)->next;

    free(temp);
}


//GeeksForGeeks
void delete_from_the_end(Node** root){

    if(*root == nullptr){
        printf("Nothing to delete...list is empty\n");
        return;
    }

    if((*root)->next  == nullptr){ //only one element in the list
        free(*root);
        *root = nullptr;
        return;
    }
    
    Node* curr = *root;
    Node* prev = nullptr;

    while((curr->next) != nullptr){
        prev = curr;
        curr = curr->next;
    }
    free(curr);
    prev->next = nullptr; // a very important linkup, because LL are not distributed contiguously like arrays
    return;
}




void delete_from_the_middle(Node** root, int pos){
    
    if(*root == nullptr){
        printf("Nothing to delete...list is empty\n");
        return;
    }
    if(pos==1){
        Node* temp = *root;
        *root = (*root)->next;
        free(temp);
        return;
    }

    Node* prev = nullptr;
    Node* curr = *root;
    int i = 1;

    while(i<=pos){
        if(curr == nullptr){
            cout<<"Nothing to delete here...pos out of bound"<<endl;
            return;
        }

        if(i==pos){
            cout<<i<<endl;
            prev->next = curr->next;
            free(curr);
            return;
        }

        i++;
        prev = curr;
        curr = curr->next;
        //prev->next = curr;
    }
    printf("Out of bound...error!!!");
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

    Node* head;
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

    //delete_from_beginning(&head);
    //delete_from_the_end(&head);
    
    delete_from_the_middle(&head,2); //delete from any position

    PrintList(&head);


    free_memory(&head);

    return 0;
}
