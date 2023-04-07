#include<bits/stdc++.h>
using namespace std;



///geeksforgeeks - Introduction and Array Implementation of Queue
class Queue{
    
    int root,last,size;
    unsigned int capacity;
    int* arr;

public:

    Queue(unsigned cap){
        this->capacity = cap;
        this->root = this->size = 0;
        this->last = -1;
        this->arr = new int[this->capacity];
    }


    void enque(int x){

        if(size == capacity){
            cout<<"queue is full"<<endl;
            return;
        }

        last = (last+1)%capacity; //check
        arr[last] = x;
        size++;
    }


    void deque(){
        if(size==0){
            cout<<"queue is empty"<<endl;
            return;
        }

        root = (root + 1)%capacity;//check
        size--;
        if(size==0){
            root = 0;
            last = -1;
        }
    }


    int top(){
        if(size==0){
            cout<<"queue is empty"<<endl;
            return INT_MIN;
        }

        return arr[last];
    }

    int bottom(){
        if(size==0){
            cout<<"queue is empty"<<endl;
            return INT_MIN;
        }

        return arr[root];
    }

    bool isEmpty(){
        if(size==0)return true;
        else return false;
    }

    bool isFull(){
        if(size==capacity)return true;
        else return false;
    }

    int size_p(){
        return size;
    }

    void display_from_bottom(){

        if(size==0){
            cout<<"queue is empty...nothing to print"<<endl;
            return;
        }

        for(int i=root ; i<=last ; i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};



int main(){
    
    Queue q =  Queue(4);

    q.enque(10);
    q.enque(12);
    q.enque(15);
    q.enque(17);

    q.deque();
    q.deque();
    q.deque();

    bool e = q.isEmpty();

    cout<<e<<endl;


    q.enque(10);
    q.enque(12);
    q.enque(15);

    cout<<" size = "<<q.size_p()<<endl;

    
    q.enque(17);
    
    int t = q.top();
    int  b = q.bottom();

    cout<<"top = "<<t<<" bottom = "<<b<<endl;
    return 0;
}

/*
=> Advantages of Array Implementation:  
    1. Easy to implement.
    2. A large amount of data can be managed efficiently with ease.
    3. Operations such as insertion and deletion can be performed with ease as it 
        follows the first in first out rule.

=> Disadvantages of Array Implementation:  
    1. Static Data Structure, fixed size.
    2. If the queue has a large number of enqueue and dequeue operations, at some point (in case of linear increment 
        (this of front and rear indexes) we may not be able to insert elements in the queue even if the queue is empty 
        problem is avoided by using circular queue).
    3. Maximum size of a queue must be defined prior.

*/