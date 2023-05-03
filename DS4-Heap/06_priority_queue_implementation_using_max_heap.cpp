#include<bits/stdc++.h>
using namespace std;

class PriorityQueueHeap{
private:
    int* a;
    int size;
    int capacity;

    int parent(int i){return (i-1)/2;}
    int left_child(int i){return (2*i+1);}
    int right_child(int i){return (2*i+2);}

    void heapify(int a[], int n, int index){
        if(index<0)return;

        int left = left_child(index);
        int right = right_child(index);

        int largest = index;

        if(left<n and a[left]>a[index]){
            largest = left;
        }
        if(right<n and a[right]>a[largest]){
            largest = right;
        }
        swap(a[index],a[largest]);

        heapify(a,n,index - 1);

    }

public:
    PriorityQueueHeap(int capacity){
        this->size = 0;
        this->capacity = capacity;
        a = (int*)calloc(capacity,sizeof(int));
    }

    void push(int val){

        if(size==capacity){
            throw "queue is full";
        }
        
        a[size] = val;
        size++;

        int i = size - 1;
        while(i>0 and a[parent(i)] < a[i]){
            if(a[parent(i)]<a[i]){
                swap(a[parent(i)] , a[i]);
                i = parent(i);
            }
        }
    }


    void pop(){
        if(size==0){
            cout<<"nothing to pop"<<endl;
            return;
        }

        swap(a[0],a[size-1]);
        size--;

        heapify(a,size,size-1);
    }


    int front(){
        if(size==0){
            throw "empty";
        }

        return a[0];
    }

    int top(){
        if(size==0){
            throw "empty";
        }

        return a[size - 1];
    }

    bool isempty(){
        if(size==0)return true;
        else return false;
    }


    void print(){
        if(size==0){
            cout<<"nothing to print"<<endl;
            return;
        }

        for(int i=0;i<size;i++){
            cout<<a[i]<<" ";
        }
    }
};

int main(){

PriorityQueueHeap q = PriorityQueueHeap(10);

q.push(12);
q.push(15);
q.push(13);
q.push(23);
q.push(22121);

q.pop();
q.pop();
q.pop();
q.pop();
q.pop();
q.pop();

q.push(22121);

q.print();

return 0;
}