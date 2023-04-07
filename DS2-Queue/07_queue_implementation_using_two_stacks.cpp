#include<bits/stdc++.h>
using namespace std;

class Stack{
    int tops = -1;
    int max_size = 5;

public:
    int* stk = (int*)calloc(max_size,sizeof(int));
    

    void push(int x){

        if(tops+1==max_size){
            cout<<"new memory allocated"<<endl;
            stk = (int*)realloc(stk,max_size+5);
            if(stk==nullptr){
                cout<<"new memory allocation failed...exiting the program"<<endl;
                exit(1);
            }
            max_size += 5;
        }
        stk[++tops] = x;
    }


    void pop(){
        if(tops == -1){
            cout<<"under flow"<<endl;
            return;
        }
        
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
            free(stk + tops*sizeof(int));
            tops--;
        }
        cout<<"memory freed"<<endl;

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


};



class Queue_using_two_stacks{
    Stack st, temp;
    int size = 0;

public:

    void enque(int x){ //making sure that front remains at top of stack st
        size++;
        while(st.Empty()==false){//storing temporarily in reverse order
            temp.push(st.top());
            st.pop();
        }
        st.push(x);
        while(temp.Empty()==false){//back to order with front at top and latest addition at bottom
            st.push(temp.top());
            temp.pop();
        }
    }

    void deque(){
        if(st.Empty()){
            cout<<"empty queue"<<endl;
            return;
        }
        size--;
        st.pop();
    }

    int bottom(){
        if(st.Empty()){
            cout<<"empty queue"<<endl;
            return INT_MIN;
        }
        return st.top();
    }

};


int main(){
    
    Queue_using_two_stacks q;

    q.enque(1);
    q.enque(2);
    q.enque(3);

    q.deque();
    
    cout<<q.bottom()<<endl;

    
    return 0;
}



