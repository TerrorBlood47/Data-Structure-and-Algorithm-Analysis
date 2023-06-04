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


int prec(char c){
    if(c=='^'){
        return 3;
    }
    else if(c=='*' || c=='/'){
        return 2;
    }
    else if(c=='+' || c=='-'){
        return 1;
    }
    else{
        return -1;
    }
}

string infixToPostfix(string s){

    Stack stack;
    string result;

    for(int i=0 ; i<s.length() ; i++){

        char c = s[i];

        if((c>='a' && c<='z') || (c>='A' && c<='Z') || (c>='0' && c<='9')){
            result += c;
        }
        else if(c=='('){
            stack.push(c);
        }
        else if(c==')'){

            while(stack.top()!='('){
                result += stack.top();
                stack.pop();
            }
            stack.pop();
        }
        //for operators
        else{
            if(c=='^' && stack.top()=='^'){
                stack.push(c);
            }
            else{
                if( prec(c) <= prec(stack.top())){ //Pop all the operators from the stack which are greater than or equal to 
                                                    //in precedence than that of the scanned operator. After doing that Push the scanned operator to the stack. 
                    while(stack.empty()==false && prec(c) <= prec(stack.top())){  //(If you encounter parenthesis while popping then stop there and push the scanned operator in the stack.) 
                        result += stack.top();
                        stack.pop();
                    }
                    stack.push(c);
                }
                else{
                    stack.push(c);
                }
            }
        }
    }


    while(stack.empty()==false){
        result += stack.top();
        stack.pop();
    }

    return result;
}



string InfixToPrefix(string a){

    string s ="";

    for(int i = a.length()-1; i>=0 ;i--){
        if(a[i]=='('){
            s += ')';
        }
        else if(a[i]==')'){
            s += '(';
        }
        else{
            s += a[i];
        }
    }



// nearly infixToPostfix function
    Stack stack;
    string result;

    for(int i=0 ; i<s.length() ; i++){

        char c = s[i];

        if((c>='a' && c<='z') || (c>='A' && c<='Z') || (c>='0' && c<='9')){
            result += c;
        }
        else if(c=='('){
            stack.push(c);
        }
        else if(c==')'){

            while(stack.top()!='('){
                result += stack.top();
                stack.pop();
            }
            stack.pop();
        }
        //for operators
        else{
            if(c=='^' ){
                while(stack.empty()==false && prec(c) <= prec(stack.top())){  //changes here
                    result += stack.top();
                    stack.pop();
                }
                stack.push(c);
            }
            else{
                if( prec(c) < prec(stack.top())){
                    while(stack.empty()==false && prec(c) < prec(stack.top())){  //changes here
                        result += stack.top();
                        stack.pop();
                    }
                    stack.push(c);
                }
                else{
                    stack.push(c);
                }
            }
        }
    }
    while(stack.empty()==false){
        result += stack.top();
        stack.pop();
    }

    string output="";
    
    for(int i = result.length()-1; i>=0 ;i--){
        output += result[i];
    }


    return output;
}



int main(){
    
    string s = "a+b*(c^d-e)^(f+g*h)-i";
    string ans = infixToPostfix(s);

    //string x = "(x+y*z/w+u)";
    //string ans = InfixToPrefix(x);
    cout<<ans<<endl;
    
    return 0;
}


