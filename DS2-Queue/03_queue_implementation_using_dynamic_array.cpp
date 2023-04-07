#include<bits/stdc++.h>
using namespace std;


class Queue_dyn{
    
    int root,last,size; //last can never be less than root
    unsigned int capacity = 20;
    int* arr;

public:

    Queue_dyn(){
        this->root = this->size = 0; 
        this->last = -1;
        this->arr = new int[this->capacity];
    }


    void enque(int x){

        if(size == capacity){
            cout<<"new memory allocated"<<endl;
            int *temp = arr;
            arr = new int[capacity + 5];
            
            for(int i=0;i<capacity;i++)arr[i] = temp[i];
            
            capacity += 5;
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

        root = (root + 1)%capacity;
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
    
    Queue_dyn q =  Queue_dyn();

    q.enque(10);
    q.enque(12);
    q.enque(15);
    q.enque(17);

    q.deque();
    q.deque();
    q.deque();
    
    
/*
    bool e = q.isEmpty();

    cout<<e<<endl;


    q.enque(10);
    q.enque(12);
    q.enque(15);

    cout<<" size = "<<q.size_p()<<endl;

    
    q.enque(17);
    */
    int t = q.top();
    int  b = q.bottom();

    cout<<"top = "<<t<<" bottom = "<<b<<endl;

    q.display_from_bottom();
    return 0;
}
