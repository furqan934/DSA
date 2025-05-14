#include <iostream>
using namespace std;

const int TABLE_SIZE = 7;  // Size of the hash table

// Node structure to store each element in the linked list
struct Node {
    int data;
    Node* next;
    Node (int value){
        data = value;
        next = nullptr;
    }
};

// LinkedList structure to handle collisions at each index
struct LinkedList {
    Node* head;
    
    // LinkedList() : head(nullptr) {}
    LinkedList(){
        head = nullptr;
    }

    // Insert a new node at the beginning of the list
    void insert(int key) {
        Node* newNode = new Node(key);
        newNode->next = head;
        head = newNode;
    }

    // Search for a key in the linked list
    bool search(int key) {
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->data == key) {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

    // Display the linked list
    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

// HashTable class
class HashTable {
private:
    LinkedList table[TABLE_SIZE];  // Array of LinkedLists

public:
    // Hash function: h(x) = x % TABLE_SIZE
    int hashFunc(int key) {
        return key % TABLE_SIZE;
    }

    // Insert a key into the hash table
    void insert(int key) {
        int index = hashFunc(key);
        table[index].insert(key);
        cout << "Inserted " << key << " at index " << index << endl;
    }

    // Search for a key in the hash table
    bool search(int key) {
        int index = hashFunc(key);
        cout << "At location: " << index;
        return table[index].search(key); 
    }

    // Display the hash table
    void display() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            cout << "Index " << i << ": ";
            table[i].display();
        }
    }
};

int main() {
    HashTable ht;

    // Insert some keys into the hash table
    ht.insert(3);
    ht.insert(19);
    ht.insert(22);
    ht.insert(17);
    ht.insert(26);

    // Display the hash table
    ht.display();
    
    // Search for some keys
    // if (ht.search(17)){
    //     cout << "search key 17: are found." << endl;
    // }
    // else{
    //    cout << "search key 17: are found." << endl;
    // }
    cout << "Search 17: " << (ht.search(17) ? " Found" : " Not Found") << endl;
    cout << "Search 1: " << (ht.search(1) ? " Found" : " Not Found") << endl;

    return 0;
}
