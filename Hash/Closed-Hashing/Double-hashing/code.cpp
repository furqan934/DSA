#include<iostream>
using namespace std;

const int TABLE_SIZE = 7;  // Size of the hash table
int hashTable[TABLE_SIZE]; // Hash table to store values

// Initialize all slots to -1 (empty)
void init() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable[i] = -1;
    }
}

// Primary hash function: h(x) = x % m
int hashFunc(int key) {
    return key % TABLE_SIZE;
}

// Secondary hash function: hD(x) = i * h(x) + 1
int secondHash(int key, int i) {
    return i * hashFunc(key) + 1;
}

// Insert using Double Hashing
void insertDoubleHashing(int key) {
    int index = hashFunc(key); // Primary hash
    int i = 1;  // Probe count (i starts from 1)
    int newIndex = index;

    while (hashTable[newIndex] != -1) {  // If the slot is occupied, probe further
        newIndex = (index + i * secondHash(key, i)) % TABLE_SIZE; // Rehashing using second hash function
        cout << "Collision at index " << newIndex << " for key " << key << endl;
        i++; // Increment probe count
        if (i > TABLE_SIZE) {  // If we have probed the whole table
            cout << "Hash table full! Couldn't insert " << key << endl;
            return;
        }
    }
    hashTable[newIndex] = key; // Insert the key at the found index
    cout << "Inserted " << key << " at index " << newIndex << endl;
}

// Display the hash table
void display() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (hashTable[i] == -1) {
            cout << i << " --> Empty" << endl;
        } else {
            cout << i << " --> " << hashTable[i] << endl;
        }
    }
    cout << endl;
}

int main() {
    init();
    // Inserting the given values into the hash table
    insertDoubleHashing(3);
    insertDoubleHashing(19);
    insertDoubleHashing(4);
    insertDoubleHashing(22);
    insertDoubleHashing(17);
    
    display();  // Display the final state of the hash table

    return 0;
}
