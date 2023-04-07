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

    Node *NewNode(int data)
    {
        Node *new_node = new Node();
        new_node->data = data;

        return new_node;
    }

public:

    void enque( int data)
    {

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
            return INT16_MIN;
        }

        return last->data;
    }

    int front()
    {
        if (root == NULL)
        {
            cout << "yo bitch queue is empty" << endl;
            return INT16_MIN;
        }
        return root->data;
    }

    int bottom()//same ase front
    {
        if (root == NULL)
        {
            cout << "yo bitch queue is empty" << endl;
            return INT16_MIN;
        }
        return root->data;
    }


    bool empty()
    {
        return !root;
    }

    int size()
    {
        if (root == NULL)
        {
            return 0;
        }
        Node *curr = root;
        int s = 0;
        while (curr != NULL)
        {
            s++;
            curr = curr->next;
        }
        return s;
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


};



int main()
{

    int n;
    cin>>n;

    Queue_ll q;

    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        q.enque(x);
    }

    int k;
    cin>>k;

    int i;
    for(int p=1;p<=n;p++){
        //cout<<"\n\n\np = "<<p<<endl;

        for(i=1;i<=n;i++){
            //cout<<endl<<"i = "<<i<<endl;

            if(n+1-p < i){
                //cout<<"loop breaks at i = "<<i<<endl;
                break;
            }

            //cout<<"q at start = ";
            //q.display_from_bottom();
            //cout<<endl;


                Queue_ll temp;

                int sum = 0;


                for(int j = 1; j<=p;j++){
                    sum += q.front();
                    q.enque(q.front());
                    temp.enque(q.front());
                    q.deque_f();

                    if(sum>=k){
                        temp.display_from_bottom();
                        return 0;
                    }

                }

                for(int j=1;j<=n-1;j++){
                    q.enque(q.front());
                    q.deque_f();
                }
            
                //cout<<"q = ";
                //q.display_from_bottom();
            
            }

            for(int j=1;j<=p-1;j++){
                q.enque(q.front());
                q.deque_f();
            }

        }



        cout<<"impossible"<<endl;


    
    return 0;
}

