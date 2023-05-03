
#include<bits/stdc++.h>
using namespace std;

class TreeNode{
public:
    int data;
    int color;//1-Red, 0-Black
    TreeNode* left; //left_child
    TreeNode* right;  // right_child
    TreeNode* parent;

    TreeNode(){};

    TreeNode(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
        this->parent = nullptr;
        this->color = 1;
    }


    
};



class RedBlackTree{
public: 

    TreeNode* root;

    RedBlackTree(){
        root = NULL;
    }

private: 

    void rightRotate(TreeNode** y){

        TreeNode* x = (*y)->left;
        TreeNode* T2 = x->right;

        (*y)->right = T2;
        if(T2 != nullptr)T2->parent = *y;

        (*y)->parent = x->parent;

        if((*y)->parent == nullptr){
            root = x;
        }
        else if(*y == (*y)->parent->left){
            x = (*y)->parent->left;
        }
        else{
            x = (*y)->parent->right;
        }

        x->right = *y;
        (*y)->parent = x;
    }

    void leftRotate(TreeNode** x){
        TreeNode* y = (*x)->right;
        TreeNode* T2 = y->left;

        (*x)->right = T2;
        if(T2 != nullptr) T2->parent = *x;

        y->parent = (*x)->parent;

        if((*x)->parent==nullptr){
            root = y;
        }
        else if((*x)->parent->left == *x){
            y = (*x)->parent->left;
        }
        else{
            y = (*x)->parent->right;
        }

        y->left = *x;
        (*x)->parent = y;
    }



    TreeNode* p_insert(TreeNode* traversing_node, TreeNode* newNode){
        
        if(traversing_node == nullptr){
            return newNode;
        }

        if(newNode->data > traversing_node->data){
            traversing_node->right = p_insert(traversing_node->right,newNode);
            traversing_node->right->parent = traversing_node;
        }
        else if(newNode->data < traversing_node->data){
            traversing_node->left = p_insert(traversing_node->left,newNode);
            traversing_node->left->parent = traversing_node;
        }
        
        return traversing_node;
    }


void fixup(TreeNode* pt)
{
    TreeNode* parent_pt = NULL;
    TreeNode* grand_parent_pt = NULL;
 
    while ((pt != root) && (pt->color != 0)
           && (pt->parent->color == 1))
    {
        parent_pt = pt->parent;
        grand_parent_pt = pt->parent->parent;
 
        /*  Case : A
             Parent of pt is left child
             of Grand-parent of
           pt */
        if (parent_pt == grand_parent_pt->left)
        {
 
            TreeNode* uncle_pt = grand_parent_pt->right;
 
            /* Case : 1
                The uncle of pt is also red
                Only Recoloring required */
            if (uncle_pt != NULL && uncle_pt->color == 1)
            {
                grand_parent_pt->color = 1;
                parent_pt->color = 0;
                uncle_pt->color = 0;
                pt = grand_parent_pt;
            }
 
            else {
 
                /* Case : 2
                     pt is right child of its parent
                     Left-rotation required */
                if (pt == parent_pt->right) {
                    leftRotate(&parent_pt);
                    pt = parent_pt;
                    parent_pt = pt->parent;
                }
 
                /* Case : 3
                     pt is left child of its parent
                     Right-rotation required */
                rightRotate(&grand_parent_pt);
                int t = parent_pt->color;
                parent_pt->color = grand_parent_pt->color;
                grand_parent_pt->color = t;
                pt = parent_pt;
            }
        }
 
        /* Case : B
             Parent of pt is right
             child of Grand-parent of
           pt */
        else {
            TreeNode* uncle_pt = grand_parent_pt->left;
 
            /*  Case : 1
                The uncle of pt is also red
                Only Recoloring required */
            if ((uncle_pt != NULL) && (uncle_pt->color == 1))
            {
                grand_parent_pt->color = 1;
                parent_pt->color = 0;
                uncle_pt->color = 0;
                pt = grand_parent_pt;
            }
            else {
                /* Case : 2
                   pt is left child of its parent
                   Right-rotation required */
                if (pt == parent_pt->left) {
                    rightRotate(&parent_pt);
                    pt = parent_pt;
                    parent_pt = pt->parent;
                }
 
                /* Case : 3
                     pt is right child of its parent
                     Left-rotation required */
                leftRotate(&grand_parent_pt);
                int t = parent_pt->color;
                parent_pt->color = grand_parent_pt->color;
                grand_parent_pt->color = t;
                pt = parent_pt;
            }
        }
    }
}


    TreeNode* findMinNode(TreeNode* node){
        TreeNode* curr = node;

        while(curr && curr->left!=NULL){
            curr = curr->left ;
        }

        return curr;
    }


    TreeNode* remove(TreeNode* node, int val){
        
        return node; //to make connection
    }



    void PreOrder(TreeNode* curr_node){
        if(curr_node==NULL){
            return;
        }
        cout<<curr_node->data<<" ";
        PreOrder(curr_node->left);
        PreOrder(curr_node->right);
    }


    void InOrder(TreeNode* curr_node){

        if(curr_node==NULL){
            return;
        }
        InOrder(curr_node->left);

        cout<<curr_node->data<<" ";
        InOrder(curr_node->right);
    }


    void PostOrder(TreeNode* curr_node){
        if(curr_node==NULL){
            return;
        }
        PostOrder(curr_node->left);
        PostOrder(curr_node->right);

        cout<<curr_node->data<<" ";
    }

    int p_height(TreeNode* node){

        if(node == NULL){
            return 0;
        }

        int left_subtree_depth = p_height(node->left);
        int right_subtree_depth = p_height(node->right);

        if(left_subtree_depth >= right_subtree_depth){
            return left_subtree_depth + 1;
        }
        else{
            return right_subtree_depth + 1;
        }
    }

    void printGivenLevel(TreeNode* node, int level){
        if(node==NULL){
            return;
        }
        if(level==1){
            cout<<node->data<<" ";
            return;
        }
        else if(level > 1){
            printGivenLevel(node->left,level-1);
            printGivenLevel(node->right,level-1);
        }
    }


int node_count(TreeNode* node){

    if(node==NULL){
        return 0;
    }

    return node_count(node->left) + node_count(node->right) + 1;//check
}


TreeNode* clearBST(TreeNode* node){

    if(node==NULL){
        return NULL;
    }

    clearBST(node->left);
    clearBST(node->right);

    cout<<"\nReleased node:"<< node->data;

    TreeNode* temp = node;
    free(temp);
    node=NULL;
    return node;
}


int p_search(TreeNode* node, int val){

    if(node == NULL){ //this needs to come above all as it might be nullptr
        return -1;
    }

    if(node->data == val){
        return 1;
    }

    if(val< node->data){
        return p_search(node->left,val);
    }
    else if(val>node->data){
        return p_search(node->right,val);
    }
}


public:

    void addNode(int val){
        TreeNode* temp = new TreeNode(val);
        temp->color = 1;//always make it red at first;
/*
Without the new operator, you would create a new TreeNode object on the stack, 
which has limited memory and would be automatically deallocated when it goes out 
of scope. This would cause issues if you need to access the TreeNode object outside 
of the current scope.
*/

        root = p_insert(this->root,temp);
        fixup(temp);
        this->root->color = 0; // remember the root is always black
    }

    void deleteNode(int value){
        root = remove(root,value);
    }

    void printPreOrder(){//prints in order of the input provided - hence used to copy the tree
        PreOrder(root);
    }

    void printInOrder(){//prints nodes in non-decreasing order
        InOrder(root);
    }

    void printPostOrder(){//prints in reverse order of the input provided - hence used to delete the tree
        PostOrder(root);
    }

    int height_of_the_tree(){
        return p_height(this->root);
    }

    void printTheLevel(int level){
        printGivenLevel(this->root,level);
    }


};



int main(){

    TreeNode k = TreeNode(12);
    /*
    The object is created on the stack, and its memory will be automatically released 
    when it goes out of scope (i.e., when the main() function ends).
    */

    RedBlackTree a = RedBlackTree();

    a.addNode(9);
    a.addNode(5);
    a.addNode(10);
    a.addNode(0);
    a.addNode(6);
    a.addNode(11);
    a.addNode(-1);
    a.addNode(1);
    a.addNode(2);

    for(int i=0;i<=a.height_of_the_tree();i++){
        a.printTheLevel(i);
        cout<<endl;
    }

    cout<<endl;
    cout<<endl;

    //a.deleteNode(10);

    for(int i=0;i<=a.height_of_the_tree();i++){
        a.printTheLevel(i);
        cout<<endl;
    }

    a.printInOrder();

    cout<<a.root->color<<endl;


    return 0;
}