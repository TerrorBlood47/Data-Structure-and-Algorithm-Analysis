#include<bits/stdc++.h>
using namespace std;

class Node{
public:

    int data;
    Node* next;
    Node* prev;
};

class Stack_LL{

    Node* root;
    Node* last;
    int size_p ;
    

public:
    Stack_LL(){
        root =NULL;
        last = nullptr;
        size_p = 0;
    }

    void push(int x){
        if(root==NULL){
            root = new Node();
            last = new Node();
            size_p++ ;
            root->data = x;
            root->next = nullptr;
            root ->prev = nullptr;
            last = root;
            return;
        }

        Node* newNode = new Node();
        newNode->data =x;
        newNode->next = nullptr;
        last->next = newNode;
        newNode->prev = last;
        last = newNode;
        size_p++;
    }


    void pop(){

        if(root == NULL){
            cout<<"nothing to pop"<<endl;
            return;
        }

        Node* temp = last;
        last = last->prev ;

        free(temp);

        if(last==NULL){
            last = root = nullptr;
        }
        else{
            last->next = nullptr;
        }

        size_p--;
    }



    int top(){
        if(root == NULL){
            cout<<"nothing to see at top"<<endl;
            return INT16_MIN;
        }

        return last->data;
    }


    void peek(){
        if(root == NULL){
            cout<<"nothing to peek"<<endl;
            return ;
        }

        cout<<last->data<<endl;
    }


    int size(){
        return size_p;
    }

    bool empty(){
        if(size_p==0){
            return true;
        }
        else{
            return false;
        }
    }

};


int main(){

    Stack_LL s = Stack_LL();


    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);

    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    
    
    

    cout<<s.empty()<<endl;

    s.peek();

    return 0;
}