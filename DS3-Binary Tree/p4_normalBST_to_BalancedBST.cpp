
#include <bits/stdc++.h>
using namespace std;
 
struct Node
{
    int data;
    Node* left,  *right;
};

Node* newNode(int data)
{
    Node* node = new Node;
    node->data = data;
    node->left = node->right = NULL;
    return (node);
}











void preOrder(Node* node)
{
    if (node == NULL)
        return;
    printf("%d ", node->data);
    preOrder(node->left);
    preOrder(node->right);
}


int main()
{
    /* Constructed skewed binary tree is
                10
               /
              8
             /
            7
           /
          6
         /
        5   */
 
    Node* root = newNode(10);
    root->left = newNode(8);
    root->left->left = newNode(7);
    root->left->left->left = newNode(6);
    root->left->left->left->left = newNode(5);
 
    root = buildTree(root);
 
    printf("Preorder traversal of balanced "
            "BST is : \n");
    preOrder(root);
 
    return 0;
}