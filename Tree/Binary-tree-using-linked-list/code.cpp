#include <iostream>
using namespace std;

// Tree node structure
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

// Manual insertion (example)
void buildSampleTree(TreeNode*& root) {
    root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
}

// Traversals
void inOrder(TreeNode* root) {
    if (root != nullptr) {
        inOrder(root->left);
        cout << root->data << " ";
        inOrder(root->right);
    }
}

void preOrder(TreeNode* root) {
    if (root != nullptr) {
        cout << root->data << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

void postOrder(TreeNode* root) {
    if (root != nullptr) {
        postOrder(root->left);
        postOrder(root->right);
        cout << root->data << " ";
    }
}

int main() {
    TreeNode* root = nullptr;

    // Build the binary tree manually
    buildSampleTree(root);

    // Show traversals
    cout << "Inorder Traversal: ";
    inOrder(root);
    cout << "\nPreorder Traversal: ";
    preOrder(root);
    cout << "\nPostorder Traversal: ";
    postOrder(root);
    cout << endl;

    return 0;
}
