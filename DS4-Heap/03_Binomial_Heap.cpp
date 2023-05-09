//g4g - Implementation of Binomial Heap(https://www.geeksforgeeks.org/implementation-binomial-heap/)
//YT - Uzair Javed Akhtar - Binomial Tree & Binomial heap

#include<bits/stdc++.h>
using namespace std;

class BinomialTreeNode{
public: 
    BinomialTreeNode* parent; // ptr to parent , null for root
    int data;
    int degree;//number of children
    BinomialTreeNode* leftmost_child;
    BinomialTreeNode* right_sibling;

    BinomialTreeNode(int data){
        this->parent = nullptr;
        this->data = data;
        this->degree = 0;
        this->leftmost_child = nullptr;
        this->right_sibling = nullptr;
    }

    //~BinomialTreeNode(){ cout<<"deleting node "<<this->data<<endl;};// a destructor
    /*
    ~BinomialTreeNode(){} is a destructor for the Node class. It's used to perform cleanup operations when a Node object is destroyed, such as 
    releasing any dynamically allocated memory associated with the object.

    In this case, the destructor is empty, which means it doesn't do anything. This is because the Node class doesn't have any 
    dynamically allocated memory that needs to be released explicitly. However, if you had added any dynamic memory allocation 
    in the Node class, you would need to free it in the destructor to prevent memory leaks.
    */
};

class list_node{
public:
    BinomialTreeNode* treeNode;
    list_node* next;

    list_node(BinomialTreeNode* treeNode){
        this->treeNode = treeNode;
        this->next = nullptr;
    }


private:
    //~list_node(){ cout<<"listnode destructor called"<<endl;};//destructor
};

class linked_list{
public:
    list_node* root;
    int size;
    //int capacity;

    linked_list(){
        root = nullptr;
        size = 0;
    }

    void push_back(BinomialTreeNode* newNode){
        if(root == nullptr){
            root = new list_node(newNode);
            root->next = nullptr;
            size++;
            return;
        }

        list_node* newListNode = new list_node(newNode);

        list_node* curr = root;

        while(curr->next != nullptr){
            curr = curr->next;
        }
        curr->next = newListNode;
        size++;
    }

    void push_front(BinomialTreeNode* newNode){

        if(root == nullptr){
            root = new list_node(newNode);
            root->next = nullptr;
            size++;
            return;
        }

        list_node* new_node = new list_node(newNode);
        
        new_node->next = this->root;
        this->root = new_node;
        size++;
    }


    bool isEmpty(){
        if(size==0)return true;
        else return false;
    }

    list_node* erase(list_node* target){
        if(root==target){
            list_node* temp = root;
            root = root->next;
            free(temp);
            size--;
            return root;
        }

        list_node* curr = root;

        while(curr->next != target){
            curr = curr->next;
        }

        list_node* temp = curr->next;
        curr->next = temp->next;
        free(temp);
        size--;
        return curr->next;//this is controversial
        //return curr;
    }


};


class BinomialHeap{
    linked_list heap;

public: 

    BinomialHeap(){
        heap = linked_list();
    }

    bool is_empty(){
        return heap.isEmpty();
    }

private:
    linked_list UniteBinomialHeaps(linked_list heap1, linked_list heap2){
        linked_list newHeap = linked_list();
        list_node* i = heap1.root;
        list_node* j = heap2.root;

        while(i!=nullptr and j!=nullptr){
            if(i->treeNode->degree <= j->treeNode->degree){
                newHeap.push_back(i->treeNode);
                i = i->next;
            }
            else{
                newHeap.push_back(j->treeNode);
                j = j->next;
            }
        }

        while(i != nullptr){
            newHeap.push_back(i->treeNode);
            i = i->next;
        }

        while(j != nullptr){
            newHeap.push_back(j->treeNode);
            j = j->next;
        }
        return newHeap;
    }


    BinomialTreeNode* MergeBinomialTrees(BinomialTreeNode* a, BinomialTreeNode* b){
        //a,b are tree root of two trees 
        if(a->data > b->data){
            BinomialTreeNode* t = a;
            a = b;
            b = t;
        }

        b->right_sibling = a->leftmost_child;
        b->parent = a;
        a->leftmost_child = b;
        a->degree++;

        return a;
    }



    linked_list adjust(linked_list xHeap){

        if(xHeap.size <= 1){
            return xHeap;
        }

        list_node *i,*j,*k;
        i = j = k = xHeap.root;

        if(xHeap.size==2){
            j = i->next;
            k = nullptr;
        }
        else{
            j = i->next;
            k = j->next;
        }

        while( i != nullptr){

            if(j==nullptr){
                i = i->next;
                cout<<"a"<<endl;
            }

            else if( i->treeNode->degree < j->treeNode->degree){

                i = i->next;
                j = j->next;
                cout<<"b"<<endl;

                if(k != nullptr)k = k->next;
            }

            else if(k != nullptr and 
                    i->treeNode->degree == j->treeNode->degree and
                    i->treeNode->degree == k->treeNode->degree){

                    i = i->next;
                    j = j->next;
                    k = k->next;
                    cout<<"c"<<endl;
            }

            else if(i->treeNode->degree == j->treeNode->degree){
                BinomialTreeNode* temp;

                i->treeNode = MergeBinomialTrees(i->treeNode,j->treeNode);
                j = xHeap.erase(j);
                cout<<"d"<<endl;
                if(k != nullptr) k = k->next;
            }
        }

        return xHeap;
    }

    
    linked_list InsertATreeInHeap(BinomialTreeNode* temp){

        linked_list newTree = linked_list();
        newTree.push_back(temp);

        newTree = UniteBinomialHeaps(heap,newTree);

        return adjust(newTree);
    }

public:
    void insert(int data){
        BinomialTreeNode* temptree = new BinomialTreeNode(data);
        this->heap = InsertATreeInHeap(temptree);
    }

    BinomialTreeNode* getMin(){
        if(heap.root == nullptr){
            cout<<"empty heap...nothing to give"<<endl;
            return nullptr;
        }
        list_node* curr = heap.root;
        list_node* temp = heap.root;

        while(curr != nullptr){

            if(temp->treeNode->data > curr->treeNode->data){
                temp = curr;
            }
            curr = curr->next;
        }
        return temp->treeNode;
    }

private:

    linked_list removeMinFromATreeToMakeANewHeap(BinomialTreeNode* tree_node){
        BinomialTreeNode* traversing_node = tree_node->leftmost_child;
        BinomialTreeNode* temp ;

        linked_list new_heap = linked_list();

        while(traversing_node != nullptr){
            temp = traversing_node;
            traversing_node =  traversing_node->right_sibling; 
            temp->right_sibling = nullptr;
            cout<<temp->data<<endl;
            new_heap.push_front(temp);
        }

        return new_heap;
    }

    linked_list extractMinHelper(linked_list xHeap){

        BinomialTreeNode* temp = getMin();
        list_node* curr = xHeap.root;
        linked_list yHeap,zHeap;

        while(curr != nullptr){

            if(curr->treeNode != temp){
                yHeap.push_back(curr->treeNode);
            }

            curr = curr->next;
        }


        zHeap = removeMinFromATreeToMakeANewHeap(temp);
        yHeap = UniteBinomialHeaps(zHeap,yHeap);
        yHeap = adjust(yHeap);

        return yHeap;
    }

public:

    void extractMin(){
        this->heap = extractMinHelper(this->heap);
    }



private:
    void printTree(BinomialTreeNode* node){

        while(node != nullptr){
            cout<<node->data<<" ";
            printTree(node->leftmost_child);
            node = node->right_sibling;
        }
    }

public:
    void printHeap(){
        list_node* i = heap.root;

        while(i != nullptr){
            printTree(i->treeNode);
            cout<<endl;
            i = i->next;
        }
    }

};

int main(){

    BinomialHeap h = BinomialHeap();

    h.insert(10);
    h.insert(20);
    h.insert(30);

    BinomialTreeNode* a = h.getMin();
    cout<<endl<<a->data<<endl<<endl;

    h.extractMin();


    cout<<endl;

    h.printHeap();

return 0;
}