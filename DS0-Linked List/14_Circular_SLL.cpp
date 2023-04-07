//Source  - GeeksForGeeks + Neso Academy


/*
-> The circular linked list is a linked list where all nodes are connected to form a circle. In a circular linked list,
    the first node and the last node are connected to each other which forms a circle. There is no NULL at the end.

->
*/


#include<bits/stdc++.h>
using namespace std;

                    

class Node{
public:

    int data;
    Node* next;//link to the next element
};


Node* addToEmpty_Circular_SLL(Node** last, int data_to_add){

    if(*last != NULL){
        cout<<"list is not empty"<<endl;
        return *last ;
    }

    *last = new Node();
    (*last)->data = data_to_add;
    (*last)->next = *last;

    return *last;

}




Node* addBegin_Circular_SLL(Node* last, int data_to_add){

    if(last == NULL){
        last = addToEmpty_Circular_SLL(&last,data_to_add);
        return last;
    }

    Node* new_node = new Node();
    new_node->data = data_to_add;

    new_node->next = last->next;
    last->next = new_node;

    return last;
}



Node* addEnd_Circular_SLL(Node* last, int data_to_add){

    if(last == NULL){
        last = addToEmpty_Circular_SLL(&last,data_to_add);
        return last;
    }

    Node* new_node = new Node();
    new_node->data = data_to_add;

    new_node->next = last->next;
    last->next = new_node;
    last = new_node;

    return last;

}

Node* addAfter_Circular_SLL(Node* last, int data_to_add, int pos){

    if(last==NULL){
        return NULL;
    }

    Node* new_node = new Node();
    new_node->data = data_to_add;

    Node* curr = last->next; //head basically
    int i = 1;

    while(curr != last){

        if(i==pos){
            new_node->next = curr->next;
            curr->next = new_node;
            return last;
        }

        i++;
        curr = curr->next;
    }

    if(i==pos){
        last = addEnd_Circular_SLL(last,data_to_add);
        return last;
    }

    cout<<"Out of bound... Error!!!"<<endl;
}


Node* deleteFirst_Circular_SLL(Node* last){

    if(last==NULL){
        cout<<"Nothing to delete"<<endl;
        return NULL;
    }

    if(last->next == last){//only 1 element
        free(last);
        last = NULL;
        return last;
    }

    Node* temp = last->next;
    last->next = temp->next;
    free(temp);

    return last;

}


Node* deleteLast_Circular_SLL(Node* last){
    if(last==NULL){
        cout<<"Nothing to delete"<<endl;
        return NULL;
    }

    if(last->next == last){//only 1 element
        free(last);
        last = NULL;
        return last;
    }

    Node* curr = last->next; // head

    while((curr->next) != last){
        curr = curr->next;
    }

    curr->next = last->next;
    free(last);
    last = curr;
    return last;
}

Node* deleteIntermediate_Circular_SLL(Node* last, int pos){
    if(last==NULL){
        cout<<"Nothing to delete"<<endl;
        return NULL;
    }

    if(last->next == last){
        cout<<"not enough element to delete"<<endl;
        return last;
    }

    Node* curr = last -> next;
    

    while(pos>2){
        pos--;
        curr = curr->next;
    }

    Node* temp = curr->next;
    curr->next = temp->next;

    if(temp == last)last = curr;

    free(temp);
    temp = NULL;
    return last;
}



int PrintList_Circular_SLL(Node* last){
    

    //cout<<(last==NULL)<<endl;

    if(last==NULL){
        cout<<"list is empty"<<endl;
        last->next = last;
        return 0;
    }
    else{
        Node* curr = last->next;
        while(curr != last){
            cout<<curr->data<<" ";
            curr = curr->next;
        }
        cout<<curr->data<<endl;
    }

    return 0;

}

int main(){

    Node* last = NULL;
    last = addToEmpty_Circular_SLL(&last,2);
    last = addBegin_Circular_SLL(last,1);
    last = addEnd_Circular_SLL(last,3);
    last = addAfter_Circular_SLL(last,200,3);
    //last = deleteLast_Circular_SLL(last);
    last = deleteIntermediate_Circular_SLL(last,2);//pos != 1

    
    //cout<<last->data<<endl;

    PrintList_Circular_SLL(last);

    
    return 0;
}
