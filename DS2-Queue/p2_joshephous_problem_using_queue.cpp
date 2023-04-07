#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;
};


class Queue_ll{

    Node *root = NULL;
    Node *last = NULL;

    int length = 0;

    Node *NewNode(int data)
    {
        Node *new_node = new Node();
        new_node->data = data;

        return new_node;
    }

public:

    void enque( int data)
    {
        length++;
        Node *new_node = NewNode(data);

        if (root == NULL)
        {
            root = new_node;
            root->prev = NULL;
            root->next = NULL;
            last = root;
            return;
        }

        last->next = new_node;
        new_node->prev = last;
        new_node->next = NULL;
        last = new_node;
        
        return;
    }

    void deque_f()
    {

        if (root == NULL)
        {
            cout << "nothing to pop....queue is empty" << endl;
            return;
        }

        Node *temp = root;
        root = root->next;
        if (root == NULL)
        {
            last->prev = NULL;
            last->next = NULL;
            last = root = NULL;
        }
        if (root != NULL)
            (root)->prev = NULL; // check
        free(temp);
        length--;
    }

    void peek()
    {
        if (last == NULL)
        {
            cout << "yo queue is empty" << endl;
            return;
        }
        cout << last->data << endl;
    }

    int top()
    {
        if (last == NULL)
        {
            cout << "yo bitch queue is empty" << endl;
            return INT_MIN;
        }

        return last->data;
    }

    bool empty()
    {
        return !root;
    }

    int size()
    {
        return length;
    }

    void clear()
    {
        Node *curr = root;
        while (curr != NULL)
        {
            Node *temp = curr;
            curr = curr->next;
            free(temp);
        }
        //(*root)->prev = NULL; //don't do it..... when the pointer in NULL, its next and prev become meaningless
        //(*root)->next = NULL;
        last = root = NULL;
        length = 0;
    }

    int search_from_top( int data_to_search)
    {
        Node *curr = last;
        int i = 0;

        while (curr != NULL)
        {
            if (data_to_search == curr->data)
            {
                return i;
            }
            i++;
            curr = curr->prev;
        }
        cout << "not found" << endl;
        return -1;
    }

    int search_from_bottom(int data_to_search)
    {
        Node *curr = root;
        int i = 0;
        while (curr != NULL)
        {
            if (data_to_search == curr->data)
            {
                return i;
            }
            i++;
            curr = curr->next;
        }
        cout << "not found" << endl;
        return -1;
    }

    void display_from_top()
    {

        if (last == NULL)
        {
            cout << "Empty queue..nothing to print" << endl;
            return;
        }

        Node *curr = last;

        while (curr != NULL)
        {
            cout << curr->data << " ";
            curr = curr->prev;
        }
    }

    void display_from_bottom()
    {

        if (root == NULL)
        {
            cout << "Empty queue..nothing to print" << endl;
            return;
        }

        Node *curr =root;

        while (curr != NULL)
        {
            cout << curr->data << " ";
            curr = curr->next;
        }
    }


    void eraseAtPos(int pos){

        if(pos>length-1){
            cout<<"unusual request"<<endl;
            return;
        }


        if(length==0 || root==NULL){
            cout<<"empty"<<endl;
            return;
        }

        
        if(pos==0){
            Node* temp = root;
            root = root->next;
            free(temp);
            if(root!=NULL)root->prev = NULL;
            length--;

            if(length==0){
                root = last = NULL;
            }
            
            return ;
        }

        if(pos==length-1){
            Node* temp = last;
            last = last->prev;
            free(temp);
            if(last!=NULL)last->next = NULL;
            length--;
            if(length==0){
                root = last = NULL;
            }
            return;
        }

        int i=1;
        Node* curr = root->next;
        
        while(curr!=last){

            if(i==pos){
                Node* prev_node = curr->prev;
                Node* next_node = curr->next;

                prev_node->next = next_node;
                next_node ->prev = prev_node;

                // curr->prev = NULL;
                // curr->next = NULL;

                free(curr);
                length--;
                if(length==0){
                root = last = NULL;
                }
                return;
            }

            curr= curr->next;
            i++;
        }
    }


};

int josephous_position(Queue_ll q, int k){
    int i=0;
    while(q.size()!=1){
        i = (i+k)%q.size();
        q.eraseAtPos(i);
    }

    //q.display_from_bottom(); // this thing works

    return q.top();
}

int main()
{

    int n,k;

    cin>>n>>k;        

    Queue_ll q;

    for(int i=1;i<=n;i++){
        q.enque(i);
    }

    k = k-1;

    //q.display_from_bottom(); //this also works

    int ans = josephous_position(q,k);

    cout<<ans<<endl;

    //q.display_from_bottom(); ///but this does not .......why???

    return 0;
}

