
#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* left; //left_child
    Node* right;  // right_child

    
};


Node* newNode(int data)
{
    Node* node
        = new Node();
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return (node);
}

int getMax(Node* node){
    if(node==NULL) return INT_MIN;

    int value = node->data;
    int leftMax = getMax(node->left);
    int rightMax = getMax(node->right);

    return max(value,max(leftMax,rightMax));
}

int getMin(Node* node){
    if(node==NULL) return INT_MAX;

    int value = node->data;
    int leftMin = getMin(node->left);
    int rightMin = getMin(node->right);

    return min(value,min(leftMin,rightMin));
}

int isBST(Node* node){ ///bool is not working correctly

    if(node == NULL){
        return 1;
    }

    if(node->left!=NULL && !(node->data > getMax(node->left))){
        return 0;
    }

    if(node->right!=NULL && !(node->data < getMin(node->right))){
        return 0;
    }

    if(isBST(node->left)==false || isBST(node->right)==false){
        return 0;
    }


    return 1;
}

int main()
{
    struct Node* root = newNode(4);
    root->left = newNode(2);
    root->right = newNode(5);
    //root->right->left = newNode(7);
    root->left->left = newNode(1);
    root->left->right = newNode(3);
    // Function call
    if (isBST(root))
        printf("Is BST");
    else
        printf("Not a BST");
    return 0;
}