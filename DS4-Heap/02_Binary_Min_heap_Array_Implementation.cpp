
//link - g4g - Introduction to Heap – Data Structure and Algorithm Tutorials
//YT - Farhan Hossain

#include<bits/stdc++.h>
using namespace std;


class MinHeap
{

    int* arr;
    int size;
    int capacity;

public:

   MinHeap(int capacity){
        this->size = 0;
        this->capacity = capacity;
        arr = new int[capacity];
    }

    int parent(int i){
        return (i-1)/2;
    }

    int left_child(int i){
        return (2*i + 1);///must have brackets
    }

    int right_child(int i){
        return (2*i + 2);//must have brackets encompassing the expression
    }


    int getMin(){
        return arr[0];
    }

    int Size(){
        return size;
    }


    void insert(int x){

        if(size==capacity){
            cout<<"size full"<<endl;
            return;
        }

        if(size==0){
            arr[0] = x;
            size++;
            return ;
        }

        arr[size] = x;
        size++;

        int i = size-1;

        while(i!=0 and arr[parent(i)] > arr[i] ){
            swap(arr[parent(i)],arr[i]);
            i = parent(i);
        }

        return;
    }



    void removeMin(){
        if(size==0){
            cout<<"nothing to delete"<<endl;
            return;
        }
        if(size==1){
            size--;
            return;
        }
        swap(arr[0],arr[size-1]);
        size--;
        MinHeapify(0);
        
    }


    void MinHeapify(int index){

        int l = left_child(index);
        int r = right_child(index);
        int smallest_among_3 = index;

        if(l < size && arr[l]<arr[index] ){
            smallest_among_3 = l;
        }

        if(r < size &&  (arr[r]< arr[l]) ){
            smallest_among_3 = r;
        }

        if(smallest_among_3==index)return;
        else{
            swap(arr[index] , arr[smallest_among_3]);
            MinHeapify(smallest_among_3);
        }

    }

    void decreaseValue(int i, int newValue){
        arr[i] = newValue;

        while(i!=0 and arr[parent(i)] > arr[i] ){
            swap(arr[i], arr[parent(i)]);
            i = parent(i);
        }
    }

    void deleteAt(int index){

        decreaseValue(index,INT_MIN);
        removeMin();
        
    }


    void print(){
        int i = 0;

        for(i=0;i<size;i++){
            cout<<arr[i]<<" ";
        }
    }


};




int main(){

    MinHeap m = MinHeap(10);

    m.insert(10);
    m.insert(8);
    m.insert(5);
    m.insert(11);

    m.removeMin();
    

    m.deleteAt(0);

    //m.removeMax();

    m.print();


return 0;
}