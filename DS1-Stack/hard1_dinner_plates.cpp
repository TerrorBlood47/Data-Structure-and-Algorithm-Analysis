//leetcode - 1172
#include<bits/stdc++.h>
using namespace std;

class Stack{
    int tops = -1;
    int max_size = 5;

public:
    int* stk = (int*)calloc(max_size,sizeof(int));
    

    void push(int x){

        if(tops+1==max_size){
            //cout<<"new memory allocated"<<endl;
            stk = (int*)realloc(stk,max_size+5);
            if(stk==nullptr){
                //cout<<"new memory allocation failed...exiting the program"<<endl;
                exit(1);
            }
            max_size += 5;
        }
        stk[++tops] = x;
    }


    void pop(){
        if(tops == -1){
            //cout<<"under flow"<<endl;
            return;
        }
        
        tops--;
    }



    void peek(){
        if(tops==-1){
            //cout<<"Empty Stack"<<endl;
            return;
        }

        cout<<stk[tops]<<endl;
    }



    int top(){
        if(tops==-1){
            //cout<<"Empty Stack"<<endl;
            return -1;
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



};



class DinnerPlates {
public:
int size;
int tops = 0;
int rightmost = 0 ;
int j = 0;

    DinnerPlates(int capacity) {
        this->size = capacity;
        
    }

    Stack a[20000];
    
    void push(int val) {

        cout<<"push :"<<val<<endl;
        
        while( a[tops].size() == size){
            ++tops;
            ++rightmost;
            
        }
        //if(tops==-1)tops=0;
        a[tops].push(val);
        // rightmost = tops;
    }
    
    int pop() {

        cout<<"pop "<<endl;
        if(tops==-1){
            return -1;
        }
        // if(j==0){
        //     return -1;
        // }

        tops = rightmost;

        while(a[tops].size()==0){
            tops--;

            if(tops<0){
                break;
            }
        }

        if(tops<0){
            tops = -1;
            return -1;
        }

        //rightmost = tops;

        int temp = a[tops].top();
        a[tops].pop();

        return temp;
    }
    
    int popAtStack(int index) {
        cout<<"popAtStack : index = "<<index<<endl;
        if(a[index].size()==0){
            return -1;
        }

        int temp = a[index].top();
        a[index].pop();
        tops = index;
        return temp;

    }

    void display(){
        int i = 0;

        while(i!=rightmost){

            if(a[i].size()==0){
                i++;
                cout<<endl;
            }

            if(i==-1)return;

            cout<<a[i].top()<<" ";
            a[i].pop();
        }
    }
};

/**
 * Your DinnerPlates object will be instantiated and called as such:
 * DinnerPlates* obj = new DinnerPlates(capacity);
 * obj->push(val);
 * int param_2 = obj->pop();
 * int param_3 = obj->popAtStack(index);
 */


int main(){

    //vector<string>v = {"DinnerPlates", "push", "push", "push", "push", "push", "popAtStack",
    //"push", "push", "popAtStack", "popAtStack", "pop", "pop", "pop", "pop", "pop"};

    //int a[] = {2,1,2,3,4,5,0,20,21,0,2,INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN};


    vector<string>v = {"DinnerPlates", "push", "push", "push", "push", "push", "popAtStack",
    "push"};

    int a[] = {2,1,2,3,4,5,0,20};

    DinnerPlates D =  DinnerPlates(a[0]) ;

    for(int i=1;i<v.size();i++){

        if(v[i]=="DinnerPlates"){
            D =  DinnerPlates(a[i]) ;
        }
        else{
            if(v[i]=="push"){
                D.push(a[i]);
            }
            else if(v[i]=="pop"){
                D.pop();
            }
            else if(v[i]=="popAtStack"){
                D.popAtStack(a[i]);
            }
        }
    }

    cout<<"display :"<<endl;

    D.display();

    return 0;
}