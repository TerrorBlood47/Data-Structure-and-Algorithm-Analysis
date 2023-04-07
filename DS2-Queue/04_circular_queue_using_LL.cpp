#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next; //changes
    

    Node(int data){
        this->next = NULL;
        this->data = data;
    }
};


class circular_Queue_ll{

    Node *root = NULL;
    Node *last = NULL;

    // Node *NewNode(int data)
    // {
    //     Node *new_node = new Node();
    //     new_node->data = data;

    //     return new_node;
    // }

public:

    void enque( int data)
    {

        Node *new_node = new Node(data);

        if (root == NULL)
        {
            root = new_node;
            root->next = NULL;
            last = root;
            return;
        }

        last->next = new_node;
        new_node->next = NULL;
        last = new_node;
        return;
    }

    void deque_f()
    {
        if (root == NULL)
        {
            cout << "nothing to pop....CIRCULAR queue is empty" << endl;
            return;
        }

        Node *temp = root;
        root = root->next;
        if (root == NULL)
        {
            last->next = NULL;
            last = root = NULL;
        }
        free(temp);
    }

    void peek()
    {
        if (last == NULL)
        {
            cout << "yo circular queue is empty" << endl;
            return;
        }
        cout << last->data << endl;
    }

    Node *top()
    {
        if (last == NULL)
        {
            cout << "yo bitch queue is empty" << endl;
            return NULL;
        }

        return last;
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

    circular_Queue_ll q ;

    q.enque(10);
    q.enque(12);
    q.enque(13);
    q.enque(14);
    q.enque(100);

    q.deque_f();
    q.deque_f();
    q.deque_f();
    q.deque_f();
    q.deque_f();
    q.deque_f();

    q.enque(14);
    q.enque(100);

    q.display_from_bottom();

    cout<<endl<<"next"<<endl;
    circular_Queue_ll p ;

    p.enque(10);
    p.enque(12);
    p.enque(13);
    p.enque(14);
    p.enque(100);

    

    
    p.display_from_bottom();


    

    
    return 0;
}

