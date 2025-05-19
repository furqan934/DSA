#include<iostream>
using namespace std;
struct TreeNode{
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int value){
        data = value;
        left , right = nullptr;
    }
};
    // TreeNode* createNode(int value){
    //     TreeNode* Node = new TreeNode(value);
    //     return Node;
    // }


    void insertion(TreeNode*  &root,int value){
        if (root == nullptr){
            root =  new TreeNode(value);
        }
        else if(value < root -> data){
            insertion(root -> left , value);
        }
        else{
            insertion(root -> right , value);
        }
    }
    bool  searchNode(TreeNode* root,int k){
        if(root == nullptr){
            cout << "Tree is Empty\n";
            return false;
        }
        if (root -> data = k){
            cout << "value: " << k << " Present at root.\n";
            return true;
        }
        else if ( root->data > k){
            return searchNode(root -> left , k);
            cout << "value: " << k << " Present at left.\n";
        }
        else{
            return searchNode(root -> right , k);
            cout << "value: " << k << " Present at right.\n";
        }
    }
    void inOrder(TreeNode* root){
        if (root != nullptr){
        inOrder(root->left);
        cout << root->data << " ";
        inOrder(root->right);
        }
    }
    void preOrder(TreeNode* root){
        if (root != nullptr){
        cout << root->data << " ";
        preOrder(root->left);
        preOrder(root->right);
        }
    }
    void postOrder(TreeNode* root){
        if (root != nullptr){
        postOrder(root->left);
        postOrder(root->right);
        cout << root->data << " ";
        }
    }
    


int main(){
    TreeNode* root = nullptr;
    int value ;
    int k;
    for (int i = 0; i < 3 ; i ++ ){
        cout <<"enter value: ";
        cin >> value;
        insertion(root,value);
    }
    cout << "\nInorder Traversal (Sorted): ";
    inOrder(root);
    cout << "\nPreorder Traversal (Sorted): ";
    preOrder(root);
    cout << "\nPostorder Traversal (Sorted): ";
    postOrder(root);
    cout << endl;
    cout << "Enter value that you want to seaerch in tree: ";
    cin >> k;
    if (searchNode(root,k)){
        cout << "value"<< k << "is found In BST.\n";
    }
    else{
        cout << "value"<< k << "is not found In BST!\n";
    }
}