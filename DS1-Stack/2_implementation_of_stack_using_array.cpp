#include<bits/stdc++.h>
using namespace std;

class Stack{
    int tops = -1;
    const int max_size = 5; //check
    int* stk;

public:
    Stack(){
        
        stk = new int[max_size];
    }

    void push(int x){
        if(tops+1==max_size){
            cout<<"over flow"<<endl;
            return;
        }
        stk[++tops] = x;
    }


    void pop(){
        if(tops == -1){
            cout<<"under flow"<<endl;
            return;
        }
        //cout<<stk[tops]<<endl;
        tops--;
    }



    void peek(){
        if(tops==-1){
            cout<<"Empty Stack"<<endl;
            return;
        }

        cout<<stk[tops]<<endl;
    }



    int top(){
        if(tops==-1){
            cout<<"Empty Stack"<<endl;
            return INT_MIN;
        }
        return stk[tops];
    }


    int size(){
        return (tops+1);
    }


    bool Empty(){
        if(tops==-1){
            return true;
        }
        return false;
    }


    void clear(){
        while(tops != -1){
            tops--;
        }
    }


    int search(int data_to_search){
        int k=0;
        for(int i=tops;i!=-1;i--){
            
            if(stk[i]==data_to_search){
                return k;
            }
            k++;
        }
        cout<<"Data Not Found"<<endl;
        return -1;
    }



    void display_from_top(){
        if(tops == -1){
            cout<<"Stack is empty"<<endl;
            return;
        }
        for(int i=tops;i!=-1;i--){
            
            cout<<stk[i]<<" ";
        }
        cout<<endl;
    }



    void display_from_bottom(){

        if(tops == -1){
            cout<<"Stack is empty"<<endl;
            return;
        }
        for(int i=0;i<=tops;i++){
            
            cout<<stk[i]<<" ";
        }
        cout<<endl;
    }


    bool Full(){
        if(tops==max_size-1)return true;

        return false;
    }


};


int main(){
    
    Stack a = Stack();

    a.push(10);
    a.push(13);
    a.push(14);
    a.push(16);
    //a.push(18);
    //a.push(19);

    //a.pop();
    //a.pop();
    //a.pop();
    //a.pop();
    //a.pop();
    ///a.pop();


    //a.peek();

    cout<<a.search(123)<<endl;

    
    cout<<a.size()<<endl;

    a.display_from_top();
    a.display_from_bottom();

    cout<<a.Full()<<endl;

    return 0;
}



/*
=> Advantages of array implementation:
    1. Easy to implement.
    2. Memory is saved as pointers are not involved.

=> Disadvantages of array implementation:
    1. It is not dynamic i.e., it doesn’t grow and shrink depending on needs at runtime. [But in case of dynamic sized arrays 
        like vector in C++, list in Python, ArrayList in Java, stacks can grow and shrink with array implementation as well].
    2. The total size of the stack must be defined beforehand.


*/