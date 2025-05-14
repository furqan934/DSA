#include<iostream>
using namespace std ;
const int TABLE_SIZE = 7;
int hashTable[TABLE_SIZE];

void init(){
    for (int i = 0; i < TABLE_SIZE; i ++){
        hashTable[i] = -1;
    }
}
int hashFunc(int key){
    return key % TABLE_SIZE;
}
void  insertLinear(int key ){
    int index = hashFunc(key);
    int start = index;
    while (hashTable[index] != -1){
        cout << "Collision occurred at index " << index << " for key " << key << endl;
        index = (index + 1) % TABLE_SIZE;
        cout << "Checking next index: " << index << endl;

        if (index == start){
            cout << "hash table is full!\n";
            return;
        }
    }
    hashTable[index] = key;
        cout << "Inserted " << key << " at index " << index << endl;

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
    insertLinear(3);
    insertLinear(19);
    insertLinear(22);
    insertLinear(4);
    display();
    insertLinear(17);
    display();
}