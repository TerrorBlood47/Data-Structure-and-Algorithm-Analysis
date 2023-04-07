/*
Problem Link  : Aditya Verma - 6 Stock Span Problem(https://youtu.be/p9T-fE1g1pU)
About Problem : Stack implementation
Tags          : 
Notes         : -> This problem could be solved using O(n^2) brute force technique and array, but that is not the intention here
                -> identical to NGR problem
 */



#include<bits/stdc++.h>
using namespace std;

class Stack{
    int tops = -1;
    int max_size = 5;

public:
    int* stk = (int*)calloc(max_size,sizeof(int));
    
    void push(int x){

        if(tops+1==max_size){
            
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
        // if(tops==-1){
        //     cout<<"Empty Stack"<<endl;
        //     return INT_MIN;
        // }
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


Stack stock_span(int a[], int n){
    Stack s,v,index,ans;

    for(int i=0;i<=n-1;i++){
        

        if(s.Empty()==true){
            s.push(a[i]);
            v.push(-1);
            index.push(i);
        }
        else if(s.Empty()==false && a[i]<s.top()){
            v.push(index.top());
            s.push(a[i]);
            index.push(i);
        }
        else if(s.Empty()==false && s.top()<=a[i]){

            while(s.Empty()==false && s.top()<=a[i]){
                s.pop();
                index.pop();
            }
            if(s.Empty()==true){
                v.push(-1);
            }
            else{
                v.push(index.top());
            }
            s.push(a[i]);
            index.push(i);
        }
    }

    //v.display_from_bottom();

    int j = n-1;

    while(j>-1 && v.Empty()==false){
        int temp = j - v.top();
        //cout<<temp<<endl;
        ans.push(temp);
        v.pop();
        j--;
    }
    
    //ans.display_from_top();

    return ans;
}


int main(){
    
    int n;

    cin>>n;

    int a[n];

    int i,j;

    for(i=0;i<n;i++)cin>>a[i];

    Stack ans = stock_span(a,n);

    ans.display_from_top();
    
    return 0;
}


