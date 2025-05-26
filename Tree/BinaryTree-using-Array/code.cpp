#include <iostream>
using namespace std;

const int MAX_SIZE = 100;  // Maximum size of tree
int tree[MAX_SIZE];        // Array to hold the tree
int n= 0;              // Current number of elements

void insert(int value) {
    if (n >= MAX_SIZE) {
        cout << "Tree is full!\n";
        return;
    }
    tree[n] = value;
    n++;
}

void display() {
    cout << "Tree elements in array form:\n";
    for (int i = 0; i < n; i++) {
        cout << "Index " << i << ": " << tree[i] << endl;
    }
}

void printInOrder(int index) {
    if (index >= n) return;
    printInOrder(2 * index + 1);         // Left child
    cout << tree[index] << " ";
    printInOrder(2 * index + 2);         // Right child
}

void printPreOrder(int index) {
    if (index >= n) return;
    cout << tree[index] << " ";
    printPreOrder(2 * index + 1);
    printPreOrder(2 * index + 2);
}

void printPostOrder(int index) {
    if (index >= n) return;
    printPostOrder(2 * index + 1);
    printPostOrder(2 * index + 2);
    cout << tree[index] << " ";
}

int main() {
    // Sample insertions
    insert(1);  // root
    insert(2);  // left child of 1
    insert(3);  // right child of 1
    insert(4);  // left child of 2
    insert(5);  // right child of 2
    insert(6);  // left child of 3

    display();

    cout << "\nInOrder Traversal: ";
    printInOrder(0);

    cout << "\nPreOrder Traversal: ";
    printPreOrder(0);

    cout << "\nPostOrder Traversal: ";
    printPostOrder(0);

    return 0;
}
