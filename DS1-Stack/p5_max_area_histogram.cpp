/*
Problem Link  : Aditya Verma - 7 Maximum Area Histogram | MAH(https://youtu.be/J2X70jj_I1o)
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


vector<int> NSR(int a[], int n){
    Stack s,index;
    vector<int>right;
    

    for(int i=n-1;i>=0;i--){

        if(s.Empty()==true){
            right.push_back(n);
            s.push(a[i]);
            index.push(i);
        }
        else if(s.Empty()==false && a[i]>s.top()){
            right.push_back(index.top());
            s.push(a[i]);
            index.push(i);
        }
        else if(s.Empty()==false && a[i]<=s.top()){

            while(s.Empty()==false && a[i]<=s.top()){
                s.pop();
                index.pop();
            }

            if(s.Empty()){
                right.push_back(n);
            }
            else{
                right.push_back(index.top());
            }

            s.push(a[i]);
            index.push(i);
        }
    }

    vector<int>right_reverse;

    for(int i=n-1;i>-1;i--){
        right_reverse.push_back(right[i]);
    }

    return right_reverse;
}


vector<int> NSL(int a[], int n){
    Stack s,index;
    vector<int>left;
    

    for(int i=0;i<n;i++){

        if(s.Empty()==true){
            left.push_back(-1);
            s.push(a[i]);
            index.push(i);
        }
        else if(s.Empty()==false && a[i]>s.top()){
            left.push_back(index.top());
            s.push(a[i]);
            index.push(i);
        }
        else if(s.Empty()==false && a[i]<=s.top()){

            while(s.Empty()==false && a[i]<=s.top()){
                s.pop();
                index.pop();
            }

            if(s.Empty()){
                left.push_back(-1);
            }
            else{
                left.push_back(index.top());
            }

            s.push(a[i]);
            index.push(i);
        }
    }

    return left;
}



int main(){
    
    int n;

    cin>>n;

    int a[n];

    int i,j;

    for(i=0;i<n;i++)cin>>a[i];

    vector<int> right = NSR(a,n);

    for(i=0;i<n;i++){
        cout<<right[i]<<" ";
    }

    cout<<endl;
    vector<int> left = NSL(a,n);

    for(i=0;i<n;i++){
        cout<<left[i]<<" ";
    }

    cout<<endl;

    vector<int>ans;

    for(i=0;i<n;i++){
        ans.push_back(right[i]-left[i]-1);
    }

    int max_area = -1,index = -1;
    for(i=0;i<n;i++){
        cout<<ans[i]<<" ";

        if((a[i]*ans[i])>max_area){
            max_area = a[i]*ans[i];
            index = i;
        }
    }

    cout<<endl<<"index = "<<index<<" max_area = "<<max_area<<endl;

    
    
    return 0;
}


