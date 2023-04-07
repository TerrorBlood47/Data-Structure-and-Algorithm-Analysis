#include<bits/stdc++.h>
using namespace std;

class Stack{
    int tops = -1;
    int max_size = 5;

public:
    char* stk = (char*)calloc(max_size,sizeof(char));
    

    void push(char x){

        if(tops+1==max_size){
            //cout<<"new memory allocated"<<endl;
            stk = (char*)realloc(stk,max_size+5);
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
        // if(tops==-1){
        //     cout<<"Empty Stack"<<endl;
        //     return;
        // }

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


    bool empty(){
        if(tops==-1){
            return true;
        }
        return false;
    }


    void clear(){
        while(tops != -1){
            free(stk + tops*sizeof(char));
            tops--;
        }
        cout<<"memory freed"<<endl;

    }

/*
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

*/

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



string prefixToInfix(string s){

    int n = s.length();
    Stack st;
    for(int i=n-1;i>=0;i--){
        char c = s[i];

        if((c>='a' && c<='z') || (c>='A' && c<='Z') || (c>='0' && c<='9')){
            st.push(c);
        }
        else{
            char a = st.top();
            st.pop();
            char b = st.top();
            st.pop();

            st.push(')');
            st.push(b);
            st.push(c);
            st.push(a);
            st.push('(');
        }
    }

    string result;

    while(st.empty()==false){
        result += st.top();
        st.pop();
    }

    return result;

}


int main(){
    
    string s = "*-A/BC-/AKL";

    string ans = prefixToInfix(s);

    cout<<ans<<endl;
    
    return 0;
}


