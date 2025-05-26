#include<iostream>
using namespace std;
//TreeNode structure.
struct TreeNode{
    int data;
    TreeNode* left ;
    TreeNode* right;
    TreeNode(int value ){
        data = value;
        left ,  right = nullptr;
    }
};
// insertion :
void  insertion (TreeNode* &root , int value){
    if(root == nullptr){
        root = new TreeNode(value);
    }
    else if (root->data > value )
    {
        insertion(root -> left , value);
    }
    else{
        insertion(root -> right , value);
    }
}
//function of traversin in preorder:
void preOrder(TreeNode* root){
    if(root != nullptr){
        cout << root -> data <<" ";
        preOrder(root -> left);
        preOrder(root -> right);
    }
}
//function of traversin in inorder:
void inOrder(TreeNode* root){
     if(root != nullptr){
        inOrder(root -> left);
        cout << root -> data <<" ";
        inOrder(root -> right);
    }
}

//function of traversin in postorder:
void postOrder(TreeNode* root){
     if(root != nullptr){
        inOrder(root -> left);
        inOrder(root -> right);
        cout << root -> data <<" ";
    }
}
//function of height of the tree :
int heightOfTree(TreeNode* root){
    if (root == nullptr){
        return 0;
    }
    return 1 + max(heightOfTree(root -> left) , heightOfTree(root -> right) );
}
//function of countleafnode.
int countLeafNode(TreeNode* root){
        if (root == nullptr){
        return 0;
    }
    if (root -> left == nullptr && root -> right == nullptr){
        return 1;
    }
    return countLeafNode(root -> left) + countLeafNode(root -> right);
}
//function of internalleafnode.
int countInternalNode(TreeNode* root){
    if (root == nullptr || root -> left == nullptr && root -> right == nullptr){
        return 0;
    }
    return 1 + countInternalNode(root -> left) + countInternalNode(root -> right);

}
// function for check the validity od the BST.
bool isValidBinarySearchTree(TreeNode* root, TreeNode* minNode = nullptr,TreeNode* maxNode = nullptr){
    if(root == nullptr){
        return true;
    }
    if ((minNode && root -> data <= minNode -> data ) || (maxNode && root -> data  >= maxNode -> data)){
        return false;
    }
    return isValidBinarySearchTree(root -> left ,minNode,maxNode) && isValidBinarySearchTree(root -> left ,minNode,maxNode);
}
// funtion of mirror of the tree.
void mirrorOfBinarSearchTree(TreeNode* root){
    if (root != nullptr){
        swap(root -> left, root -> right);
        mirrorOfBinarSearchTree(root ->left);
        mirrorOfBinarSearchTree(root -> right);
    }
}
// searching
bool searching(TreeNode* root,int key){
    if(root == nullptr){
        return false;
    }
    if (root -> data == key){
        cout <<"node at parent.\n";
        return true;
    }
    else if(root -> data > key){
        return searching(root -> left , key);
        cout <<"node at left child.\n";
    }
    else{
        return searching(root -> right , key);
         cout <<"node at right  child.\n";
    }
    }
// function for fin depth of three     
void printNodeAtGivenDepth(TreeNode* root, int depth){
    if(root == nullptr){
        return;
    }
    if(depth == 0){
        cout << root -> data<< " ";
        return;
    }
    printNodeAtGivenDepth(root ->  left , depth - 1);
    printNodeAtGivenDepth(root ->  right , depth - 1);
}
int main(){
    TreeNode* root = nullptr;
    int  dataSet[] = {55, 23, 78, 15, 42, 64, 90, 33, 50, 72, 88, 91, 12};
    int n = sizeof(dataSet)/sizeof(dataSet[0]);
    for ( int value: dataSet){
        insertion(root , value);
    }
    // traversas (03)
    cout <<"\nPre order Traversal: ";
    preOrder(root);
    cout <<"\nIn order Traversal: ";
    inOrder(root);
    cout <<"\nPost Order order Traversal: ";
    postOrder(root);
    //height of the tree:
    cout <<"Height of the Tree: "<< heightOfTree(root) << endl;
    //print total leaf nodes:
    cout <<"Total leaf nodes: "<< countLeafNode(root) << endl;
     //print total internal nodes:
    cout <<"Total Internal nodes: "<< countInternalNode(root) << endl;

    //checking for valid BST:
    if(isValidBinarySearchTree){
        cout << "BST is valid.\n";
    }
    else{
        cout <<"BST is invalid!\n";
    }
    int searchValue[] = {50,91,100};
    for (int val : searchValue) {
        cout << "Search " << val << ": " << (searching(root, val) ? "Found" : "Not Found") << "\n";
    }
    // cout << "Search " << 50 << ": " << (searching(root, 50) ? "Found" : "Not Found") << "\n";
    //Bonus: print at depth 3:
    cout <<"Nodes at depth 3: ";
    printNodeAtGivenDepth(root,3);
     //Mirror the tree:
    mirrorOfBinarSearchTree(root);
    cout <<"\nIn order after mirror: ";
    inOrder(root);
    cout << endl;
}