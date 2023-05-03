
//source - GeeksForGeeks - Insertion in an AVL Tree
//                        -Deletion in an AVL Tree

#include<bits/stdc++.h>
using namespace std;

class TreeNode{
public:
    int data;
    TreeNode* left; //left_child
    TreeNode* right;  // right_child
    int height;

    TreeNode(){};

    TreeNode(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
        this->height = 1;// new node is initially
                      // added at leaf
    }


    
};


int max(int a, int b){
    return (a>b)?a:b;
}

class AVL_Tree{
public: 

    TreeNode* root;

    AVL_Tree(){
        root = NULL;
    }

private: 

    int getHeight(TreeNode* node){
        if(node==nullptr){
            return 0;
        }
        return node->height;
    }



    TreeNode* rightRotate(TreeNode* y){
        TreeNode* x = y->left;
        TreeNode* T2 = x->right;

        //perform rotation
        x->right = y;
        y->left = T2;

        //update heights
        y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

        x->height = max(getHeight(x->left), getHeight(x->right)) + 1;//check

        //return new root
        return x;
    }


    TreeNode* leftRotate(TreeNode* x){
        TreeNode* y = x->right;
        TreeNode* T2 = y->left;

        y->left = x;
        x->right = T2;

        y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
        x->height = max( getHeight(x->left), getHeight(x->right)) + 1;//check

        return y;
    }


    int getBalanceFactor(TreeNode* node){
        if(node==NULL)return 0;
        return getHeight(node->left) - getHeight(node->right);
    }


    TreeNode* p_insert(TreeNode* parent, int val){
        if(parent==NULL){
            parent = new TreeNode(val);
            return parent;
        }
        if(val < parent->data){ // <= ??  // Equal keys are not allowed in BST
            parent->left = p_insert(parent->left,val);
        }
        else if(val > parent->data){
            parent->right = p_insert(parent->right,val);
        }
        else return parent;


        parent->height = 1 + max( getHeight(parent->left), getHeight(parent->right));

        int balanceFactor = getBalanceFactor(parent);

        //left-left case
        if(balanceFactor>1 and val< (parent->left->data)){
            return parent = rightRotate(parent);
        }

        //left-right case
        if(balanceFactor>1 && val > (parent->left->data)){

            parent->left = leftRotate(parent->left);
            return parent = rightRotate(parent);
        }

        //right-right case
        if(balanceFactor<-1 && val>(parent->right->data)){
            return parent = leftRotate(parent);
        }

        //right-left case
        if(balanceFactor<-1 && val < (parent->right->data)){
            parent->right = rightRotate(parent->right);
            return parent = leftRotate(parent);
        }


        return parent;

    }



    TreeNode* findMinNode(TreeNode* node){
        TreeNode* curr = node;

        while(curr && curr->left!=NULL){
            curr = curr->left ;
        }

        return curr;
    }


    TreeNode* remove(TreeNode* node, int val){
        
        if(node == NULL){
            return node;
        }

        if(val < node->data){
            node->left = remove(node->left,val);
        }
        else if(val > node->data){
            node->right = remove(node->right,val);
        }
        else{

            if(node->left==NULL && node->right==NULL){
                free(node);
                return NULL;
            }
            else if(node->left!=NULL && node->right==NULL){//node with only left child
                TreeNode* temp = node->left;
                free(node);
                return temp;
            }
            else if(node->left==NULL && node->right!=NULL){//node with only right child
                TreeNode* temp = node->right;
                free(node);
                return temp;
            }

            //nodes with two children
            TreeNode* temp = findMinNode(node->right);
            node->data = temp->data;

            node->right = remove(node->right,temp->data);

        }

        node->height = 1 + max( getHeight(node->left), getHeight(node->right));

        int balanceFactor = getBalanceFactor(node);

        //left-left case
        if(balanceFactor>1 && getBalanceFactor(node->left)>=0){
            return node = rightRotate(node);
        }

        //left-right case
        if(balanceFactor>1 && getBalanceFactor(node->left) < 0){
            node->left = leftRotate(node->left);
            return node = rightRotate(node);
        }

        //right-right case
        if(balanceFactor<-1 and getBalanceFactor(node->right) <= 0){ //check
            return node = leftRotate(node);
        }

        //right-left case
        if(balanceFactor<-1 and getBalanceFactor(node->right) > 0){
            node->right = rightRotate(node->right);
            return node = leftRotate(node);
        }

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
        root = p_insert(root,val);
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
        return p_height(root);
    }

    void printTheLevel(int level){
        printGivenLevel(root,level);
    }


};


int main(){

    AVL_Tree a = AVL_Tree();

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

    a.deleteNode(10);

    for(int i=0;i<=a.height_of_the_tree();i++){
        a.printTheLevel(i);
        cout<<endl;
    }


    return 0;
}