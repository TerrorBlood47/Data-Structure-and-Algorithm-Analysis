//jamal's implementation

#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MULTIPLE_TEST int t;cin>>t;while(t--)

//local array size = 1e5, global = 1e8
//int = 1e9, long long = 1e18
// 1 sec = 1e7 ~ 1e8

const int N = 1e7+10;

class Object{
public:
    string name;
    int key;
    int roll;

    Object(){
        this->name = "";
        this->key = 0;
        this->roll = 0;
    }

    Object(string name, int key, int roll){
        this->name = name;
        this->key =key;
        this->roll = roll;
    }

};

class Node{
public:
    Object value;

    Node* left;
    Node* right;
    
    Node(Object value, Node* left=nullptr, Node* right=nullptr){
        this->value = value;
        this->left = left;
        this->right = right;
    }

};

int compare(Object a, Object b){
    if(a.key<b.key) return -1;
    if(a.key>b.key) return 1;
    return 0;
}


class BST{
public:
    Node* root;

    BST(){
        this->root=nullptr;
    }

    Node* insertNode(Node* root, Object value){
        if(root==nullptr){
            return new Node(value);
        }

        if(compare(value,root->value)<=0){
            root->left = insertNode(root->left,value);
        }
        else{
            root->right = insertNode(root->right,value);
        }

        return root;

    }

    void add(Object value){
        root = insertNode(root, value);

        inorder(root);
        cout<<'\n';
    }


    Node* deleteNode(Node* root, Object value){
        if(root==nullptr) return nullptr;

        if(compare(value,root->value)<0){
            root->left = deleteNode(root->left,value);
        }
        else if(compare(value,root->value)>0){
            root->right = deleteNode(root->right, value);
        }

        else{
            if(root->left==nullptr and root->right==nullptr){
                root = nullptr;
                return nullptr;
            }
            if(root->left==nullptr){
                Node* temp = root;
                root = root->right;
                delete temp;
            }
            else if(root->right==nullptr){
                Node* temp = root;
                root = root->left;
                delete temp;
            }

            else{
                Node* min = findMin(root->right);

                root->value = min->value;

                root->right = deleteNode(root->right,min->value);
            }
        }
        return root;

    }

    Node* findMin(Node* node){
        while(node->left!=nullptr){
            node = node->left;
        }
        return node;
    }

    void remove(Object value){
        root = deleteNode(root,value);

        inorder(root);
        cout<<'\n';
    }



   Node* find(Node* node, Object value, int& level){
        if(node==nullptr){
            level=-1;
            return nullptr;
        }

        if(compare(node->value,value)==0) return node;
        level++;
        if(compare(value,node->value)<0)return find(node->left,value,level);
        return find(node->right,value,level);
    }

    int search(Object value){
        int level=0;
        find(root,value,level);
        return level;
    }

    void preorder(Node* node){
        if(node == nullptr) return;

        cout<<node->value.key<<"->";
        preorder(node->left);
        preorder(node->right);
    }

    void inorder(Node* node){
        if(node == nullptr) return;

        inorder(node->left);
        cout<<node->value.key<<"->";
        inorder(node->right);
    }

    void postorder(Node* node){
        if(node == nullptr) return;

        postorder(node->left);
        postorder(node->right);
        cout<<node->value.key<<"->";
    }

    int checkBalanced(Node* root){
        if(root==nullptr) return 0;

        int lh = checkBalanced(root->left);
        if(lh==-1) return -1;

        int rh = checkBalanced(root->right);
        if(rh==-1) return -1;

        if(abs(rh-lh)>1) return -1;

        return max(lh,rh)+1;
    }

    bool isBalanced(Node* root){
        if(checkBalanced(root)==-1) return false;
        return true;
    }

    int height(Node* root){
        if(root==nullptr) return 0;

        return 1+max(height(root->left),height(root->right));
    }

    bool isLeftSkewed(Node* root){

        int rh = height(root->right);

        return rh==0;
    }

    bool isRightSkewed(Node* root){
        int lh = height(root->left);

        return lh==0;
    }

    bool isPerfect(Node* root){
        if(root==nullptr) return true;

        if((root->left==nullptr && root->right!=nullptr)
        ||(root->left!=nullptr && root->right==nullptr)){
            return false;
        }

        return isPerfect(root->left) && isPerfect(root->right);
    }

    bool isFUll(Node* root){
        if(root==nullptr) return true;

        if(!(root->left==nullptr && root->right==nullptr)
        ||(root->left!=nullptr && root->right!=nullptr)){
            return false;
        }

        return isFUll(root->left) && isFUll(root->right);
    }

    // bool isFull(Node* root){

    // }




};

int main(){

    fastio

    BST b;
    int arr[] = {10,5,18,2,6,4,1,13,15,11};

    for (int i = 0; i < 10; i++)
    {
            b.add(Object("a",arr[i],5));
    }

   b.remove(Object("a",13,5));
    

    return 0;
}