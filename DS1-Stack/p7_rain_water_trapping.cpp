/*
Problem Link  : Aditya Verma - 7 Maximum Area Histogram | MAH(https://youtu.be/J2X70jj_I1o)
About Problem : Stack implementation
Tags          : 
Notes         : 
                
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

vector<int> max_left(int height[], int n){
    vector<int>l;
    Stack max_so_far;

    l.push_back(height[0]);
    max_so_far.push(height[0]);

    for(int i=1;i<n;i++){
        if(max_so_far.top() > height[i]){
            l.push_back(max_so_far.top());
        }
        else{
            l.push_back(height[i]);
            max_so_far.push(height[i]);
        }
    }

    return l;
}

vector<int> max_right(int height[], int n){
    vector<int>r;
    Stack max_so_far;

    r.push_back(height[n-1]);
    max_so_far.push(height[n-1]);

    for(int i=n-2;i>=0;i--){
        if(max_so_far.top() > height[i]){
            r.push_back(max_so_far.top());
        }
        else{
            r.push_back(height[i]);
            max_so_far.push(height[i]);
        }
    }

    vector<int>ri;

    for(int i=n-1;i>=0;i--){
        ri.push_back(r[i]);
    }

    return ri;
}

int total_rain_water_trapped(int height[], int n){
    vector<int>maxleft = max_left(height,n);
    vector<int>maxright = max_right(height,n);

    for(int i=0;i<n;i++)cout<<maxleft[i]<<" ";

    cout<<endl;

    for(int i=0;i<n;i++)cout<<maxright[i]<<" ";

    cout<<endl;


    vector<int>water;

    for(int i=0;i<n;i++){
        int min_ = min(maxleft[i],maxright[i]);

        water.push_back(min_ - height[i]); //width = 1
    }
    int total_area = 0;
    for(int i=0;i<n;i++){
        cout<<water[i]<<" ";
        total_area += water[i];
    }

    cout<<endl;

    return total_area;

}


int main(){
    
    int n;

    cin>>n;

    int height[n];

    for(int i=0;i<n;i++)cin>>height[i];

    int ans = total_rain_water_trapped(height,n);

    cout<<ans<<endl;
    
    return 0;
}


