#include<bits/stdc++.h>
using namespace std;

class Node{
public:

    int data;
    Node* next;
    Node* prev;
    
};

Node* NewNode(int data){
    Node* new_node = new Node();
    new_node->data = data;

    return new_node;
}

void push(Node** root, Node** last , int data){

    Node* new_node = NewNode(data);

    if((*root)==NULL){
        *root = new_node;
        (*root)->prev = NULL;
        (*root)->next = NULL;
        *last = *root;
        return;
    }

    (*last)->next = new_node;
    new_node->prev = *last;
    new_node->next = NULL;
    *last = new_node;
    return;
    
}

void pop(Node** root, Node** last ){

    if(*root == NULL){
        cout<<"nothing to pop....stack is empty"<<endl;
        return;
    }

    Node* temp = *last;
    *last = (*last)->prev;
    if(*last==NULL){
        (*root)->prev = NULL;
        (*root)->next = NULL;
        *root = *last = NULL;
    }
    if(*last != NULL)(*last)->next = NULL; //check
    free(temp);
    
}



void peek(Node** root, Node** last){
    if(*last == NULL){
        cout<<"yo stack is empty"<<endl;
        return;
    }
    cout<<(*last)->data<<endl;
}


Node* top(Node** last){
    if(*last == NULL){
        cout<<"yo bitch stack is empty"<<endl;
        return NULL;
    }

    return *last;
}


bool Empty(Node** root){
    return !(*root);
}



int size(Node** root){

    if(*root==NULL){
        return 0;
    }
    Node* curr = *root;
    int s = 0;
    while(curr != NULL){
        s++;
        
        curr = curr->next;
        
    }
    return s;
}


void clear(Node** root, Node** last){
    Node* curr = *root;
    while(curr!=NULL){
        Node* temp = curr;
        curr = curr->next;
        free(temp);
    }
    //(*root)->prev = NULL; //don't do it..... when the pointer in NULL, its next and prev becomes meaningless
    //(*root)->next = NULL;
    *last = *root = NULL;
}


int search_from_top(Node** last, int data_to_search){
    Node* curr = *last;
    int i = 0;

    while(curr != NULL){

        if(data_to_search==curr->data){
            return i;
        }
        i++;
        curr = curr->prev;
    }

    cout<<"not found"<<endl;
    return -1;
}


int search_from_bottom(Node** root, int data_to_search){
    Node* curr = *root;
    int i = 0;
    while(curr != NULL){
        if(data_to_search==curr->data){
            return i;
        }
        i++;
        curr = curr->next;
    }
    cout<<"not found"<<endl;
    return -1;
}

void display_from_top(Node** last){

    if(*last==NULL){
        cout<<"Empty Stack..nothing to print"<<endl;
        return;
    }

    Node* curr = *last;

    while(curr != NULL){
        cout<<curr->data<<" ";
        curr = curr->prev;
    }
}





int main(){

    Node* root = NULL;
    Node* last = NULL;

    push(&root,&last,4);
    push(&root,&last,14);
    push(&root,&last,24);

    pop(&root,&last);
    pop(&root,&last);
    pop(&root,&last);
    //pop(&root,&last);
    
    //clear(&root,&last);

    peek(&root,&last);

    int k = search_from_bottom(&root,4);

    cout<<k<<endl;

    display_from_top(&last);
    return 0;
}

/*

=> Advantages of Linked List implementation:
    1. The linked list implementation of a stack can grow and shrink according to the needs at runtime.
    2. It is used in many virtual machines like JVM.

=> Disadvantages of Linked List implementation:
    1. Requires extra memory due to the involvement of pointers.
    2. Random accessing is not possible in stack.


*/