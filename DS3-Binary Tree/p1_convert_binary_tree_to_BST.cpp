//g4g

#include<bits/stdc++.h>
using namespace std;


class Node {
public:
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int data)
{
    Node* temp = new Node();
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

int count_nodes(Node* node){

    if(node==NULL) return 0;

    return count_nodes(node->left)+count_nodes(node->right) + 1;
}


void storeInorder(int* arr,  Node* node, int* i){

    if(node==NULL)return;

    storeInorder(arr,node->left,i);//no need to increment i as i is incremented inside the function

    arr[*i] = node->data;
    (*i)++;

    storeInorder(arr,node->right,i);
}



/* A helper function that copies contents of arr[]
   to Binary Tree. This function basically does Inorder
   traversal of Binary Tree and one by one copy arr[]
   elements to Binary Tree nodes */
void arrayToBST(int* arr, Node* node, int* i){
    if(node==NULL){
        return;
    }

    arrayToBST(arr,node->left,i);
    node->data = arr[*i];
    (*i)++;
    arrayToBST(arr,node->right,i);
}


void binaryTreeToBST(Node* root){
    if(root==NULL){
        return;
    }

    int n = count_nodes(root);

    int* arr = new int[n]; //this array will store the data in inorder fashion

    int i = 0;
    storeInorder(arr,root,&i);

    for(int i=0;i<n-1;i++){ // sorting the array
        for(int j=i+1;j<n;j++){

            if(arr[i]>arr[j]){
                swap(arr[i],arr[j]);
            }
        }
    }


    i = 0;
    arrayToBST(arr,root,&i);

    delete[] arr; //deleting the array dynamically

}

void printInorder(Node* root){

    if(root==NULL)return;

    cout<<root->data<<" ";

    printInorder(root->left);
    printInorder(root->right);
}



int main()
{
    Node* root = NULL;
 
    /* Constructing tree given in the above figure
        10
        / \
        30 15
      /     \
    20       5 
    
*/
    root = newNode(10);
    root->left = newNode(30);
    root->right = newNode(15);
    root->left->left = newNode(20);
    root->right->right = newNode(5);
 
    // convert Binary Tree to BST
    binaryTreeToBST(root);
 
    cout <<"Following is Inorder Traversal of the converted BST:" << endl ;
    printInorder(root);
 
    return 0;
}
  