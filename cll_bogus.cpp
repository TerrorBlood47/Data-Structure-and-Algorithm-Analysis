#include<bits/stdc++.h>
using namespace std;

class Queue_dyn{
    int root,last,size;
    unsigned int cap;

    int* arr;

public:
    Queue_dyn(unsigned int c){
        this->root = 0;
        this->last = -1;
        this->cap = c;
        this->size = 0;

        arr = new int[cap];
    }

    void enque(int x){

        if(size==cap){
            cout<<"dyn"<<endl;

            int* t = arr;

            arr = new int[cap+5];

            for(int i=0; i<cap ;i++)arr[i] = t[i];

            cap += 5;
        }

        last = (last+1)%cap;
        arr[last] = x;
        size++;
    }


    void deque(){

        if(size==0 || last==-1){
            cout<<"nothing to deque"<<endl;
            return;
        }

        root = (root + 1)%cap;

        if(root>last){
            root = 0;
            last = -1;
        }

        size--;
    }



    void peekbottom(){
        if(size==0 || last==-1){
            cout<<"nothing to peek"<<endl;
            return;
        }

        cout<<arr[last]<<endl;
    }


};


int main(){

    Queue_dyn q = Queue_dyn(3);

    q.enque(1);
    q.enque(2);
    q.enque(3);
    q.enque(4);

    q.deque();
    q.deque();
    q.deque();
    q.deque();
    q.deque();
    q.deque();

    q.enque(10);
    q.enque(20);
    q.enque(30);
    q.enque(1);
    q.enque(2);
    q.enque(3);q.enque(1);
    q.enque(2);
    q.enque(3);


    q.peekbottom();

    return 0;
}