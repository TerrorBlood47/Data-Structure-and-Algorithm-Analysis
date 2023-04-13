
//source - GeeksForGeeks - Introduction to Binary Search Tree 

#include<bits/stdc++.h>
using namespace std;

class TreeNode{
public:
    int data;
    TreeNode* left; //left_child
    TreeNode* right;  // right_child

    TreeNode(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

class BinarySearchTree{
public: 

    TreeNode* root;

    BinarySearchTree(){
        root = NULL;
    }

private: 

    TreeNode* p_insert(TreeNode* parent, int val){
        if(parent==NULL){
            parent = new TreeNode(val);
            return parent;
        }
        if(val < parent->data){ // <= ??
            parent->left = p_insert(parent->left,val);
        }
        else{
            parent->right = p_insert(parent->right,val);
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

void printLeafNodes(TreeNode* node){

    if(node==NULL){
        return;
    }

    if(node->left==NULL && node->right==NULL){
        cout<<node->data<<" ";
        return;
    }
    else{
        printLeafNodes(node->left);
        printLeafNodes(node->right);
    }
}

void print_NonLeafNodes(TreeNode* node){
    if(node==NULL){
        return;
    }
    if(node->left!=NULL || node->right!=NULL){
        cout<<node->data<<" ";
        
        print_NonLeafNodes(node->left);
        print_NonLeafNodes(node->right);
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

bool determineFull(TreeNode* node){
    if(node==NULL){
        return true;
    }
    
    if((node->left==NULL && node->right!= NULL) or (node->left!=NULL && node->right== NULL)){
        //cout<<"node of conviction : "<<node->data<<endl;
        return false;
    }
    else{
        //cout<<" going left : "<<node->left->data<<" maybe left isn't right :"<<node->right->data<<endl;
        return determineFull(node->left) and determineFull(node->right);
    }
}



bool determineComplete(TreeNode* node, int index, int count_nodes){
    
    if(node==nullptr) return true;
    
    if(index >= count_nodes) return false;

    return determineComplete(node->left, 2*index + 1, count_nodes) 
                and determineComplete(node->right,2*index + 2, count_nodes);
}

bool determineBalanced(TreeNode* node){
    if(node==NULL){
        return true;
    }

    int left_height = p_height(node->left);
    int right_height = p_height(node->right);

    if(abs(left_height-right_height)>1){
        return false;
    }

    return determineBalanced(node->left) && determineBalanced(node->right);
}


bool determinePerfect(TreeNode* node){

    if(node==NULL) return true;

    if((node->left==NULL && node->right!= NULL) or (node->left!=NULL && node->right== NULL)){
        return false;
    }

    return determinePerfect(node->left) && determinePerfect(node->right);
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

    void print_All_Leaf_Nodes(){
        printLeafNodes(root);
    }

    void print_All_NonLeaf_Nodes(){
        print_NonLeafNodes(root);
    }

    int minValue(){
        TreeNode* curr = root;
        if(root==NULL){
            cout<<"Empty tree"<<endl;
            return INT_MIN;
        }
        while(root!=NULL && curr->left!=NULL){
            curr = curr->left;
        }
        return curr->data;
    }

    int totalNodeCount(){
        return node_count(root);
    }

    void clear(){
        root = clearBST(root);
    }

    int search(int val){
        return p_search(root,val);
    }

    bool isFull(){
        return determineFull(root);
    }

    bool isComplete(){
        int count_nodes = node_count(root);
        return determineComplete(root, 0 , count_nodes);
    }

    bool isBalanced(){
        return determineBalanced(root);
    }

    bool isPerfect(){
        return determinePerfect(root);
    }

};


int main(){

    BinarySearchTree t  = BinarySearchTree();

    t.addNode(50);
    t.addNode(30);
    t.addNode(20);
    t.addNode(40);
    t.addNode(70);
    t.addNode(60);
    t.addNode(80);
    ///t.addNode(10);
    //t.addNode(100);
    //t.addNode(25);
    //t.addNode(75);
    //t.addNode(5);

    

    // t.printPreOrder();
    // cout<<endl;
    // t.printInOrder();
    // cout<<endl;
    // t.printPostOrder();

    // cout<<endl<<"height = "<<t.height_of_the_tree()<<endl;

     int h = t.height_of_the_tree();
     cout<<h<<endl;

    // //t.deleteNode(20);
    // //t.deleteNode(50);

    // //t.clear();

    for(int i=0;i<h;i++){
        t.printTheLevel(i+1);
        cout<<endl;
    }

    //cout<<t.isFull()<<endl;

    //cout<<t.isBalanced()<<endl;

    //cout<<t.isComplete()<<endl;

    cout<<t.isPerfect()<<endl;

    return 0;
}