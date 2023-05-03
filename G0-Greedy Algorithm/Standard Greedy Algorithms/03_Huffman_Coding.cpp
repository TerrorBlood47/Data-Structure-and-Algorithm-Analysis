#include<bits/stdc++.h>
using namespace std;

class MinHeapNode{
public:
    char character;
    int frequency;
    MinHeapNode* left, *right;// left and right child

    MinHeapNode(char character, int frequency){
        this->character = character;
        this->frequency = frequency;
        this->left = this->right = nullptr;
    }
};

class MinHeap{
    MinHeapNode** arr;
    int size,capacity;

    int parent(int i){return (i-1)/2 ;}
    int left_child(int i){return (2*i + 1);}
    int right_child(int i){return (2*i + 2) ;}

    void swap_(MinHeapNode** a, MinHeapNode** b){
        MinHeapNode* t = *a;
        *a = *b;
        *b = t;
    }

public:
    MinHeap(int capacity){
        this->capacity = capacity;
        this->size = 0;

        arr = new MinHeapNode*[capacity];
    }

    void insert(MinHeapNode* newNode){
        int i = this->size ;
        arr[i] = newNode;

        while(i>=0 and arr[parent(i)]->frequency < arr[i]->frequency){
            arr[i] = arr[parent(i)];
            i = parent(i);
        }

        arr[i] = newNode;
        this->size++;
    }

    void MinHeapify(int i){
        
        int smallest = i;
        int left = left_child(i);
        int right = right_child(i);

        if(left<size and (arr[smallest]->frequency > arr[left]->frequency)){
            
            smallest = left;
        }
        if(right<size and (arr[left]->frequency > arr[right]->frequency)){
            smallest = right;
        }

        if(smallest==i){
            return;
        }
        else{
            swap_(&arr[smallest],&arr[i]);
            
            MinHeapify(smallest);
        }
    }

    MinHeapNode* extractMin(){
        if(size==0)return nullptr;

        MinHeapNode* temp = arr[0];
        swap(arr[0],arr[size - 1]);
        size--;

        MinHeapify(0);
        return temp;
    }

    void printArr(){
        for(int i=0; i<size; i++){
            cout<<arr[i]->character<<" "<<arr[i]->frequency<<endl;
        }
    }

    int size_(){
        return this->size;
    }

};

MinHeapNode* BuildHuffmanTree(char Char[], int freq[], int n){
    MinHeapNode *left, *right, *top;

    MinHeap* a = new MinHeap(n);

    for(int i=0; i<n; i++){
        a->insert(new MinHeapNode(Char[i],freq[i]));
    }

    while(a->size_() != 1){

        left = a->extractMin();
        right = a->extractMin();

        top = new MinHeapNode('$',left->frequency + right->frequency);

        top->left = left;
        top->right = right;
        a->insert(top);
    }

    return a->extractMin();//the whole tree is inside the first element
}

void printCodes(MinHeapNode* node, int temp[], int top){

    if(node->left != nullptr){
        temp[top] = 0;
        printCodes(node->left,temp,top + 1);
    }

    if(node->right != nullptr){
        temp[top] = 1;
        printCodes(node->right,temp, top + 1);
    }

    if(node->left==nullptr and node->right==nullptr){ //leaf node
        cout<<node->character<<" : ";
        for(int i=0; i<top ;i++){
            cout<<temp[i];
        }

        cout<<endl;
    }
}

MinHeap* HuffmanCode(char Char[], int freq[], int n){

    MinHeapNode* root = BuildHuffmanTree(Char,freq,n); //root of the huffman tree

    int temp[1000];
    int top=0;

    printCodes(root, temp, top);

}

int main(){

    int n;
    cin>>n;

    char Char[n];
    int freq[n];

    for(int i=0; i<n; i++){
        char c;
        int f;

        cin>>c>>f;

        Char[i] = c;
        freq[i] = f;
    }

    HuffmanCode(Char,freq,n);

return 0;
}