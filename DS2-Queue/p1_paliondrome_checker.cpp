#include<bits/stdc++.h>
using namespace std;


class Queue_dyn{
    
    int root,last,size; //last can never be less than root
    unsigned int capacity = 20;
    char* arr;

public:

    Queue_dyn(){
        this->root = this->size = 0; 
        this->last = -1;
        this->arr = new char[this->capacity];
    }


    void enque(int x){

        if(size == capacity){
            cout<<"new memory allocated"<<endl;
            char *temp = arr;
            arr = new char[capacity + 5];
            
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


    char top(){
        if(size==0){
            cout<<"queue is empty"<<endl;
            
            return '+';
        }
        
        return arr[last];
    }

    char bottom(){
        if(size==0){
            cout<<"queue is empty"<<endl;
            return '+';
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


bool is_paliondrome(string s){
    int len = s.length();
    int mid = len/2;
    Queue_dyn q;

    for(int i = 0;i <= (len/2)-1; i++){
        q.enque(s[i]);
    }

    for(int i=0;i<=(len/2)-1;i++){

        if(q.bottom() != s[len-1-i]){
            return false;
        }
        q.deque();
    }

    return true;
}


int main(){
    
    string s = "a";

    bool b = is_paliondrome(s);

    if(b==true)cout<<"true"<<endl;
    else cout<<"false"<<endl;
    
    return 0;
}
