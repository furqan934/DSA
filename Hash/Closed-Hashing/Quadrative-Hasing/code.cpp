#include<iostream>
using namespace std ;
const int TABLE_SIZE = 7;
int hashTable[TABLE_SIZE];

// Initialize all slots to -1 (empty)
void init(){
    for (int i = 0; i < TABLE_SIZE; i ++){
        hashTable[i] = -1;
    }
}
// Hash function: h(x) = x % TABLE_SIZE
int hashFunc(int key){
    return key % TABLE_SIZE;
}
// Insert using Quadratic Probing
void insertQuadratic(int key) {
    int index = hashFunc(key);
    int i = 0;
    int newIndex;

    while (i < TABLE_SIZE) {
        newIndex = (index + i * i) % TABLE_SIZE;
        if (hashTable[newIndex] == -1) {
            hashTable[newIndex] = key;
            cout << "Inserted " << key << " at index " << newIndex << endl;
            return;                                                                                                      
        } else {
            cout << "Collision at index " << newIndex << " for key " << key << endl;
            i++;
        }
    }

    cout << "Hash table full! Couldn't insert " << key << endl;
}

void display(){
    for (int i=0 ; i < TABLE_SIZE; i++){
        // cout << i << " --> " << (hashTable[i] == -1 ? "empty" : to_string(hashTable[i])) << endl;
        if (hashTable[i] == -1){
            cout << i << " --> Empty" << endl; 
        }
        else{
            cout << i << " --> " << hashTable[i] << endl;
        }
    }
    cout << endl;
}
int main(){
    init();
    insertQuadratic(3);
    insertQuadratic(19);
    insertQuadratic(22);
    insertQuadratic(4);
    insertQuadratic(17);
    display();

}