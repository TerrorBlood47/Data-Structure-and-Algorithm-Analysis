/*
Problem Link  : Aditya Verma - 2 NGR | Nearest Greater to right | Next Largest Element(https://youtu.be/NXOOYYwpbg4)
About Problem : Stack implementation
Tags          : 
Notes         : -> This problem could be solved using O(n^2) brute force technique and array, but that is not the intention here
        
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



Stack NGR(int a[], int n){

    Stack s,ans;

    for(int i=n-1;i>=0;i--){
        
        if(s.Empty()==true){
            s.push(a[i]);
            ans.push(-1); //if s is empty, then elements from the left at hand,a[i] is greater than all of the elements positioned 
            //right to it
        }
        else if(s.Empty()==false && a[i]<s.top()){
            ans.push(s.top());
            s.push(a[i]);
        }
        else{
            while(a[i]>=s.top() && s.Empty()==false){
                s.pop();
            }
            if(s.Empty()==true){
                ans.push(-1);
            }
            else {
                ans.push((s.top()));
            }
            s.push(a[i]);
        }
    }

    return ans;

}// this implementation takes O(n) time




int main(){
    
    int n;

    cin>>n;

    int a[n];

    int i,j;

    for(i=0;i<n;i++)cin>>a[i];

    Stack ans = NGR(a,n);

    ans.display_from_top();
    
    return 0;
}


